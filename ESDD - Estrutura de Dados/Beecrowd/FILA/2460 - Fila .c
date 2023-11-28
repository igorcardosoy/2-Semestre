#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

#define QUEUE_MAX_SIZE 50001

typedef int Element;

typedef struct queue* Queue;

void init(Queue* queue);

bool is_full(Queue queue);

bool is_empty(Queue queue);

bool enqueue(Queue queue, Element new_element);

Element dequeue(Queue queue);

typedef struct node* Node;

struct node{
    Element info;
    Node next;
};

struct queue{
    Node inicio; //HEAD
    Node fim;    //TAIL
    int size;
};

void init(Queue* queue){
    *queue = malloc(sizeof(struct queue));
    (*queue)->inicio = NULL;
    (*queue)->fim = NULL;
    (*queue)->size = 0;
}

bool is_full(Queue queue){
    return false;
}

bool is_empty(Queue queue){
    return queue->inicio == NULL;
}

bool enqueue(Queue queue, Element new_element){
    if(queue != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = new_element;
        novo->next = NULL;

        if(is_empty(queue)){
            queue->inicio = novo;
            queue->fim = novo;
        }else{
            queue->fim->next = novo;
            queue->fim = novo;
        }
        queue->size += 1;
        return true;
    }
    return false;
}

Element dequeue(Queue queue){
    Element resposta;
    if(queue != NULL){
        if(!is_empty(queue)){
            Node rip = queue->inicio;
            resposta = rip->info;
            if(rip->next == NULL){
                queue->fim = NULL;
                queue->inicio = NULL;
            }else{
                queue->inicio = rip->next;
            }
            queue->size -= 1;
            free(rip);
        }
    }
    return resposta;
}

void remove_element(Queue queue, Element el){
    Element removed;
    bool find = false;
    if(queue != NULL){
        if(!is_empty(queue)){
            Node walker = queue->inicio;
            Node stalker = NULL;

            if(walker->info == el){
                find = true;
            }

            while(walker->next != NULL && !find){
                stalker = walker;
                walker = walker->next;
                if(walker->info == el){ find = true; }
            }

            if(find){
                removed = walker->info;
                if(stalker == NULL){
                    queue->inicio = walker->next;
                }else{
                    stalker->next = walker->next;
                }
                queue->size -= 1;
                free(walker);
            }
        }
    }
}

int get_size(Queue queue){
    return queue->size;
}

int main(int argc, char const *argv[])
{
    Queue fila; 
    init(&fila);

    int num_fila;
    int num;
    Element el;

    scanf("%d", &num_fila);
    for(int i = 0; i < num_fila; i++){
        scanf("%d", &el);
        enqueue(fila, el);
    }

    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &el);
        remove_element(fila, el);
    }

    num_fila = get_size(fila);
    int i = 0;
    
    while(!is_empty(fila)){
        ++i;
        if (i == num_fila){
            printf("%d\n", dequeue(fila));
        }else{
            printf("%d ", dequeue(fila));
        }
    }

    return 0;
}