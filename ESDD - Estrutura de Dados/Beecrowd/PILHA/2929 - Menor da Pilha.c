#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

typedef struct stack* Pilha;
typedef long long Tipo_Informacao;

void init(Pilha* pilha);
bool is_full(Pilha pilha);
bool is_empty(Pilha pilha);
bool push(Pilha pilha, Tipo_Informacao elemento);
bool pop(Pilha pilha, Tipo_Informacao* elemento);
Tipo_Informacao min_stack(Pilha p1);  

struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};

int main() {
    Pilha pilha;
    Tipo_Informacao valor, min;
    char escolha[5];
    unsigned operations;

    init(&pilha);

    scanf("%u", &operations);

    while (operations--){
        scanf("%s", escolha);

        if (strcmp(escolha, "PUSH") == 0) {  
            scanf("%lld", &valor);
            push(pilha, valor);
        } else if (strcmp(escolha, "POP") == 0) {  
            pop(pilha, &valor);
        } else {
            min =  min_stack(pilha);
            if (min == -1){
                printf("EMPTY\n");
            } else {
                printf("%lld\n", min);
            }
        }
    }

    free(pilha);

    return 0;
}

Tipo_Informacao min_stack(Pilha p1){
    if (is_empty(p1)){
        return -1; 
    }

    Tipo_Informacao min = p1->itens[p1->topo];

    for (int i = p1->topo - 1; i >= 0; i--){
        if (p1->itens[i] < min){
            min = p1->itens[i];
        }
    }

    return min;
}

void init(Pilha* pilha){
	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}


bool is_full(Pilha pilha){
	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    } else {
	    return false;
    }
}

bool is_empty(Pilha pilha){
    return pilha->topo == -1 ? true : false;
}


bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if(pilha != NULL){
		if(!is_full(pilha)){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if(pilha != NULL){
		if(!is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		} else {
            printf("EMPTY\n");
        }
	}

	return deuCerto;
}