/*
Nathalia da Silva Fialho - [26/06/2021]
*/
#include "calc.h"

int main () {
  int operacao, cont=0, cont_op=0; 
  char op, opRes;
  float operando, op1, op2; 
  pilhaOp *q;
  stack *w = NULL;
  calc *calculad = (calc*)malloc(sizeof(calc));

  do {
      printf("\n##### Calculadora #####\n");
      printf("1- Adicionar operador:\n");
      printf("2- Remover operador:\n");
      printf("3- Adicionar operando:\n");
      printf("4- Remover operando:\n");
      printf("5- Calcular:\n");
      printf("6- Imprimir:\n");
      printf("0- Sair:\n");
      scanf("%d",&operacao);

   switch(operacao) {
     case 1: 
     // Adicionar operados
     if(cont_op == 0) {
      q=cria();
     }
     printf("Insira operador:");
     scanf("%f", &op);
     q = pushOp(q, op);
     cont_op++;
     break;
     case 2:
     // Remover Operador
     pop_operadores(q);
     --cont_op;
     break;
     case 3:
     // Adicionar operando
     if (cont == 0) {
       w = criaStack();
     }
     printf("Insira operando:");
     scanf("%f", &operando);
     stackPush(w, operando);
     cont++;
     break;
     case 4:
     //Remover operando
     --cont;
     break;
     case 5:
     //Calcular
     if(cont != 0 && cont_op >=2) {
        op1=calculad->op1 = stackPop(w);
        op2=calculad->op2 = stackPop(w);
        opRes=calculad->op = pop_operadores(q);
        --cont_op;

        printf("\nOperando 1: %f | Operando 2: %f \n", op1, op2);
        printf("Operador: %c\n",opRes);


        printf("Resultado: %f", calculadora(op1, op2, opRes));
     } else {
       printf("Erro na operacao!");
       exit(-1);
     }
     break;
     case 6:
     //Imprimir
     if(cont != 0) {
       mostraStack(w);
     }
     if(cont_op != 0) {
       mostraStackOp(q);
     }
     break;
     case 0:
     //Sair do prog
     printf("Saindo..");
     exit(0);
     break;
     default:
     printf("Erro! Digite uma opção válida!");
     exit(0);
     break;
   } 
  } while (operacao != 0);
liberaStack(w);
liberaOp(q);
return 0;
}