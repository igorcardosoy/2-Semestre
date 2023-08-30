/*
1. Elabore um sistema que leia os valores de uma equação do 2º grau (a, b e c) e apresente os possíveis resultados. O programa deve utilizar função com retorno void, de forma que os resultados sejam obtidos por passagem de parâmetro por referência. Atenção, a leitura de dados e impressão de resultados deve ser realizada na função main().
*/
#include <stdio.h>
#include <stdlib.h>

void scan(int *a, int *b, int *c);


void main()
{
    int *a, *b, *c;

    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));

    scan(a, b, c);

}

void scan(int *a, int *b, int *c)
{
    printf("Digite o valor de a: ");
    scanf("%d", a);

    printf("Digite o valor de b: ");
    scanf("%d", b);

    printf("Digite o valor de c: ");
    scanf("%d", c);
}


