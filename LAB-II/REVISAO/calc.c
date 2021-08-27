#include "calc.h"

pilhaOp *criaStack() { 
  return NULL;
}

pilhaOp *pushOp (pilhaOp *q, char a) { // insere no topo da pilha de op 
  pilhaOp *new = (pilhaOp*)malloc(sizeof(pilhaOp));
  pilhaOp *aux = q;
  new->item=a;
  new->prox = NULL;
      
    if( q == NULL) {
      return new;
    } else {
      while ( aux->prox != NULL) {
        aux=aux->prox;
      }
      aux->prox=new;
    }
  return q;
}

void mostraStackOp (pilhaOp *q) { // mostra operadores
  pilhaOp *aux = q;

  if (q == NULL) {
    printf("ERRO! nenhum operador");
  } 

  for ( aux=q ; aux!= NULL ; aux=aux->prox) {
    printf(" %c ", aux->item);
  }
}

stack *cria(){ // cria pilha op
  stack *novo = (stack*)malloc(sizeof(stack));
  for(int i=0; i<20; i++) {
      novo->num[i]= -1;
  }
  novo->i=0;
  return novo;
}

void stackPush(stack *w, float numero) { // insere no topo da pilha de operandos
  if (w->i < MAX_POSICAO) {
    w->num[w->i] = numero;
    w->i++;
  }
}

float stackPop(stack *w) { // retira e retorna o topo da pilha de op
  float x = w->num[(w->i)-1];
  w->i--;
  return x;
}

void mostraStack (stack *w){ // mostra pilha operandos
  stack *aux = w;

    for( int i=0; i< aux->i; i++) {
      printf(" %f ", aux->num[i]);
    }
}

void liberaStack( stack *w) { // libera pilha operandos
  w=NULL;
}

void liberaOp (pilhaOp *q) { // libera pilha de op 
  q = NULL;
}


float calculadora( float op1, float op2, char op) {
  float resultadoOp;

  switch(op) {
    case '+':
      return resultadoOp=op1+op2;
    break;
    case '-':
      return resultadoOp=op1-op2;
    break;
    case '/':
      return resultadoOp=op1/op2;
    break;
    case '*':
      return resultadoOp=op1*op2;
    break;
  }
  return 0;
}


char pop_operadores(pilhaOp *q) { // Remove e retorna o ultimo elem da pilha de op
  pilhaOp *aux=q, *count=NULL;
  char a; 

  if(q->prox == NULL)
 {
   a = q->item;
   return a;
 }
 
 while (aux->prox != NULL) {
   count=aux;
   aux=aux->prox;
 }

 a=aux->item;
 count->prox=NULL;
 return a;
 }