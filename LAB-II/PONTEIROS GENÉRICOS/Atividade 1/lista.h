#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  int matricula;
  char nome[50];
} aluno;

typedef struct gener{
  void *type; 
  struct gener *prox;
} listaGen;

listaGen* procuraMatricula (int mat, void (*callback)(void*, int));
void insere(void *estrutura);
void mostrar();
void matricula (void *mat, int i);
void verifica();
void inserirAluno();
void procMat();
void removeMatricula (void *estrutura, int i);