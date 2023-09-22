#include "ConjuntoInt.h"

struct conjuntoInt
{
    int *num;
    int size;
};

void printSet(ConjuntoInt conjunto)
{
    printf("\n----------Conjunto----------\n");

    for (int i = 0; i < conjunto->size; i++)
    {
        printf("%d ", conjunto->num[i]);
    }

    printf("\n");
}

ConjuntoInt creatSet()
{
    ConjuntoInt conjunto;
    conjunto = malloc(sizeof(struct conjuntoInt));

    conjunto->num = malloc(sizeof(int));

    conjunto->size = 0;

    return conjunto;
}

void destroySet(ConjuntoInt conjunto)
{
    free(conjunto);
}

void insertInt(ConjuntoInt conjunto, int num)
{

    bool isInserted = false;

    conjunto->size += 1;

    conjunto->num = realloc(conjunto->num, sizeof(int) * conjunto->size);

    for (int i = 0; i < conjunto->size && !isInserted; i++)
    {
        if (conjunto->num[i] >= num)
        {
            for (int j = conjunto->size - 2; j >= i; j--)
            {
                conjunto->num[j + 1] = conjunto->num[j];
            }
            conjunto->num[i] = num;
            isInserted = true;
        }
    }

    if (!isInserted)
    {
        conjunto->num[(conjunto->size - 1)] = num;
    }
}

void removeInt(ConjuntoInt conjunto, int num)
{
    for (int i = 0; i < conjunto->size; i++)
    {
        if (conjunto->num[i] == num)
        {
            for (int j = i; j < conjunto->size - 1; j++)
            {
                conjunto->num[j] = conjunto->num[j + 1];
            }

            conjunto->size -= 1;

            realloc(conjunto->num, sizeof(int) * conjunto->size);
        }
    }
}

ConjuntoInt unite(ConjuntoInt conjunto1, ConjuntoInt conjunto2)
{
    ConjuntoInt conjunto3;
    conjunto3 = creatSet();

    for (int i = 0; i < conjunto1->size; i++)
    {
        if (!isOnSet(conjunto3, conjunto1->num[i]))
        {
            insertInt(conjunto3, conjunto1->num[i]);
        }
    }

    for (int i = 0; i < conjunto2->size; i++)
    {
        if (!isOnSet(conjunto3, conjunto2->num[i]))
        {
            insertInt(conjunto3, conjunto2->num[i]);
        }
    }

    return conjunto3;
}

ConjuntoInt intersection(ConjuntoInt conjunto1, ConjuntoInt conjunto2)
{
    int size;

    ConjuntoInt conjunto3;
    conjunto3 = creatSet();

    for (int i = 0; i < getSize(conjunto1); i++)
    {
        if (isOnSet(conjunto2, conjunto1->num[i]))
        {
            if (!isOnSet(conjunto3, conjunto1->num[i]))
            {
                insertInt(conjunto3, conjunto1->num[i]);
            }
        }
    }

    return conjunto3;
}

ConjuntoInt difference(ConjuntoInt conjunto1, ConjuntoInt conjunto2)
{
    int size;
    ConjuntoInt conjunto3;
    conjunto3 = creatSet();

    for (int i = 0; i < getSize(conjunto1); i++)
    {
        if (!isOnSet(conjunto3, conjunto1->num[i]))
        {
            insertInt(conjunto3, conjunto1->num[i]);
        }
        
    }

    for (int i = 0; i < getSize(conjunto2); i++)
    {
        if (isOnSet(conjunto3, conjunto2->num[i]))
        {
            removeInt(conjunto3, conjunto2->num[i]);
        }
    }

    return conjunto3;
}

bool isOnSet(ConjuntoInt conjunto, int num)
{

    bool found = false;

    for (int i = 0; i < conjunto->size && !found; i++)
    {

        if (conjunto->num[i] == num)
        {
            found = true;
        }
    }

    return found;
}

bool isEqual(ConjuntoInt conjunto1, ConjuntoInt conjunto2)
{

    int countEquals = 0;

    if (conjunto1->size == conjunto2->size)
    {
        for (int i = 0; i < conjunto1->size; i++)
        {
            if (conjunto1->num[i] == conjunto2->num[i])
            {
                countEquals++;
            }
        }
    }

    return countEquals == conjunto2->size ? true : false;
}

bool isEmpty(ConjuntoInt conjunto)
{
    return conjunto->size == 0 ? true : false;
}

int getSize(ConjuntoInt conjunto)
{
    return conjunto->size;
}