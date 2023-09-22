#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool strComp(char*, char*);

int main()
{

    char* sentence1;
    char* sentence2;

    sentence1 = malloc(sizeof(char) * 50);
    sentence2 = malloc(sizeof(char) * 50);

    printf("\nDigite uma frase: [Max size: 50]: ");
    fgets(sentence1, 50, stdin);

    printf("\nDigite uma frase: [Max size: 50]: ");
    fgets(sentence2, 50, stdin);

    printf("\n%s", strComp(sentence1, sentence2) ? "Sim" : "Nao");

    return 0;
}

bool strComp(char* sentence1, char* sentence2){
    
    int  i, j;

    for (i = 0, j = 0; *(sentence1+i) != '\0' && *(sentence2+j) != '\0'; i++)
    {
        if (*(sentence1 + i) == *(sentence2+j))
        {
            j++;
        }
    }

    return *(sentence2+j) == '\0' ? true : false;
}
