#include <stdio.h>
#include <stdlib.h>

typedef struct descritor_arvore {
  int tamanho;
  struct arvore *raiz;
} descritor;
typedef struct nodo {
  int info; 
  struct nodo *pai;
  struct nodo *direita;
  struct nodo *esquerda;
} arvore;

// void *criaArvore();
void *insereArvore (arvore *arv, int x);
void *buscaArvore (arvore *arv, int x);
arvore *minimum(arvore *arv);
arvore *maximum (arvore *arv);
void imprime_pos(arvore *arv);
void imprime(arvore *arv);
arvore *liberaArvore(arvore *arv);
void imprime_pre(arvore *arv);
int sucessorArvore(arvore *arv);
int predecessorArvore(arvore *arv);
arvore *retiraArvore(arvore *arv, int x);
