#include <stdio.h>
#define SIZE 10

void show(int dataset[]);
void random_number(int dataset[]);


int main()
{
    int array[SIZE] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
    srand((unsigned)time(NULL));
    
    // Ordenar com o método Insertion Sort
    insert_sort(array, SIZE);

    // Mostrar o Array
    show(array);
    

    return 0;
}

// Mostra o array
void show(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}

void insert_sort(int colecao[], int tamanho){
	
	int i, j, aux, trocas = 0;

    for (i = 1; i < tamanho; i++)
    {
        aux = colecao[i];

        for (j = i-1; j >= 0 && aux < colecao[j]; j--)
        {
            trocas++;
            colecao[j+1] = colecao[j];
        }
        
        colecao[j+1] = aux;
    }
    
    printf("Total de trocas: %d\n" , trocas);

}