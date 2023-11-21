#include <stdio.h>
#include <stdlib.h>

#define TAM 9999

void range(int, int, int[], int*);
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
void where(int[], int, int);

int main()
{

    int array[TAM];
    int n, num, pos;

    pos = malloc(sizeof(int));

    while (scanf("%d", &n) != EOF) {
        pos = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            range(x, y, array, &pos);
        }
        merge_sort(array, 0, pos - 1);
        scanf("%d", &num);
        where(array, pos, num);
    }

    return 0;
}

void range(int x, int y, int array[], int* start)
{
    for (int i = *start; x <= y; x++, i++) {
        array[i] = x;
        *start += 1;
    }
}

void merge_sort(int colecao[], int inicio, int fim)
{
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        merge_sort(colecao, inicio, meio);
        merge_sort(colecao, meio + 1, fim);
        merge(colecao, inicio, fim, meio);
    }
}

void merge(int colecao[], int inicio, int fim, int meio)
{
    int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
    int arquivo_aux[TAM];
    inicio_arquivo1 = inicio;
    inicio_arquivo2 = meio + 1;
    pos_livre = inicio;

    while (inicio_arquivo1 <= meio && inicio_arquivo2 <= fim) {
        if (colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]) {
            arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
            inicio_arquivo1 += 1;
        } else {
            arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
            inicio_arquivo2 += 1;
        }
        pos_livre += 1;
    }

    for (i = inicio_arquivo1; i <= meio; i++, pos_livre++) {
        arquivo_aux[pos_livre] = colecao[i];
    }

    for (i = inicio_arquivo2; i <= fim; i++, pos_livre++) {
        arquivo_aux[pos_livre] = colecao[i];
    }

    for (i = inicio; i <= fim; i++) {
        colecao[i] = arquivo_aux[i];
    }
}

void where(int array[], int tamanho, int key)
{
    int qtd = 0;
    int inicio = 0;
    int fim = 0;

    for (int i = 0; i < tamanho; i++) {
        if (array[i] == key) {
            qtd++;
            if (qtd == 1) {
                inicio = i;
            } else {
                fim = i;
            }
        }
    }

    if (qtd == 1) {
        fim = inicio;
    }

    if (qtd != 0) {
        printf("%d found from %d to %d\n", key, inicio, fim);
    } else {
        printf("%d not found\n", key);
    }

}