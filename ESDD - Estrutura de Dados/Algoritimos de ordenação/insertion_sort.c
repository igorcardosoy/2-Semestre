/*

Ordenação por inserção

- O método de ordenação por Inserção Direta é o mais rápido entre os outros métodos considerados básicos — Bubblesort e Seleção.

- A principal característica deste método consiste em ordenarmos o arquivo utilizando um "sub-arquivo" ordenado localizado em seu inicio, e a cada novo passo, acrescentamos a este "sub-arquivo" mais um elemento, até que atingimos o último elemento do arquivo fazendo assim com que ele se torne ordenado.

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10000
#define TRUE 1
#define FALSE 0

void insertion_sort(int dataset[]);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);
    
    // Ordenar com o método Insertion Sort
    insertion_sort(array);

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

// Coloca numeros aleatórios no Array
void random_number(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = rand() % 1001;
    }
}

//Metodo de ordenação
void insertion_sort(int dataset[])
{
    int aux;
    int i, j;

    // Começa da segunda posição, para j ser o segundo elemento.
    for (i = 1; i < SIZE; i++)
    {
        //Variavel auxiliar recebe o valor da segunda posição.
        aux = dataset[i];

        //Variavel auxiliar recebe i.
        j = i;

        // Enquanto j for maior que zero, e a posição anterior a i ser maior que a i, o algoritmo fara a troca. Sempre comparando com quem vem antes.
        // Assim, sempre encontrando a posição correta.
        while (j > 0 && (dataset[j - 1] > aux))
        {

            //Posição j recabe o valor anterior a ele, assim andando no vetor com o numero.
            dataset[j] = dataset[j - 1];

            //Decrementa a posição j, para andar no vetor.
            j--;
        }
        
        //O valor j, recebe o valor aux, no seu local correto.
        dataset[j] = aux;
    }
    
}
