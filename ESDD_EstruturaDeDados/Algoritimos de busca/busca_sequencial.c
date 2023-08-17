// Busca sequencial eficiencia de O(n)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

void show(int dataset[]);
void random_number(int dataset[]);
int busca_sequencial_1(int dataset[], int size, int key);
int busca_sequencial_2(int dataset[], int size, int key);
int busca_sequencial_3(int dataset[], int size, int key);
int busca_sequencial_ord(int dataset[], int size, int key);


int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    srand((unsigned)time(NULL));

    // // Colocar numeros aleatórios no Array
    // random_number(array);

    show(array);

    // Digitar a chave a ser encontrada
    scanf("%d", &key);

    // Busca sequencial
    int search = busca_sequencial_ord(array, SIZE, key);

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

// Coloca numeros aleatórios no Array
void random_number(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = rand() % 51;
    }
}

// Faz a busca pelo metodo de busca sequencial
int busca_sequencial_1(int dataset[], int size, int key)
{
    int i = -1;
    int finded = -1;

    while (i < size && finded == -1)
    {
        i++;

        if (dataset[i] == key)
        {
            finded = i;
        }
    }

    if (finded != -1)
    {
        return i;
    }

    return -1;
}

int busca_sequencial_2(int dataset[], int size, int key)
{
    int i = 0;

    while (i < size && dataset[i] != key)
    {
        i++;
    }

    if (i == size)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

int busca_sequencial_3(int dataset[], int size, int key)
{
    int i = size;

    while (i >= 0 && dataset[i] != key)
    {
        i--;
    }

    return i;
}

int busca_sequencial_ord(int dataset[], int size, int key)
{
    {
    int i = 0;

    while (i < size && dataset[i] < key)
    {
        i++;
    }

    if (dataset[i] == key)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
}

