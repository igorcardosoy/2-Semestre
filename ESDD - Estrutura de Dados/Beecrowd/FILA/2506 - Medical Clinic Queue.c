#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 25

typedef struct queue* Queue;

typedef struct paciente {
    int hora;
    int minuto;
    int critico;
} Paciente;

struct queue {
    Paciente items[QUEUE_MAX_SIZE];
    int last, first, size;
};

void init(Queue* queue);

bool is_full(Queue queue);

bool is_empty(Queue queue);

bool enqueue(Queue queue, Paciente new_element);

Paciente dequeue(Queue queue);

int main()
{
    int n;
    int count;
    int tempo_ocorrido;
    int h, m, c;

    Paciente p;

    Queue queue;
    init(&queue);

    for (int i = 0; i < 10; i++) {
        tempo_ocorrido = 420;
        count = 0;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &h, &m, &c);
            p = (Paciente){ h, m, c };

            enqueue(queue, p);
        }

        while (!is_empty(queue)) {
            p = dequeue(queue);

            while (tempo_ocorrido < (p.hora * 60) + p.minuto) {
                tempo_ocorrido += 30;
            }

            if (tempo_ocorrido - ((p.hora * 60) + p.minuto) > p.critico) {
                count++;
            }

            tempo_ocorrido += 30;
        }

        printf("%d\n", count);
    }

}

void init(Queue* queue)
{
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    q->first = -1;
    q->size = 0;
    *queue = q;
}

bool is_full(Queue queue)
{
    return queue->size == QUEUE_MAX_SIZE;
}

bool is_empty(Queue queue)
{
    return queue->size == 0;
}

bool enqueue(Queue queue, Paciente new_element)
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

Paciente dequeue(Queue queue)
{
    Paciente answer;

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
