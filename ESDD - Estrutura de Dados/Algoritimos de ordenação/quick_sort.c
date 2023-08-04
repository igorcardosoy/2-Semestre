// Dificil, mas menos que o merge.
#include <stdio.h>
#include <time.h>
#define SIZE 100

void quick_sort(int dataset[], int inicio, int fim);
int particionar(int dataset[], int inicio, int fim);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);

    // Ordenar com o método Quick Sort
    quick_sort(array, 0, SIZE);

    // Mostrar o Array
    show(array);

    return 0;
}

void show(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}
void random_number(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = rand() % 1001;
    }
}
void quick_sort(int dataset[], int inicio, int fim)
{
    int pivo;

    if (inicio < fim)
    {
        pivo = particionar(dataset, inicio, fim);
        quick_sort(dataset, inicio, (pivo - 1));
        quick_sort(dataset, (pivo + 1), fim);
    }
}
int particionar(int dataset[], int inicio, int fim)
{
    int i, j, aux;
    int pivo = dataset[fim];

    i = inicio;
    for (j = inicio; j < fim; j++)
    {
        if (dataset[j] <= pivo)
        {
            aux = dataset[j];
            dataset[j] = dataset[i];
            dataset[i] = aux;

            i++;
        }
    }

    aux = dataset[i];
    dataset[i] = dataset[fim];
    dataset[fim] = aux;

    return i;
}