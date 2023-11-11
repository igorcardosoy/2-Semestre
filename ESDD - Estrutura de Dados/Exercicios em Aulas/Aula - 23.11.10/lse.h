#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* Node;

typedef struct list* List;

typedef int TypeInfo;


// Inicializa a lista
void list_init(List* list);

// Inicializa a lista
List list_init2();

// Insere um elemento no início da lista
void list_insert_begin(List list, TypeInfo new_info);

// Insere um elemento no final da lista
void list_insert_end(List list, TypeInfo new_info);

// Insere um elemento na lista de forma ordenada
void list_insert_ascendent(List list, TypeInfo new_info);

// Retorna se a lista está vazia
bool list_is_empty(List list);

// Deleta o primeiro elemento da lista e retorna o elemento.
TypeInfo list_delete_begin(List list);

// Deleta o elemento da lista na posição indicada e retorna o elemento.
TypeInfo list_delete_at_list(List list, int position);

// Delete o último elemento da lista e retorna o elemento.
TypeInfo list_delete_end(List list);

// Retorna o ultimo Node da lista.
Node findLastNode(Node node);

// Destroi a lista, liberando a memória de todos os nós
void list_destroy(List* list);