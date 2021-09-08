// Pesquisa e Classificação de Dados - Trabalho 02
// 17/08/2021
// Nathália da Silva Fialho - nathaliafialho.aluno@unipampa.edu.br
#include "hash.h"

int main () {
  int op; 
  Lista *v;
  v = cria();

  do {
    printf("\n ---- TABELAS HASH ---- \n"); // ENCADEADA
    printf("1- Inserir:\n");
    printf("2- Consultar:\n");
    printf("3- Exibir tudo:\n");
    printf("4- Encerrar:\n");
    scanf("%d", &op);
    
    switch(op) {
      case 1:
      // inserir item 
      inserirHash(v);
      break;
      case 2:
      // consultar tabela 
      consultarHash(v);
      break;
      case 3:
      // Exibir tudo 
      printf("Exibir tabela:");
      mostrarTudo(v);
      break;
      case 4:
      // Encerrar programa
      fim(v);
      break;
      default:
      printf(" Opção inválida!");
      exit(0);
      break;
    }  
  } while (op != 0);
  return 0;
}