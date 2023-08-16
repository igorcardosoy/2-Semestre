#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TAM 1000000
#define TRUE 1
#define FALSE 0

void testQuick(int array[], int tamanho, double trocas[], double comparacoes[]);
void testBubble(int array[], int tamanho);
void testSelection(int array[], int tamanho);
void testInsert(int array[], int tamanho);
void testMerge(int array[], int tamanho, double trocas[], double comparacoes[]);
void copiar_array(int array[], int array1[]);
void tabelaQuick(int array1[], int array[], int array_org[], int array_pior[], double trocas[], double comparacoes[]);
void tabelaBubble(int array1[], int array[], int array_org[], int array_pior[]);
void tabelaSelection(int array1[], int array[], int array_org[], int array_pior[]);
void tabelaInsert(int array1[], int array[], int array_org[], int array_pior[]);
void tabelaMerge(int array1[], int array[], int array_org[], int array_pior[], double trocas[], double comparacoes[]);
void quicksort(int x[], int lb, int ub, double trocas[], double comparacoes[]);
void partition(int x[], int lb, int ub, int *j, double trocas[], double comparacoes[]);
void merge(int colecao[], int inicio, int fim, double trocas[], double comparacoes[]);
void intercala(int colecao[], int inicio, int fim, int meio, double trocas[], double comparacoes[]);
void bubble_sort(int colecao[], int tamanho);
void insert_sort(int colecao[], int tamanho);
void selection_sort(int colecao[], int tamanho);
void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos);
void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);
void carrega_vetor_pior_caso(int colecao[], int tamanho);
void imprime_vetor(int colecao[], int tamanho);

// Para fazer funcionar com 1M, aparentemente tem que ser utilizado variaveis globais.
int array[TAM], array1[TAM];
int array_org[TAM];
int array_pior[TAM];

int main()
{

    // int array[TAM], array1[TAM];
    // int array_org[TAM];
    // int array_pior[TAM];

    // Outra forma de declarar os arrays para funcionar é alocando memoria usando a função malloc.
    // int *array =(int*) malloc(sizeof(int)*1000000; 
    // int *array1 =(int*) malloc(sizeof(int)*1000000;
    // int *array_org =(int*) malloc(sizeof(int)*1000000;
    // int *array_pior =(int*) malloc(sizeof(int)*1000000;

    double trocas[2];
    double comparacoes[2];

    carrega_vetor_aleatorio(array, TAM, 10);
    carrega_vetor_ordenado(array_org, 1, TAM);
    carrega_vetor_pior_caso(array_pior, TAM);

    tabelaBubble(array1, array, array_org, array_pior);
    tabelaSelection(array1, array, array_org, array_pior);
    tabelaInsert(array1, array, array_org, array_pior);
    tabelaQuick(array1, array, array_org, array_pior, trocas, comparacoes);
    tabelaMerge(array1, array, array_org, array_pior, trocas, comparacoes);


    return 0;
}

