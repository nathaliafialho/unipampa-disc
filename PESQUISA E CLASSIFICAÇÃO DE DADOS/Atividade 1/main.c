// Pesquisa e Classsificação de Dados - Trabalho 01 - 02/08/2021
// Nathália da Silva Fialho - fialhonathalia9@gmail.com

/*
ERRO NA EXECUÇÃO DO SHELL SORT !! 
*/

#include <stdio.h>
#include <stdlib.h>
#include "at.h"

int main () {
  FILE *arq = NULL;
  int *vet = NULL;
  int op, qnt, op2;
  int aux;
  double aux1, aux2, aux3;
  //aux1, aux2, aux3= -1;

  printf("Quantidade:");
  scanf("%d", &qnt);
  numeros(arq, qnt);

  do {
    printf("\n####### MENU ########\n");
    printf("1. Mostrar vetor:\n");
    printf("2. Escolha de algoritmo:\n");
    printf("3. Mostrar tempos de execução:\n");
    printf("4. Alterar quantidade\n");
    printf("0. Sair\n");
    printf("Digite uma opção: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
      /*##############################################*/
        // Mostrar vetor
        mostraVetor(arq, qnt, 'd');
        break;
      case 2:
       /*##############################################*/
        // Escolha de algoritmos
        printf("\n## Escolha um algoritmo de ordenamento abaixo ## \n");
        printf("1. Insertion Sort:\n");
        printf("2. Shell Sort:\n");
        printf("3. Quick Sort:\n");
        scanf("%d", &op2);
        switch(op2) {
            case 1:
            // InsertionSort
            aux1 = insertion(arq, qnt, vet);
            printf("Digite [1] para ver os valores na tela e [0] para sair.");
            scanf("%d", &aux);
                switch(aux) {
                case 1:
                  mostraVetor(arq, qnt, 'y'); 
                break;
                case 0:
                  printf("saindo..");
                  exit(0);
                break;
                }
            break;

            case 2:
            //ShellSort
            aux2 = shell(arq, qnt, vet);
            printf("Digite [1] para ver os valores na tela e [0] para sair.");
            scanf("%d", &aux);
              switch(aux) {
                case 1:
                  mostraVetor(arq, qnt, 'p');
                break;
                case 0:
                printf("saindo..");
                exit(0);
                break;
              }
           break;

            case 3:
            //QuickSort
            aux3 = sortQuick(arq, qnt, vet);
            printf("Digite [1] para ver os valores na tela e [0] para sair.");
            scanf("%d", &aux);
              switch(aux) {
                case 1:
                  mostraVetor(arq, qnt, 'k');
                break;
                case 0:
                printf("saindo..");
                exit(0);
                break;
              }          
            break;
        }
          case 3:
          /*##############################################*/
          // Tempos de execução 
          printf("Tempo de execução: \n -> Bubble: %lf \n -> Shell: %lf \n -> Quick: %lf", aux1, aux2, aux3);
          printf("\n\n");
            break;
          case 4:
          /*##############################################*/
          // Alterar quantidade
          printf(" Digite a quantidade:");
          scanf("%d", &qnt);
          numeros(arq, qnt); // Gera numeros aleat novamente
            break;
          case 0:
          /*##############################################*/
            printf("\nSAINDO.....");
            exit(0);
            break;
          default:
          /*##############################################*/
          printf("ERRO! Digite uma opção válida.");
              exit(-1);
            break;
         }
  } while(op != 0);
}
