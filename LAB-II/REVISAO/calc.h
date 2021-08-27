#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_POSICAO 20

struct stackOp {
  char item;
  struct stackOp *prox;
};
typedef struct stackOp pilhaOp;

struct Stack {
  int i;
  float num[MAX_POSICAO];
};
typedef struct Stack stack;


struct Calc {
  float op1, op2;
  char op;
};
typedef struct Calc calc;


pilhaOp *criaStack();
pilhaOp *pushOp (pilhaOp *q, char a);
void mostraStackOp (pilhaOp *q);
stack *cria();
void stackPush(stack *w, float numero);
float stackPop(stack *w);
void mostraStack (stack *w);
void liberaStack( stack *w);
void liberaOp (pilhaOp *q);
float calculadora( float op1, float op2, char op);
char pop_operadores(pilhaOp *q);