#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct nodo {
  int cod;
  char descricao[40];
  float valor;
  struct nodo *prox;
} Nodo; 

typedef struct lista {
  Nodo *ini;
  Nodo *fim;
  int tam;
} Lista;


Lista *cria();
void consulta (Lista *l);
int buscar(Lista *l, int cod);
void inserirHash(Lista *l);
void mostrarTudo(Lista *l);
void fim (Lista *l);