#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void loadArray(int arrayInt[], int size);
void insertValue(int arrayInt[], int value, int size);
void printArray(int arrayInt[], int size);
void increaseSize(int array[], int *size);

int main()
{
    int size = 5, x;
    int *arrayInt, value;
    arrayInt = malloc(sizeof(int) * size);
    bool stop = false;

    loadArray(arrayInt, size);
    printArray(arrayInt, size);

    while (!stop)
    {
        printf("\nDigite o valor a adicionar ao array: ");
        scanf("%d", &value);

        increaseSize(arrayInt, &size);
        insertValue(arrayInt, value, size);

        printArray(arrayInt, size);

        printf("\nParar? (1/0): ");
        scanf("%d", &x);

        stop = x == 1 ? true : false;

    }
    
    free(arrayInt);
    
    return 0;
}
void increaseSize(int array[], int *size){
    *size+=1;
    array = realloc(*array, sizeof(int) * (*size));
}

void loadArray(int arrayInt[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arrayInt[i] = i*2;
    }
}

void insertValue(int arrayInt[], int value, int size)
{
    bool isInserted = false;

    for (int i = 0; i < size && !isInserted; i++)
    {
        if (arrayInt[i] >= value)
        {
            for (int j = size - 2; j >= i; j--)
            {
                arrayInt[j + 1] = arrayInt[j];
            }
            arrayInt[i] = value;
            isInserted = true;
        }
    }
}

void printArray(int arrayInt[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("Array [%d]: %d\n", i, arrayInt[i]);
    }
    
}
