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
#include <stdlib.h>
#define SIZE 10000

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

//Metodo de ordenação recursiva
void merge_sort(int dataset[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Encontrar o elemento do meio
        int meio = inicio + (fim - inicio) / 2;

        // Metade vai para a recursividade, para chegar em problemas triviasis
        merge_sort(dataset, inicio, meio);

        // A outra metade vai para a recursividade, para chegar em problemas triviasis
        merge_sort(dataset, (meio + 1), fim);

        // Cada parte da recursividade, vai se juntando.
        merge(dataset, inicio, meio, fim);
    }
}

// Juntar os arrays.
void merge(int dataset[], int inicio, int meio, int fim)
{
    int count_left, count_right, count;

    int size_left = meio - inicio + 1;
    int size_right = fim - meio;

    //Arrays temporarios
    int left[size_left], right[size_right];

    //Copia os dados do array principal para os temporarios, como pilhas de papeis se separando

    // lado esquerdo é separado.
    for (count_left = 0; count_left < size_left; count_left++)
    {
        left[count_left] = dataset[inicio + count_left];
    }

    //Lado da direita é separado.
    for (count_right = 0; count_right < size_right; count_right++)
    {
        right[count_right] = dataset[meio + 1 + count_right];
    }

    // Juntar (merge) os arrays temporarios no principal.
    count_left = 0;
    count_right = 0;
    count = inicio;
    
    // Enquanto a contagem da esquerda for menor que o tamanho do vetor, ele continua. Mesma coisa para o lado direito.
    while (count_left < size_left && count_right < size_right)
    {
        //Se o lado esquedo for menor, o valor da esquerda é colocado no vetor original, na posição Inicio.
        if (left[count_left] <= right[count_right])
        {
            dataset[count] = left[count_left];
            count_left++;
        }
        // Se o lado direito for menor, o valor da direita é colocado no vetor original, na posição Inici
        else 
        {
            dataset[count] = right[count_right];
            count_right++;
        }
        count++;
    }

    //Caso ainda tenha numeros no array esquerdo, ele coloca no array.
    while (count_left < size_left)
    {
        dataset[count] = left[count_left];
        count_left++;
        count++;
    }

    //Caso ainda tenha numeros no array direito, ele coloca no array.
    while (count_right < size_right)
    {
        dataset[count] = right[count_right];
        count_right++;
        count++;
    }
}
