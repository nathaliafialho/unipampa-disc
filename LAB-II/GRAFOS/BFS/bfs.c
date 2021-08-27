#include "info_bfs.h"

Fila *cria_fila() {
  Fila *f = (Fila*)malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

void insere(Fila *f, int i) {
  Lista *novo = (Lista*)malloc(sizeof(Lista));
  novo->v = i;
  novo->prox = NULL;

    if (f->fim == NULL && f->ini == NULL) {
      f->fim = novo;
      f->ini = novo;
    } else {
      f->fim->prox = novo;
      f->fim = novo;
    }
}

int retira(Fila *f) {
  Lista *aux; 
  int i;

  if (f->ini == NULL && f->fim==NULL) {
    printf("Lista Vazia");
  } else {
    aux = f->ini;
    i = aux->v;
    f->ini = aux->prox;

      if (f->ini == NULL) {
        f->fim = NULL;
      }
    free(aux);
    return i;
  }
}

void libera(Fila *f) {
  Lista *aux = f->ini;
  while (aux != NULL) { 
    Lista *l = aux->prox;
    free(aux);
    aux = l;
  }
  free(f);
}

Grafo *cria_grafo(int i) {
  Grafo *graf = (Grafo*)malloc(sizeof(Grafo));
  graf->v = i;
  graf->matriz = (int**)malloc(i*sizeof(int*));

    for(int i=0; i<graf->v; i++) { 
      graf->matriz[i] = (int*)malloc(i*sizeof(int));
    }
  
    for(int i=0; i<graf->v; i++) {
      for(int j=0; j<graf->v; j++) {
        graf->matriz[i][j] = BRANCO;
      }
    }
  return graf;
}

Resultado *result(int i) {
  Resultado *aux_result = (Resultado*)malloc(sizeof(Resultado));
  aux_result->cor = (int*)malloc(i*sizeof(int));
  aux_result->predecessor = (int*)malloc(i*sizeof(int));
  aux_result->distancia = (int*)malloc(i*sizeof(int));

  for (int i=0; i<i; i++) {
    aux_result->cor[i] = BRANCO;
    aux_result->predecessor[i] = -1;
    aux_result->distancia[i] = 0;
  }
  return aux_result;
}

void insereAresta (Grafo *graf, int x, int y) {
  graf->matriz[x][y] = 1;
}

void imprimeListaAdj (Grafo *graf) { 
  printf("\n Vertice -> Lista de adjacencia\n");
  printf("\n");
    for(int i=0; i<graf->v; i++) { 
      printf("%d -> ", i);
      for(int j=0; j<graf->v; j++) {
        if (graf->matriz[i][j] == 1) {
          printf("%d", j);
        }
      }
    }
  printf("\n\n");
}

void imprimeMatriz (Grafo *graf) {
  printf("\nMatriz de adjacencia:\n");
  for(int i=0; i<graf->v; i++) {
    for(int j=0; j<graf->v; j++) {
      printf("%d ", graf->matriz[i][j]); 
    }
    printf("\n");
  }
}

Resultado *bfs(Grafo *graf, int x) {
  Resultado *aux = result(graf->v);
  aux->cor[x] = CINZA;

  Fila *fila = cria_fila();
  insere(fila, x);

    while (fila->fim != NULL) {
      int agr = retira(fila);

        for(int adj = 0; adj< graf->v; adj++) {
          if (graf->matriz[agr][adj] == 1 && aux->cor[adj] == BRANCO) {
            aux->cor[adj] = CINZA;
            insere(fila, adj);
            aux->predecessor[adj] = agr;
            aux->distancia[adj] = aux->distancia[agr] + 1;
          }
        }
        aux->cor[agr] = PRETO;
    }
  return aux;
} 

void imprime_bfs(Grafo *graf, Resultado *aux) {
  printf("\n Resultado BFS: \n");
  for(int i=0; i<graf->v; i++) {
   // printf("Vertice [%d]: Cor: %s, Pred: %d, Dist: %d \n", i, (aux->cor[i])==PRETO ? "Preto" : (aux->cor[i]) == CINZA? "Cinza" : "Branco", aux->predecessor[i], aux->distancia[i]);
    printf(" %d | Predecessor: %d \t Cor: %d \t Distancia: %d \n", i, aux->predecessor[i], aux->cor[i], aux->distancia[i] );
  }
}
