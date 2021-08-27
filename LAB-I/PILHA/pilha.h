#include <stdio.h>
#include <stdlib.h>

typedef struct info {
  char nome[50];
  float nota;
  struct info *prox;
} elem;

typedef struct pilha {
  elem *topo;
}tpilha;

void inicializa(tpilha *p);
void push(tpilha *p);
void pop(tpilha *p);
void mostra_pilha(tpilha *p);