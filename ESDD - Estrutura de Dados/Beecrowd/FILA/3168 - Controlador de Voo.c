#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Queue */
#define QUEUE_MAX_SIZE 1001

typedef struct aeronave* Element;

typedef struct queue* Queue;

void init(Queue* queue);

void init_aeronave(Element* Element);

bool is_full(Queue queue);

bool is_empty(Queue queue);

int get_size(Queue queue);

bool enqueue(Queue queue, Element new_element);

Element dequeue(Queue queue);

struct queue {
    Element items[QUEUE_MAX_SIZE];
    int last, first, size;
};

struct aeronave {
    int ponto_cardeal;
    char identificador[10001];
};


void init(Queue* queue)
{
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    q->first = -1;
    q->size = 0;
    *queue = q;
}

void init_aeronave(Element* element)
{
    Element el;
    el = malloc(sizeof(struct aeronave));
    el->ponto_cardeal = 0;
    strcpy(el->identificador, "Empty");
    *element = el;
}

bool is_full(Queue queue)
{
    return queue->size == QUEUE_MAX_SIZE;
}

bool is_empty(Queue queue)
{
    return queue->size == 0;
}

int get_size(Queue queue)
{
    return queue->size;
}

bool enqueue(Queue queue, Element new_element)
{
    bool answer = false;
    if (!is_full(queue)) {
        if (queue->last == QUEUE_MAX_SIZE - 1) {
            queue->last = 0;
        } else {
            queue->last += 1;
        }
        queue->items[queue->last] = new_element;
        queue->size += 1;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue)
{
    Element answer = NULL;
    if (!is_empty(queue)) {
        if (queue->first == QUEUE_MAX_SIZE - 1) {
            queue->first = 0;
        } else {
            queue->first += 1;
        }
        queue->size -= 1;
        answer = queue->items[queue->first];
    }
    return answer;
}

/* Main */

int main(int argc, char const* argv[])
{
    Queue fila;
    init(&fila);

    Queue norte;
    init(&norte);
    Queue sul;
    init(&sul);
    Queue leste;
    init(&leste);
    Queue oeste;
    init(&oeste);

    char input[10001];
    int opc;
    int counter = 0;

    do {
        Element plane;
        init_aeronave(&plane);
        fgets(input, 10001, stdin);
        if (input[0] != 'A') {
            if (input[0] == '0') {
                opc = 0;
            } else {
                switch (input[1]) {
                    case '1':
                        opc = -1;
                        break;
                    case '2':
                        opc = -2;
                        break;
                    case '3':
                        opc = -3;
                        break;
                    case '4':
                        opc = -4;
                        break;
                }
                fgets(input, 10001, stdin);
            }
        }
        if (opc < 0) {
            plane->ponto_cardeal = opc;
            strcpy(plane->identificador, input);
            plane->identificador[strcspn(plane->identificador, "\n")] = 0;
            switch (opc) {
                case -1:
                    enqueue(oeste, plane);
                    break;
                case -2:
                    enqueue(sul, plane);
                    break;
                case -3:
                    enqueue(norte, plane);
                    break;
                case -4:
                    enqueue(leste, plane);
                    break;
            }
            counter += 1;
        }
    } while (opc != 0);

    do {
        Element aux;

        if (!is_empty(oeste)) {
            aux = dequeue(oeste);
            if (get_size(oeste) == 0 && is_empty(leste) && is_empty(norte) && is_empty(sul)) {
                printf("%s\n", aux->identificador);
            } else {
                printf("%s ", aux->identificador);
            }
        }

        if (!is_empty(norte)) {
            aux = dequeue(norte);
            if (get_size(norte) == 0 && is_empty(oeste) && is_empty(sul) && is_empty(leste)) {
                printf("%s\n", aux->identificador);
            } else {
                printf("%s ", aux->identificador);
            }
        }

        if (!is_empty(sul)) {
            aux = dequeue(sul);
            if (get_size(sul) == 0 && is_empty(oeste) && is_empty(leste) && is_empty(norte)) {
                printf("%s\n", aux->identificador);
            } else {
                printf("%s ", aux->identificador);
            }
        }

        if (!is_empty(leste)) {
            aux = dequeue(leste);
            if (get_size(leste) == 0 && is_empty(oeste) && is_empty(norte) && is_empty(sul)) {
                printf("%s\n", aux->identificador);
            } else {
                printf("%s ", aux->identificador);
            }
        }

    } while (!is_empty(oeste) || !is_empty(norte) || !is_empty(sul) || !is_empty(leste));

    return 0;
}