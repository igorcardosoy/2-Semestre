#include <stdio.h>
#include <stdlib.h>

int plusDouble(int* , int*);

int main()
{
    int a, b;

    printf("\nDigite Var1: ");
    scanf("%d", &a);

    printf("\nDigite Var2: ");
    scanf("%d", &b);

    printf("\nA soma do dobro eh: %d\n", plusDouble(&a, &b));
    return 0;
}

int plusDouble(int* a , int* b){
    *a *= 2;
    *b *= 2;

    return *a + *b;
}
