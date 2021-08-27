#include "exec.h"

int main () {
  int op; 
  tpilha pilha;
  inicializa(&pilha);

  do {
      printf("\n1-empilha\t\n2-desempila\t\n3-exibe pilha\t\n0-sair\nDigite a opcao:");
      scanf("%d", &op);
      switch(op){
          case 1:
            push(&pilha);
          break;
          case 2:
            pop(&pilha);
          break;
          case 3:
            mostra_pilha(&pilha);
          break;
          case 0:
            printf("Saindo..");
            exit(0);
          break;
          default:
            printf("ERRO! Digite uma opcao válida!");
            exit(1);
          break;
      }
  } while(op != 0);

  return 0;
}