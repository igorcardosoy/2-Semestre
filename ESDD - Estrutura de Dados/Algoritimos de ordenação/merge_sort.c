//Dificil.

/*

Ordenação por intercalação

- O Mergesort consiste em dividir o arquivo pela metade do tamanho original por meio de procedimento recursivo. Essa divisão ocorre até que o arquivo fique com apenas um elemento e estes sejam ordenados e intercalados.

- Neste algoritmo é aplicada a técnica da divisão e conquista, envolvendo:
    - Dividir o problema em um certo número de subproblemas;
    - Conquistar os subproblemas solucionando-os recursivamente. Se os tamanhos dos subproblemas são suficientemente pequenos, então, solucionar os subproblemas de forma simples;
    - Combinar as soluções dos subproblemas na solução do problema original.

*/
#include <stdio.h>
#include <time.h>
#define SIZE 100000

void merge_sort(int dataset[], int esquerda, int direita);
void merge(int dataset[], int l, int m, int r);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);

    // Ordenar com o método Merge Sort
    merge_sort(array, 0, SIZE);

    // Mostrar o Array
    show(array);

    return 0;
}

void show(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}
void random_number(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = rand();
    }
}
void merge_sort(int dataset[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Encontrar o elemento do meio
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(dataset, inicio, meio);
        merge_sort(dataset, (meio + 1), fim);

        merge(dataset, inicio, meio, fim);
    }
}
void merge(int dataset[], int inicio, int meio, int fim)
{
    int i, j, count;

    int size_left = meio - inicio + 1;
    int size_right = fim - meio;

    //Arrays temporarios
    int esquerda[size_left], direita[size_right];

    //Copia os dados do array principal para os temporarios, como pilhas de papeis se separando
    for (i = 0; i < size_left; i++)
    {
        esquerda[i] = dataset[inicio + i];
    }
    for (j = 0; j < size_right; j++)
    {
        direita[j] = dataset[meio + 1 + j];
    }

    // Juntar (merge) os arrays temporarios no principal.
    i = 0;
    j = 0;
    count = inicio;
    
    while (i < size_left && j < size_right)
    {
        if (esquerda[i] <= direita[j])
        {
            dataset[count] = esquerda[i];
            i++;
        }
        else
        {
            dataset[count] = direita[j];
            j++;
        }
        count++;
    }

    while (i < size_left)
    {
        dataset[count] = esquerda[i];
        i++;
        count++;
    }

    while (j < size_right)
    {
        dataset[count] = direita[j];
        j++;
        count++;
    }
}
