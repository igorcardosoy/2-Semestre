#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 10

typedef struct type_fila* Fila;

typedef int Info;

bool init(Fila* fila);

bool enqueue(Fila fila, Info info);

Info dequeue(Fila fila);

bool is_full(Fila fila);

bool is_empty(Fila fila);