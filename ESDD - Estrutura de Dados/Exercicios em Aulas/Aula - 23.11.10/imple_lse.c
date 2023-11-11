#include "lse.h"

struct node {
  // Informação que será armazenada no nó
  TypeInfo info;

  // Ponteiro para o próximo nó
  Node next;
};

struct list {
  //Ponteiro para o primeiro nó da lista
  Node head;
};


void list_init(List* list)
{
  // Aloca memória para a lista
  *list = (List) malloc(sizeof(struct list));

  // Inicializa o ponteiro para o primeiro nó
  (*list)->head = NULL;
}

List list_init2()
{
  // Aloca memória para a lista
  List list = (List) malloc(sizeof(struct list));

  // Inicializa o ponteiro para o primeiro nó
  list->head = NULL;

  return list;
}

void list_insert_begin(List list, TypeInfo new_info)
{

  if (list != NULL) {
    // Aloca memória para o novo nó
    Node new_node = (Node) malloc(sizeof(struct node));

    new_node->next = list->head;
    new_node->info = new_info;
    list->head = new_node;
  }
}

void list_insert_end(List list, TypeInfo new_info)
{
  if (list != NULL) {
    // Aloca memória para o novo nó
    Node new_node = (Node) malloc(sizeof(struct node));

    // Define os valores do novo nó
    new_node->next = NULL;
    new_node->info = new_info;

    // Verifica se a lista está vazia
    if (list->head == NULL) {
      // Lista vazia, insere o novo nó no início da lista
      list->head = new_node;
    } else {

      // Lista não esta vazia, percorre a lista até o último nó
      Node aux = list->head;
      while (aux->next != NULL) {
        aux = aux->next;
      }

      // Insere o novo nó no final da lista
      aux->next = new_node;
    }
  }
}

void list_insert_ascendent(List list, TypeInfo new_info)
{
  if (list != NULL) {
    Node new_node = (Node) malloc(sizeof(struct node));
    new_node->info = new_info;

    if (list->head == NULL) {
      new_node->next = NULL;
      list->head = new_node;
    } else {
      Node walker = list->head;
      Node stalker = NULL;

      while (walker != NULL && walker->info < new_info) {
        stalker = walker;
        walker = walker->next;
      }

      if (walker->info > new_info) {
        if (stalker == NULL) {
          // Insere no início
          new_node->next = walker;
          list->head = new_node;
        } else {
          // Insere no meio
          new_node->next = walker;
          stalker->next = new_node;
        }
      } else {
        // Insere no final
        new_node->next = NULL;
        walker->next = new_node;
      }
    }
  }
}

TypeInfo list_delete_at_list(List list, int position)
{
  TypeInfo info;

  if (list != NULL && position >= 0)
  {
    if(list->head != NULL)
    {
      Node walker = list->head;
      Node stalker = NULL;
      int count = 0;

      while (walker != NULL && count < position)
      {
        stalker = walker;
        walker = walker->next;
        count++;
      }

      if (count == position)
      {
        info = walker->info;
        if (stalker == NULL)
        {
          list->head = walker->next;
        } else {
          stalker->next = walker->next;
        }

        free(walker);
      }
    }
  }

  return info;
}

bool list_is_empty(List list)
{
  return list->head == NULL;
}

TypeInfo list_delete_begin(List list)
{
  TypeInfo info;

  if (list != NULL && list->head != NULL) {
    Node rip = list->head;
    info = list->head->info;
    list->head = list->head->next;

    free(rip);
  }

  return info;
}

TypeInfo list_delete_end(List list)
{
  TypeInfo info;

  if (list != NULL) {
    Node rip;
    Node stalker;

    rip = findLastNode(list->head);
    info = rip->info;

    stalker = list->head;

    while (stalker->next != rip) {
      stalker = stalker->next;
    }

    free(rip);

    if (stalker == NULL) {
      list->head = NULL;
    } else {
      stalker->next = NULL;
    }
  }

  return info;
}

void list_destroy(List* list)
{
  if (*list != NULL) {
    if ((*list)->head != NULL) {
      Node rip;
      Node walker;

      rip = findLastNode((*list)->head);

      free(rip);
    }

    free(*list);
    *list = NULL;
  }
}

Node findLastNode(Node node)
{
  if (node->next == NULL) {
    return node;
  } else {
    return findLastNode(node->next);
  }
}
