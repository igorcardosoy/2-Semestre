#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int busca_sequencial_ord(int dataset[], int size, int key);
void loadArray(int dataset[]);
void printArray(int dataset[]);

int main()
{
    int array[SIZE];
    int key;
    int search;

    loadArray(array);

    // Digitar a chave a ser encontrada
    printf("\nDigite o valor a ser encontrado: ");
    scanf("%d", &key);

    printf("\n%s\n\n", busca_sequencial_ord(array, SIZE, key) != -1 ? "Valor encontrado!" : "Valor nao encontrado!");

    return 0;
}

// Coloca numeros aleatórios no Array
void loadArray(int dataset[])
{
    for (int i = 0; i < SIZE; i++)
    {
        dataset[i] = i;
    }
}

int busca_sequencial_ord(int dataset[], int size, int key)
{
    int i = 0;

    while (i < size && dataset[i] < key)
    {
        i++;
    }

    return dataset[i] == key ? i : -1;
}