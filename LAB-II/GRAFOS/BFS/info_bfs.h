#include <stdio.h>
#include <stdlib.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2

struct grafo {
  int **matriz; // matriz de adjacencia
  int v; // numero de vértices
};
typedef struct grafo Grafo;

struct resultado{
    int *cor; 
    int *distancia;
    int *predecessor;
};
typedef struct resultado Resultado;

struct lista {
    int v;
    struct lista *prox;
};
typedef struct lista Lista;

struct fila{
    Lista *ini;
    Lista *fim;
};

typedef struct fila Fila;

/*chamada de funcoes*/
Fila *cria_fila();
void insere(Fila *f, int i);
int retira(Fila *f);
void libera(Fila *f); 
Grafo *cria_grafo(int i);
Resultado *result(int i);
void insereAresta (Grafo *graf, int x, int y);
void imprimeListaAdj (Grafo *graf);
void imprimeMatriz (Grafo *graf);
Resultado *bfs (Grafo *graf, int x);
void imprime_bfs(Grafo *graf, Resultado *aux);