#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct conjuntoInt* ConjuntoInt;


// Cria um conjunto vazio;
ConjuntoInt creatSet();

//Mostra o conjunto
void printSet(ConjuntoInt);

// Destroi um conjunto, liberando a memoria
void destroySet(ConjuntoInt);

// Insere um elemento no conjunto
void insertInt(ConjuntoInt, int);

// Remove um numero do conjunto
void removeInt(ConjuntoInt, int);

// Faz a uniao de dois conjuntos e retorna um novo conjunto.
ConjuntoInt unite(ConjuntoInt, ConjuntoInt);

// Faz a interseção de dois conjuntos e retorna um novo conjunto.
ConjuntoInt intersection(ConjuntoInt, ConjuntoInt);

// Faz a diferença de dois conjuntos e retorna um novo conjunto.
ConjuntoInt difference(ConjuntoInt, ConjuntoInt);

// Verifica se um numero esta no conjunto
bool isOnSet(ConjuntoInt, int);

// Verifica se dois conjuntos são iguais
bool isEqual(ConjuntoInt, ConjuntoInt);

// Verifica se um conjunto é vazio
bool isEmpty(ConjuntoInt);

// Retorna o tamanho do conjunto
int getSize(ConjuntoInt );

