/*

Ordenação por seleção

O método de ORDENAÇÃO POR SELEÇÃO é considerado um dos mais simples e constitui-se na execução dos passos:
- Selecionar a menor chave do arquivo;
- Troque-a com o que está na primeira posição;
- Repita as operações anteriores para os demais elementos,até que reste apenas um.

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10000
#define TRUE 1
#define FALSE 0

void selection_sort(int dataset[]);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);

    // Ordenar com o método Selection Sort
    selection_sort(array);

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
void selection_sort(int dataset[])
{
    int smaller, aux;
    int search, i;

    for (i = 0; i < SIZE; i++)
    {
        smaller = i;
        for (search = i + 1; search < SIZE; search++)
        {
            if (dataset[search] < dataset[smaller])
            {
                smaller = search;
            }
        }

        aux = dataset[i];
        dataset[i] = dataset[smaller];
        dataset[smaller] = aux;
    }
}
