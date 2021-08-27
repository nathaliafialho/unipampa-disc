/* Usando a seguinte struct, implemente uma
pilha ou uma fila usando o conceito de TAD
e makefile
*/
#include "exec.h"

void inicializa(tpilha *p) {
    p->topo=NULL;
}

void push(tpilha *p) {
    elem *novo;
    novo = (elem*)malloc(sizeof(elem));

        printf("Inserir nome:");
        scanf("%s", &novo->nome);
        printf("Inserir nota:");
        scanf("%f", &novo->nota);
    novo->prox=NULL;

        if(p->topo == NULL) {
            p->topo=novo;
        } else {
            novo->prox = p->topo;
            p->topo=novo;
        }
}

void pop(tpilha *p) {
    elem *aux;

        if(p->topo == NULL) {
            printf("pilha vazia");
        } else {
            aux = p->topo;
            p->topo=p->topo->prox;
            free(aux);
        }
}

void mostra_pilha(tpilha *p) {
    elem *aux2 = p->topo;

    while ( aux2 != NULL) {
        printf("%s\t\t%.2f\n", aux2->nome, aux2->nota);
        aux2=aux2->prox;
    }
}