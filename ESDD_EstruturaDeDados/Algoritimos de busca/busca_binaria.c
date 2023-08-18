// Busca binaria eficiencia de O(log n)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100000000
#define TRUE 1
#define FALSE 0

void show(int dataset[]);
void numbers(int dataset[]);
int buscaBinariaInterativa(int dataset[], int size, int key);
int buscaBinariaRecursiva(int dataset[], int left, int right, int key);

int array[SIZE];

int main()
{
    
    int key;
    srand((unsigned)time(NULL));

    // // Colocar numeros aleatórios no Array
    numbers(array);

    // Digitar a chave a ser encontrada
    scanf("%d", &key);

    // Busca binaria
    int search = buscaBinariaRecursiva(array, 0, SIZE-1, key);
    // int search = buscaBinariaInterativa(array, SIZE, key);

    if (search != -1)
    {
        printf("Chave encontrada!");
    }
    else
    {
        printf("Chave invalida!");
    }

    return 0;
}

// Mostra o array
void show(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}

// Coloca numeros no Array
void numbers(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = i+1;
    }
}

// Faz a busca pelo metodo de busca binaria
int buscaBinariaInterativa(int dataset[], int size, int key)
{
    int left = 0;
    int right = size;
    int mid, stop = FALSE;

    while (left < right && !stop)
    {
        mid = (left + right) / 2;

        if (key == dataset[mid])
        {
            stop = TRUE;
        }
        else
        {
            if (key > dataset[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
    }

    if (stop)
    {
        return mid -1;
    }
    else
    {
        return -1;
    }
    
}
int buscaBinariaRecursiva(int dataset[], int left, int right, int key)
{
    int mid;

    if (right < left)
    {
        return -1;
    }

    mid = (left + right) / 2;

    if (key == dataset[mid])
    {
        return mid;
    }

    if (dataset[mid] < key)
    {
        return buscaBinariaRecursiva(dataset, mid + 1, right, key);
    }
    else
    {
        return buscaBinariaRecursiva(dataset, left, mid - 1, key);
    }
}





