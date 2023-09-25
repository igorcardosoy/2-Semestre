#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct type_data *Data;

// Operação para criar nova data.
bool criarData(int, int, int, Data*);

// Operação para validar uma data.
bool ehValida(Data);

// Criar uma data a partir de uma string.
bool criarDataDeString(char*, Data*);

// Compara duas datas, retorna 0 se iguai, valor positivo se a primeira for maior que a segunda e uma valor negativo se a primeira data for menor que a segunda.
int compararData(Data, Data);

// Operação que retorna a data em string.
char* toString(Data);

