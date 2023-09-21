#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void loadArray(int arrayInt[], int size);
void insertValue(int arrayInt[], int value, int size);
void printArray(int arrayInt[], int size);
void increaseSize(int array[], int *size);

int main()
{
    int size = 10, count = 0;
    int *arrayInt, value;
    arrayInt = malloc(sizeof(int) * size);
    bool stop = false;

    while (!stop)
    {
        printf("\nDigite o valor a adicionar ao array: ");
        scanf("%d", &value);

        if (value != 0)
        {
            arrayInt[count] = value;

            if (count == size)
            {
                increaseSize(arrayInt, &size);
            }

            count++;
        }
        else
        {
            stop = true;
        }
        
        
        
    }

    printArray(arrayInt, size);
    
    free(arrayInt);
    
    return 0;
}
void increaseSize(int array[], int *size){
    *size+=1;
    array = realloc(*array, sizeof(int) * (*size));
}

void printArray(int arrayInt[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("Array [%d]: %d\n", i+1, arrayInt[i]);
    }
    
}
