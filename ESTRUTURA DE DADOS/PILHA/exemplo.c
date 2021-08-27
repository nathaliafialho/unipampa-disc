#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct {
    int item[TAM]; 
    int topo; 
} TPilha; 

void inicializaTPilha(TPilha *p) {
    p->topo=-1;
} 

int pilhaVazia(TPilha *p) {
    if(p->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

int pilhaCheia(TPilha *p) {
    if(p->topo == TAM-1) {
        return 1;
    } else {
        return 0;
    }
}

void inserePilha(TPilha *p, int x) {
    if(pilhaCheia(p) == 1) {
        printf("ERRO: pilha cheia");
    } else {
        p->topo++;
        p->item[p->topo] = x; 
    }
}

int retiraPilha(TPilha *p) {
    int aux; 

        if(pilhaVazia(p) == 1) {
            printf("ERRO: pilha vazia");
        } else {
            aux=p->item[p->topo];
            p->topo--;
            return aux; 
        }
}

int main() {
    TPilha *p;
    p= malloc(sizeof(TPilha));
    inicializaTPilha(p);

    inserePilha(p, 1);
    inserePilha(p, 2);
    inserePilha(p, 3);
    inserePilha(p, 4);

    
 int r = retiraPilha(p);

    printf("Retirado: %d", r);

return 0; 
}