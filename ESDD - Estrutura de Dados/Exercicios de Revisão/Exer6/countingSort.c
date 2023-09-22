#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void random_number(int dataset[], int size);
void show(int dataset[], int size);
void countingSort(int array[], int size);
int higherFind(int array[], int size);

int main()
{
    int array[SIZE];

    random_number(array, SIZE);
    show(array, SIZE);

    printf("\n\n");

    countingSort(array, SIZE);
    show(array, SIZE);

    return 0;
}

void show(int dataset[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}

void random_number(int dataset[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        dataset[i] = rand() % 101;
    }
}

void countingSort(int *array, int size)
{
    int maior = higherFind(array, size);

    int *aux = malloc(sizeof(int) * size);
    int numberPosition[maior + 1];

    for (int i = 0; i <= maior; i++)
    {
        numberPosition[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        numberPosition[array[i]] += 1;
    }

    for (int i = 1; i <= maior; i++)
    {
        numberPosition[i] += numberPosition[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        aux[numberPosition[array[i]] - 1] = array[i];
        numberPosition[array[i]] -= 1;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = aux[i];
    }

    free(aux);
}

int higherFind(int *array, int size)
{
    int maior = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > maior)
        {
            maior = array[i];
        }
    }

    return maior;
}