// Criar tabelas
void tabelaQuick(int array1[], int array[], int array_org[], int array_pior[], double trocas[], double comparacoes[])
{
    printf("\n-----------Quick Sort-----------\n\n");

    printf("\n---------Array - Ordenado--------\n");

    copiar_array(array_org, array1);
    testQuick(array1, TAM, trocas, comparacoes);

    copiar_array(array_org, array1);
    testQuick(array1, 100000, trocas, comparacoes);

    copiar_array(array_org, array1);
    testQuick(array1, 1000, trocas, comparacoes);

    printf("\n--------Array - Aleatorio---------\n");

    copiar_array(array, array1);
    testQuick(array1, TAM, trocas, comparacoes);

    copiar_array(array, array1);
    testQuick(array1, 100000, trocas, comparacoes);

    copiar_array(array, array1);
    testQuick(array1, 1000, trocas, comparacoes);

    printf("\n---------Array - Pior Caso--------\n");

    copiar_array(array_pior, array1);
    testQuick(array1, TAM, trocas, comparacoes);

    copiar_array(array_pior, array1);
    testQuick(array1, 100000, trocas, comparacoes);

    copiar_array(array_pior, array1);
    testQuick(array1, 1000, trocas, comparacoes);
}
void tabelaBubble(int array1[], int array[], int array_org[], int array_pior[])
{
    printf("\n-----------Bubble Sort-----------\n\n");

    printf("\n---------Array - Ordenado--------\n");

    copiar_array(array_org, array1);
    testBubble(array1, TAM);

    copiar_array(array_org, array1);
    testBubble(array1, 100000);

    copiar_array(array_org, array1);
    testBubble(array1, 1000);

    printf("\n--------Array - Aleatorio---------\n");

    copiar_array(array, array1);
    testBubble(array1, TAM);

    copiar_array(array, array1);
    testBubble(array1, 100000);

    copiar_array(array, array1);
    testBubble(array1, 1000);

    printf("\n---------Array - Pior Caso--------\n");

    copiar_array(array_pior, array1);
    testBubble(array1, TAM);

    copiar_array(array_pior, array1);
    testBubble(array1, 100000);

    copiar_array(array_pior, array1);
    testBubble(array1, 1000);
}
void tabelaSelection(int array1[], int array[], int array_org[], int array_pior[])
{
    printf("\n-----------Selection Sort-----------\n\n");

    printf("\n---------Array - Ordenado--------\n");

    copiar_array(array_org, array1);
    testSelection(array1, TAM);

    copiar_array(array_org, array1);
    testSelection(array1, 100000);

    copiar_array(array_org, array1);
    testSelection(array1, 1000);

    printf("\n--------Array - Aleatorio---------\n");

    copiar_array(array, array1);
    testSelection(array1, TAM);

    copiar_array(array, array1);
    testSelection(array1, 100000);

    copiar_array(array, array1);
    testSelection(array1, 1000);

    printf("\n---------Array - Pior Caso--------\n");

    copiar_array(array_pior, array1);
    testSelection(array1, TAM);

    copiar_array(array_pior, array1);
    testSelection(array1, 100000);

    copiar_array(array_pior, array1);
    testSelection(array1, 1000);
}
void tabelaInsert(int array1[], int array[], int array_org[], int array_pior[])
{
    printf("\n-----------Insert Sort-----------\n\n");

    printf("\n---------Array - Ordenado--------\n");

    copiar_array(array_org, array1);
    testInsert(array1, TAM);

    copiar_array(array_org, array1);
    testInsert(array1, 100000);

    copiar_array(array_org, array1);
    testInsert(array1, 1000);

    printf("\n--------Array - Aleatorio---------\n");

    copiar_array(array, array1);
    testInsert(array1, TAM);

    copiar_array(array, array1);
    testInsert(array1, 100000);

    copiar_array(array, array1);
    testInsert(array1, 1000);

    printf("\n---------Array - Pior Caso--------\n");

    copiar_array(array_pior, array1);
    testInsert(array1, TAM);

    copiar_array(array_pior, array1);
    testInsert(array1, 100000);

    copiar_array(array_pior, array1);
    testInsert(array1, 1000);
}
void tabelaMerge(int array1[], int array[], int array_org[], int array_pior[], double trocas[], double comparacoes[])
{
    printf("\n-----------Merge Sort-----------\n\n");

    printf("\n---------Array - Ordenado--------\n");

    copiar_array(array_org, array1);
    testMerge(array1, TAM, trocas, comparacoes);

    copiar_array(array_org, array1);
    testMerge(array1, 100000, trocas, comparacoes);

    copiar_array(array_org, array1);
    testMerge(array1, 1000, trocas, comparacoes);

    printf("\n--------Array - Aleatorio---------\n");

    copiar_array(array, array1);
    testMerge(array1, TAM, trocas, comparacoes);

    copiar_array(array, array1);
    testMerge(array1, 100000, trocas, comparacoes);

    copiar_array(array, array1);
    testMerge(array1, 1000, trocas, comparacoes);

    printf("\n---------Array - Pior Caso--------\n");

    copiar_array(array_pior, array1);
    testMerge(array1, TAM, trocas, comparacoes);

    copiar_array(array_pior, array1);
    testMerge(array1, 100000, trocas, comparacoes);

    copiar_array(array_pior, array1);
    testMerge(array1, 1000, trocas, comparacoes);
}

