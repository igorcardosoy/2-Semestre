#include <stdio.h>
#include <stdlib.h>

void swap(int* , int*);

int main()
{
    int var1, var2;

    printf("\nDigite Var1: ");
    scanf("%d", &var1);

    printf("\nDigite Var2: ");
    scanf("%d", &var2);

    swap(&var1, &var2);

    printf("\nVar1: %d | Var2: %d\n", var1, var2);    
    return 0;
}

void swap(int* var1, int* var2){
    int aux;

    aux = *var1;
    *var1 = *var2;
    *var2 = aux;
}