#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    float *array;
    array = malloc(sizeof(float) * SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEndereco de memoria da posicao [%d]: %p", i, &array[i]);
    }
    
    free(array);

    return 0;
}
