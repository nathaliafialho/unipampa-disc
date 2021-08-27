#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MAX 5 

struct fila {
    int ini;
    int n;
    int vet[MAX];
}; 

Fila *cria() {
    Fila *f= (Fila*)malloc(sizeof(Fila));
    f->ini=0;
    f->n=0;
    return f;
}

int filaVazia(Fila *f) {
    return (f->n == 0);
}

int insere(Fila *f, int v) {
    int pos;
        if(f->n == MAX) {
            printf("fila cheia");
            exit(0);
        }
    pos=(f->ini + f->n) % MAX;
    f->vet[pos]=v;
    f->n++;
}

int retira(Fila *f) {
    int v; 

        if(filaVazia(f)) {
            puts("fila vazia");
            exit(1);
        } 
    v=f->vet[f->ini];
    f->ini=(f->ini + 1) % MAX;
    f->n--;
    return v; 
}

void imprime(Fila *f) {
    int x;
       
        for(x=0; x<f->n; x++)
            printf("%d | ", f->vet[(f->ini+x) % MAX]);
}

void liberaFila(Fila *f) {
    free(f);
}