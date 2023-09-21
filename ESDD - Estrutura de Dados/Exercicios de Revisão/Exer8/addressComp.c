#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1, var2;

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &var1);

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &var2);

    printf("\nA variavel com o maior endereco de memoria e %d!\n", &var1 > &var2 ? var1 : var2);
    return 0;
}
