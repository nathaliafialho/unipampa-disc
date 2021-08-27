#include <stdio.h>
#include <stdlib.h>

struct arvore {
	int n;
	struct arvore *esq;
	struct arvore *dir;
};
typedef struct arvore *arv;

arv cria();
int dados();
arv insere(arv a,int num);
int vazia(arv a);
void busca(arv a,int num);
arv libera(arv a);
arv exclui(arv a,int v);
void preEsq(arv a);
void centro_esq(arv a);
void posfEsq(arv a);