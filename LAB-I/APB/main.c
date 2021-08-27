#include "arv.h"

int main () {
  int op, x, op_imprime;
  descritor *d; 
  arvore *arv;
  arvore *m; //pont aux

  do {
        printf("\n######## MENU #########\n");
        // printf("# 1- Cria arvore        #\n");
        printf("# 2- Inserir            #\n");
        printf("# 3- Buscar nodo        #\n");
        printf("# 4- Imprimir           #\n");
        printf("# 5- Minimum            #\n");
        printf("# 6- Maximum            #\n");
        printf("# 7- Predecessor        #\n");
        printf("# 8- Sucessor           #\n");
        printf("# 9- Excluir nodo       #\n");
        printf("# 10- Liberar arvore    #\n");
        printf("# 0- Sair               #\n");
        printf("#########################\n");
        printf("DIGITE UMA OPCAO:");
        scanf("%d", &op);

        switch(op){
          case 1:
          /*cria arvore*/
          // criaArvore();
          // printf("criada com sucesso!");
          break;
          case 2:
          /*Inserir valor na arvore*/
          printf("Valor a ser inserido:\n");
          scanf("%d", &x);
          insereArvore(arv, x);
          break;
          case 3:
          /*Buscar um valor x na arvore*/
          printf("Valor:\n");
          scanf("%d", &x);
          buscaArvore(arv, x);
          break;
          case 4:
          /*Imprime pre sim pos*/
          printf("Imprimir:\n");
          printf("1-Imprimir Pre Ordem:\n");
          printf("2-Imprimir Simetrico:\n");
          printf("3-Imprimir Pos Ordem:\n");
          switch (op_imprime){
          case 1:
            imprime_pre(arv);
            break;
          case 2:
            imprime(arv);
            break;
          case 3:
            imprime_pos(arv);
            break;
          }
          break;
          case 5:
          /*minimum*/
          m = minimum(arv);
          printf("\nminimum: %d\n", m->info);
          break;
          case 6:
          /*maximum*/
          m = maximum(arv);
          printf("\nMaximum: %d\n", m->info);
          break;
          case 7:
          /*Predecessor*/
          sucessorArvore(arv);
          break;
          case 8:
          /*Sucessor*/
          predecessorArvore(arv);
          break;
          case 9:
          /*Exclui elemento da arvore (teste)*/
          // printf("Valor a ser excluido:");
          // scanf("%d", &x);
          // arv = retiraArvore(arv, x);
          // printf("\nElemento excluido!!\n");
          break;
          case 10:
          /*Libera arvore*/
          liberaArvore(arv);
          exit(0);
          break;
          case 0:
          printf("\nSaindo..");
          exit(0);
          break;
          printf("\n[ERRO] Digite uma opcao válida!");
          exit(0);
          default:
          break;
        }
  } while (op != 0);

  return 0;
}