// Copiar arrays
void copiar_array(int array[], int array1[])
{
    int i;

    for (i = 0; i < TAM; i++)
    {
        array1[i] = array[i];
    }
}

// Teste com contagem
void testQuick(int array[], int tamanho, double trocas[], double comparacoes[])
{
    trocas[0] = 0;
    comparacoes[0] = 0;
    double time_spent = 0.0;
    clock_t begin = clock();
    quicksort(array, 0, tamanho - 1, trocas, comparacoes);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Trocas: %.0lf ", trocas[0]);
    printf("| Comparacoes: %.0lf | ", comparacoes[0]);
    printf("%.15lf segundos (%d itens)\n", time_spent, tamanho);
}
void testBubble(int array[], int tamanho)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    bubble_sort(array, tamanho);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%.15lf segundos (%d itens)\n", time_spent, tamanho);
}
void testSelection(int array[], int tamanho)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    selection_sort(array, tamanho);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%.15lf segundos (%d itens)\n", time_spent, tamanho);
}
void testInsert(int array[], int tamanho)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    insert_sort(array, tamanho);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%.15lf segundos (%d itens)\n", time_spent, tamanho);
}
void testMerge(int array[], int tamanho, double trocas[], double comparacoes[])
{
    trocas[0] = 0;
    comparacoes[0] = 0;
    double time_spent = 0.0;
    clock_t begin = clock();
    merge(array, 0, (tamanho - 1), trocas, comparacoes);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Trocas: %.0lf ", trocas[0]);
    printf("| Comparacoes: %.0lf | ", comparacoes[0]);
    printf("%.15lf segundos (%d itens)\n", time_spent, tamanho);
}

