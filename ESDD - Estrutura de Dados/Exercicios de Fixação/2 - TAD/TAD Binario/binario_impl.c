#include "binario.h"

struct type_binario{
    bool bits[BITS_SIZE];
};

Binario criar_binario(char string[BITS_SIZE+1]){

    Binario numero;
    numero = malloc(sizeof(struct type_binario));

    zerar_binario(numero);

    for(int i = strlen(string) - 1, j = BITS_SIZE - 1; i >= 0; i--, j--){
        if (string[i] == '1')
        {
            numero->bits[j] = true;
        }
    }

    if(validar_binario(numero) == false){
        zerar_binario(numero);
    }
    return numero;
}

void destruir_binario(Binario numero){
    free(numero);
}

bool validar_binario(Binario numero){
    bool isValid = true;

    for (int i = 0; i < BITS_SIZE && isValid; i++)
    {
        if (numero->bits[i] != false && numero->bits[i] != true)
        {
            isValid = false;
        }
    }

    return isValid;
}


void zerar_binario(Binario numero){
    for (int i = 0; i < BITS_SIZE; i++)
    {
        numero->bits[i] = false;
    }

}


void imprime_binario(Binario numero){

    int count = 0;
    printf("Binario: [ ");

    for (int i = 0; i < BITS_SIZE; i++)
    {
        printf("%d", numero->bits[i]);
        count++;

        if (count == 4)
        {
            printf(" ");
            count = 0;
        }
        
    }

    printf("]");
    
}


Binario leitura_binario(char* mensagem){

    Binario numero;
    numero = criar_binario("0");

    char bin[BITS_SIZE+1];

    printf("%s", mensagem);
    
    scanf("%s", bin);

    for(int i = strlen(bin) - 1, j = BITS_SIZE - 1; i >= 0; i--, j--){

        if (bin[i] == '1')
        {
            numero->bits[j] = true;
        }
    }

    return numero;

}


int binario_to_int(Binario numero){
    
    int num = 0;

    for (int i = 0, j = BITS_SIZE - 1; i < BITS_SIZE; i++, j--)
    {
        if (numero->bits[i] == true)
        {
            num += pow(2, j);
        }
    }

    return num;
}


Binario soma_binario(Binario n1, Binario n2){

    int int_to_bin;

    Binario n3;
    n3 = criar_binario("0");

    int_to_bin = binario_to_int(n1) + binario_to_int(n2);

    for (int i = 0, j = BITS_SIZE - 1; i < BITS_SIZE; i++, j--)
    {
        if (int_to_bin - pow(2, j) >= 0)
        {
            n3->bits[i] = true;
            int_to_bin -= pow(2, j);
        }
        else
        {
            n3->bits[i] = false;
        }
          
    }

    return n3;

}