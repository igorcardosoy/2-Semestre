#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void loadArray(int *array, int size, int type);
bool isClassified(int *array, int size);

int main()
{
    int size = 10;
    int *array;
    array = malloc( sizeof(int) * size);

    loadArray(array, size, 0);
    printf("\n%s\n\n", isClassified(array, size) ? "Ordenado" : "Desordenado");

    loadArray(array, size, 1);
    printf("\n%s\n\n", isClassified(array, size) ? "Ordenado" : "Desordenado");

    free(array);

    return 0;
}


void loadArray(int *array, int size, int type){

    switch (type)
    {
    case 0:
        for (int i = 0; i < size; i++)  
        {
            array[i] = i;
        }
        break;
    case 1:
        for (int i = size-1, j = 0; i >= 0; i--, j++)  
        {
            array[i] = j;
        }
        break;

    default:
        break;
    }
    
    
}

bool isClassified(int *array, int size){

    int isArrayed = true;

    for (int i = 0; i < size-1 && isArrayed; i++)
    {
        for (int j = i+1; j < size && isArrayed; j++)
        {
            if (array[i] > array[j])
            {
                isArrayed = false;
            }
        }
    }

    return isArrayed;
    
}
