/*

Ordenação por troca

- Esse método consiste em comparar pares consecutivos de valores e permutá-los caso esteja fora de ordem.
- O algoritmo determina uma sequencia de comparações sistemáticas que varrem o arquivo como um todo, fazendo com que a maior chave (ou menor) acabe no final do arquivo.

*/

#include <stdio.h>
#include <time.h>
#define SIZE 10000
#define TRUE 1
#define FALSE 0

void bubble_sort(int dataset[]);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);

    // Ordenar com o método Bubble Sort
    bubble_sort(array);

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
void bubble_sort(int dataset[])
{
    int i, j, swap, aux;

    i = 0;
    while (i < (SIZE - 1) && swap)
    {

        swap = FALSE;
        for (j = 0; j < (SIZE - (1 + i)); j++)
        {
            if (dataset[j] > dataset[j + 1])
            {
                swap = TRUE;
                aux = dataset[j + 1];
                dataset[j + 1] = dataset[j];
                dataset[j] = aux;
            }
        }

        i++;
    }
}