#include <stdio.h>
#include <stdlib.h>

void plus(int*, int*);

int main()
{
    int a, b;

    printf("\nDigite Var1: ");
    scanf("%d", &a);

    printf("\nDigite Var2: ");
    scanf("%d", &b);

    plus(&a, &b);

    printf("\nA soma dos numeros sao: %d\n", a);
    return 0;
}

void plus(int* a, int* b){
    *a = *a + *b;
}