// Metodos de sort
void quicksort(int x[], int lb, int ub, double trocas[], double comparacoes[])
{
    int j = -1;

    if (lb >= ub)
        return; /* Vetor está classificado */

    partition(x, lb, ub, &j, trocas, comparacoes); /* Particiona os elementos do subvetor
                                                    * de modo que um dos elementos seja alocado
                                                    * em sua posição correta. A variável j é a
                                                    * posição onde este elemento foi alocada
                                                    */

    quicksort(x, lb, j - 1, trocas, comparacoes); /* Classifica de forma recursiva o subvetor
                                                   * entre a posição lb e j-1
                                                   */

    quicksort(x, j + 1, ub, trocas, comparacoes); /* Classifica de forma recursiva o subvetor
                                                   * entre a posição j+1 e ub
                                                   */
}
void partition(int x[], int lb, int ub, int *j, double trocas[], double comparacoes[])
{

    int a, down, up, temp;

    /*
     * a é o elemento cuja posição
     * final é procurada (pivô)
     */
    // a = x[lb];
    // a = x[lb + rand()%(ub+1-lb)];

    // Pegando o Pivo como o do meio, para evitar problemas e funcionar certo com 1M.
    a = x[(lb + ub) / 2];

    /*
     * Inicialização dos ponteiros
     */
    up = ub;
    down = lb;
    while (down < up)
    {

        while (x[down] <= a && down < ub)
        {
    
            /*
             * Sobe no vetor
             */
            down++;
        }

        while (x[up] > a)
        {
    
            /*
             * Desce no vetor
             */
            up--;
        }

        comparacoes[0]++;
        if (down < up)
        {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
            trocas[0]++;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}
void merge(int colecao[], int inicio, int fim, double trocas[], double comparacoes[])
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        merge(colecao, inicio, meio, trocas, comparacoes);
        merge(colecao, meio + 1, fim, trocas, comparacoes);
        intercala(colecao, inicio, fim, meio, trocas, comparacoes);
    }
}
void intercala(int colecao[], int inicio, int fim, int meio, double trocas[], double comparacoes[])
{
    int pos_livre, inicio_arquivo1, inicio_arquivo2, i;

    // int arquivo_aux[tam]; Troquei isso pois com 1M não funciona.
    // Créditos ao @Eric Postpischil do StackOverflow.
    int *arquivo_aux = malloc((fim + 1) * sizeof *arquivo_aux);
    if (arquivo_aux == NULL)
    {
        puts("malloc");
        exit(1);
    }

    inicio_arquivo1 = inicio;
    inicio_arquivo2 = meio + 1;
    pos_livre = inicio;

    while (inicio_arquivo1 <= meio && inicio_arquivo2 <= fim)
    {
        comparacoes[0]++;
        if (colecao[inicio_arquivo1] <= colecao[inicio_arquivo2])
        {
            arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
            inicio_arquivo1 += 1;
            trocas[0]++;
        }
        else
        {
            arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
            inicio_arquivo2 += 1;
            trocas[0]++;
        }
        pos_livre += 1;
    }

    for (i = inicio_arquivo1; i <= meio; i++, pos_livre++)
    {
        arquivo_aux[pos_livre] = colecao[i];
    }

    for (i = inicio_arquivo2; i <= fim; i++, pos_livre++)
    {
        arquivo_aux[pos_livre] = colecao[i];
    }

    for (i = inicio; i <= fim; i++)
    {
        colecao[i] = arquivo_aux[i];
    }

    free(arquivo_aux);
}
void bubble_sort(int colecao[], int tamanho)
{
    int i, j, elemento_auxiliar;
    int trocou = TRUE;
    double trocas = 0, comparacoes = 0;

    for (i = 0; i < tamanho && trocou; i++)
    {
        trocou = FALSE;
        for (j = 0; j < tamanho - (1 + i); j++)
        {
            comparacoes++;
            if (colecao[j] > colecao[j + 1])
            {
                elemento_auxiliar = colecao[j];
                colecao[j] = colecao[j + 1];
                colecao[j + 1] = elemento_auxiliar;
                trocas++;
                trocou = TRUE;
            }
        }
    }

    printf("Trocas: %.0lf ", trocas);
    printf("| Comparacoes: %.0lf | ", comparacoes);
}
void insert_sort(int colecao[], int tamanho)
{

    int i, j, elemento_auxiliar;
    double trocas = 0, comparacoes = 0;
    for (i = 1; i < tamanho; i++)
    {

        elemento_auxiliar = colecao[i];

        comparacoes++;
        for (j = i - 1; j >= 0 && colecao[j] > elemento_auxiliar; j--)
        {
            trocas++;
            colecao[j + 1] = colecao[j];
        }

        colecao[j + 1] = elemento_auxiliar;
    }

    printf("Trocas: %.0lf ", trocas);
    printf("| Comparacoes: %.0lf | ", comparacoes);
}
void selection_sort(int colecao[], int tamanho)
{
    int i, j, pos_menor, elemento_auxiliar;
    double trocas = 0, comparacoes = 0;

    for (i = 0; i < tamanho; i++)
    {
        pos_menor = i;
        for (j = i + 1; j < tamanho; j++)
        {
            comparacoes++;
            if (colecao[j] < colecao[pos_menor])
            {
                pos_menor = j;
            }
        }

        if (pos_menor != i)
        {
            trocas++;
            elemento_auxiliar = colecao[i];
            colecao[i] = colecao[pos_menor];
            colecao[pos_menor] = elemento_auxiliar;
        }
    }

    printf("Trocas: %.0lf ", trocas);
    printf("| Comparacoes: %.0lf | ", comparacoes);
}

// Colocar listas nos vetores
void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos)
{
    int i, digitos;

    for (i = 1, digitos = 10; i < qtd_digitos; i++)
    {
        digitos *= 10;
    }

    srand((unsigned)time(NULL));
    for (i = 0; i < tamanho; i++)
    {
        colecao[i] = rand() % digitos;
    }
}
void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho)
{
    int i;
    srand((unsigned)time(NULL));
    for (colecao[0] = valor_inicial, i = 1; i < tamanho; i++)
    {
        colecao[i] = colecao[i - 1] + (rand() % 10);
    }
}
void carrega_vetor_pior_caso(int colecao[], int tamanho)
{
    int i, j;
    for (i = tamanho, j = 0; j < tamanho - 1; i--, j++)
    {
        colecao[j] = i;
    }
}

// Mostrar o vetor
void imprime_vetor(int colecao[], int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d, ", colecao[i]);
    }
    printf("\n");
}
