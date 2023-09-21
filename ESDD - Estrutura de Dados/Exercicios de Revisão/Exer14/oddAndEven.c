#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int *array, size;
    int odd = 0, even = 0;
    bool end = false;

    printf("\nDigite o tamanho do array: ");
    scanf("%d", &size);

    array = malloc(sizeof(int) * size);

    while (!end)
    {
        printf("Digite um numero: ");
        scanf("%d", array);

        *array % 2 == 0 ? even++ : odd++;

        if ((even+odd) == size)
        {
            end = true;

            for (int i = 0; i < (even+odd); i++)
            {
                array--;
            }
            
        }

        array++;
    }

    for (int i = 0; i < size; i++)
    {
        printf("\nArray[%d]: %d", i, *array);
        array++;
    }
    

    printf("\n\nPar: %d\n", even);
    printf("\nImpar: %d\n\n", odd);

    return 0;
}
