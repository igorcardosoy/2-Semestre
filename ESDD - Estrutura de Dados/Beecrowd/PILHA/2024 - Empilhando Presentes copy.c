// URI: https://www.urionlinejudge.com.br/judge/pt/problems/view/2024

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100000

typedef struct presente {
    int largura;
    int altura;
    int profundidade;
} Presente;

typedef struct stack* Pilha;
typedef Presente Tipo_Informacao;

struct stack {
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha);
bool is_full(Pilha pilha);
bool is_empty(Pilha pilha);
bool push(Pilha pilha, Tipo_Informacao elemento);
bool pop(Pilha pilha, Tipo_Informacao* elemento);
void stack_two(Pilha pilha, Presente presente, Presente topo);
void rotate_presete(Presente* presente);



int main()
{
    long n = 1;
    long altura_maxima = 0;
    Pilha pilha;
    bool find = true;

    init(&pilha);

    scanf("%ld", &n);

    for (int i = 0; i < n; i++) {

        Presente presente;
        scanf("%d %d %d", &presente.largura, &presente.altura, &presente.profundidade);
        if (i == 0) {
            push(pilha, presente);
        } else {
            Presente anterior;
            pop(pilha, &anterior);

            if (presente.largura <= anterior.largura && presente.profundidade <= anterior.profundidade) {
                stack_two(pilha, presente, anterior);
            } else {
                rotate_presete(&presente);
                if (presente.largura <= anterior.largura && presente.profundidade <= anterior.profundidade) {
                    stack_two(pilha, presente, anterior);
                } else {
                    rotate_presete(&presente);
                    if (presente.largura <= anterior.largura && presente.profundidade <= anterior.profundidade) {
                        stack_two(pilha, presente, anterior);
                    } else {
                        find = false;
                        break;
                    }
                }
            }
        }
    }
    Presente topo;
    while (!is_empty(pilha)) {
        pop(pilha, &topo);
        altura_maxima += topo.altura;
    }

    if (!find) {
        printf("-1\n");
    } else if (n >= 1) {
        printf("%ld\n", altura_maxima);
    }

    return 0;
}

void rotate_presete(Presente* presente)
{
    int aux;

    aux = presente->largura;
    presente->largura = presente->altura;
    presente->altura = presente->profundidade;
    presente->profundidade = aux;
}

void stack_two(Pilha pilha, Presente presente, Presente topo)
{
    push(pilha, topo);
    push(pilha, presente);
}

void init(Pilha* pilha)
{
    *pilha = malloc(sizeof(struct stack));

    if (*pilha != NULL) {
        (*pilha)->topo = -1;
    }
}


bool is_full(Pilha pilha)
{

    if (pilha->topo == MAX_STACK_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool is_empty(Pilha pilha)
{

    return pilha->topo == -1;

}


bool push(Pilha pilha, Tipo_Informacao elemento)
{
    bool deuCerto = false;

    if (pilha != NULL) {
        if (!is_full(pilha)) {
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
            deuCerto = true;
        }
    }

    return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento)
{
    bool deuCerto = false;

    if (pilha != NULL) {
        if (!is_empty(pilha)) {
            *elemento = pilha->itens[pilha->topo];
            pilha->topo -= 1;
            deuCerto = true;
        }
    }

    return deuCerto;
}
