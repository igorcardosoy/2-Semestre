#include "Data.h"

int main()
{
    Data datas[6];
    Data dataAux;
    char string[12];
    int i = 0;
    bool valid, trocou = true;

    valid = criarData(10, 10, 10, &dataAux);

    while (i != 6)
    {
        printf("\nDigite a data (DD/MM/AAAA): ");
        fgets(string, 12, stdin);

        valid = criarDataDeString(string, &datas[i]);

        if (valid)
        {
            i++;
        }
        else
        {
            printf("\nData invalida!");
        }
    }
    
    // Bubble sort
    for (i = 0; i < 6 && trocou; i++)
    {
        trocou = false;
        for (int j = 0; j < (6 - i - 1); j++)
        {
            if (compararData(datas[j], datas[j + 1]) == 1)
            {
                dataAux = datas[j + 1];
                datas[j + 1] = datas[j];
                datas[j] = dataAux;
                trocou = true;
            }
        }
    }

    // Mostrar datas
    for (i = 0; i < 6; i++)
    {
        printf("\n%s", toString(datas[i]));
    }

    return 0;
}
