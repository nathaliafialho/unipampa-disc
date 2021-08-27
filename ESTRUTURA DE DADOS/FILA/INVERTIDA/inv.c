#include<stdio.h>
#include <stdio.h>
#include "tFila.h"
#define MAXF 10
#define MAXP 10

struct p{
     int x;
};
struct q {
     Tfila item[MAXF];
    int inicio, fim, t;
};
struct t{
     Tfila item[MAXP];
    int topo;
};

void criaFilaVazia(Fila *f) {
    f-> inicio = 0;
    f-> fim = 0;
    f-> t = 0;
}
void CriarPilhaVazia(Pilha *p){
  p-> topo = 0;
}
int filaVazia(Fila *f){
    return(f->inicio == f->fim);
}
int pilhaVazia(Pilha*p) {
    return(p->topo == 0);
}
int filaCheia(Fila *f) {
    return((f->fim+1)%MAXF == f->fim);
  }
int pilhaCheia(Pilha *p){
    return(p->topo == MAXP);
}
void enfileirar(Fila *f, Tfila x){  
	 if(filaCheia(f)) 
      printf("fila cheia\n");
     else {
          f->item[f->fim] = x;
          f->fim = (f->fim + 1)% MAXF;
          f->t++;
     }
}

void empilhar(Pilha *p, Tfila x){  
	  if(pilhaCheia(p))
      printf("pilha cheia \n");
      else { 
          p->item[p->topo] = x;
          p->topo++;
      }
}

void desenfileirar(Fila *f,Tfila x){ 
        if(filaVazia(f))
        printf("fila Vazia \n");
        else {
            x = f->item[f->inicio];
            f->inicio = (f->inicio + 1)%MAXF;
            f->t--;
        }
}

void desempilhar(Pilha *p, Tfila x){ 
	 if(pilhaVazia(p))
	  printf("pilha vazia\n ");
	 else {
      p->topo--;
      x = p->item[p->topo];
	 }
}

void mostraElem(Fila *f){ 
        int x;
    for(x=f->inicio ;x<f->t; x++){
        printf("%d", f->item[x]);
    }
}

void inverterFila (Fila *f) {
  Pilha *aux; 
  Tfila x;
  pilhaVazia(&aux);
      while(!filaVazia(f)) {
        desenfileirar(&(*f),x); // tira da fila e bota elem no x 
        mostraElem(&x);
        empilhar(&aux,x);
      }
 while(!pilhaVazia(aux)) {
      desempilhar(&aux,x);
      mostraElem(&x);
      Enfileirar(&(*f),x);
     }
}

void liberaFila(Fila *f) {
    free(f);
}

void liberaPilha(Pilha *p){
    free(p);
}