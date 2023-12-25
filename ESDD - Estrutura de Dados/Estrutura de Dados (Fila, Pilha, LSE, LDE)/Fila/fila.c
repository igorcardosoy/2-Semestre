#include "fila.h"

struct type_fila {
    int first;
    int last;
    int size;
    int data_set[QUEUE_MAX_SIZE];
};

bool init(Fila* fila)
{
    *fila = malloc(sizeof(struct type_fila));
    if (*fila != NULL) {
        (*fila)->size = 0;
        (*fila)->first = -1;
        (*fila)->last = -1;

        return true;
    } else {
        return false;
    }
}

bool enqueue(Fila fila, Info info)
{
    bool answer = false;
    if (!is_full(fila))
    {
        if (fila->last == QUEUE_MAX_SIZE - 1)
        {
            fila->last = 0;
        } else {
            fila->last += 1;
        }
        
        fila->data_set[fila->last] = info;
        fila->size += 1;
        answer = true;
    } 

    return answer;
    
}

Info dequeue(Fila fila)
{
    Info answer = NULL;

    if (!is_empty(fila))
    {
        if (fila->last == QUEUE_MAX_SIZE - 1)
        {
            fila->last = 0;
        } else {
            fila->last += 1;
        }

        fila->size -= 1;
        answer = fila->data_set[fila->first];
    }
    
    return answer;
}

bool is_full(Fila fila)
{
    return fila->size == QUEUE_MAX_SIZE - 1;
}

bool is_empty(Fila fila)
{
    return fila->size == 0;
}