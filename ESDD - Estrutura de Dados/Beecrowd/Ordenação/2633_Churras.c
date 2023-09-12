#include <stdio.h>

struct type_carnes
{
    char carne_type[20];
    int validity;
};

void selectionSort(struct type_carnes carne[], int size);

int main()
{

    int numCarnes, i;

    while (scanf("%d", &numCarnes) != EOF)
    {
        struct type_carnes carne[numCarnes];

        for (i = 0; i < numCarnes; i++)
        {
            scanf("%s", carne[i].carne_type);
            scanf("%d", &carne[i].validity);
        }

        selectionSort(carne, numCarnes);

        for (i = 0; i < numCarnes; i++)
        {
            if (i != 0 && i != numCarnes)
            {
                printf(" ");
            }

            printf("%s", carne[i].carne_type);
        }

        printf("\n");
    }

    return 0;
}

void selectionSort(struct type_carnes carne[], int size)
{
    int smaller;
    int search, i;
    struct type_carnes aux;

    for (i = 0; i < size; i++)
    {
        smaller = i;
        for (search = i + 1; search < size; search++)
        {
            if (carne[search].validity < carne[smaller].validity)
            {
                smaller = search;
            }
        }

        aux = carne[i];
        carne[i] = carne[smaller];
        carne[smaller] = aux;
    }
}
