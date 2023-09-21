// Dificil, mas menos que o merge.

/*

Quicksort

Seja x um arquivo e n o número de elementos no arquivo a ser classificado.

- Escolhe-se um elemento a numa posição específica dentro do arquivo (por exemplo, a pode ser escolhido como o primeiro elemento de modo que a = x[0]).

Suponha que os elementos de x sejam particionados de modo que a seja colocado na posição j e as seguintes condições sejam observadas:
    1. Cada elemento nas posições 0 até j 1 seja menor ou igual a "a"
    2. Cada elemento nas posições j + 1 até n 1 seja maior ou igual a "a"

- Observe que, se essas duas condições forem mantidas para determinado "a" e j, "a" será iésimo menor elemento de x, de forma que a permanecerá na posição j quando o vetor estiver totalmente classificado. Se o processo anterior for repetido com os sub-arquivos x[0] até x[j-l] e x[j + 1] até x[n-l] e com quaisquer arquivos criados pelo processo em sucessivas iterações, o resultado final será um arquivo classificado.

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000000

void quick_sort(int dataset[], int inicio, int fim);
int particionar(int dataset[], int inicio, int fim);
void show(int dataset[]);
void random_number(int dataset[]);

int array[SIZE];

int main()
{
    
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);

    // Ordenar com o método Quick Sort, onde o ultimo numero será o pivo
    quick_sort(array, 0, SIZE);

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
void quick_sort(int dataset[], int inicio, int fim)
{
    int pivo;

    if (inicio < fim)
    {
        pivo = particionar(dataset, inicio, fim);
        quick_sort(dataset, inicio, (pivo - 1));
        quick_sort(dataset, (pivo + 1), fim);
    }
}

// Particionar o array
int particionar(int dataset[], int inicio, int fim)
{
    int left, right, aux;

    // Define o pivô como o último elemento
    int pivo = dataset[fim];

    // Inicializa o índice para a posição inicial
    left = inicio;

    // Percorre o array
    for (right = inicio; right < fim; right++)
    {
        // Se o elemento atual da parte direita do array, de acordo com o pivo, é menor ou igual ao pivô
        if (dataset[right] <= pivo)
        {
            // Troca os elementos de posição
            aux = dataset[right];
            dataset[right] = dataset[left];
            dataset[left] = aux;

            // Move o índice da posição onde os elementos menores ficam
            left++;
        }
    }

    // Coloca o pivô na posição correta
    aux = dataset[left];
    dataset[left] = dataset[fim];
    dataset[fim] = aux;

    // Retorna a nova posição do pivô
    return left;
}

void quickSort(int arr[], int left, int right)
{

    int i = left, j = right;

    int tmp;

    int pivot = arr[(left + right) / 2];

    /* partition */

    while (i <= j)
    {

        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {       
            j--;
        }

        if (i <= j)
        {

            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;
        }
    };

    /* recursion */

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);
}

void quicksort2(int x[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;                     /* Vetor está classificado */

    partition(x, lb, ub, &j);       /* Particiona os elementos do subvetor
                                     * de modo que um dos elementos seja alocado
                                     * em sua posição correta. A variável j é a
                                     * posição onde este elemento foi alocada
                                     */

    quicksort2(x, lb, j-1);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição lb e j-1
                                     */

    quicksort2(x, j+1, ub);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição j+1 e ub
                                     */

}


void partition(int x[], int lb, int ub, int *j){

    int a, down, up, temp;
    
    /*
     * a é o elemento cuja posição 
     * final é procurada (pivô)
     */
    a = x[lb];

    /*
     * Inicialização dos ponteiros
     */
    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            /*
             * Sobe no vetor
             */
            down++;
        }
        while(x[up] > a){
            /*
             * Desce no vetor
             */
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}