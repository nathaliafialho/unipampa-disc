#include "lista.h"

int main () {
 int op;
 int matricula; 

 do {
   printf("\n ### MENU DE OPÇÕES ### \n");
   printf("1 - Inserir aluno:\n");
   printf("2 - Buscar aluno (por matricula):\n");
   printf("3 - Imprimir alunos:\n");
   printf("4 - Remover aluno (por matricula):\n");
   printf("5 - Verificar se a lista está vazia:\n");
   printf("0 - Sair:\n");
   printf("\n#############################\n");
   printf("Digite uma opção:");
  scanf("%d", &op);

  switch(op) {
    case 1:
      // Inserir aluno
      // ARRUMAR INSERIR MATRICULA DO ALUNO ! 
      inserirAluno();
    break;
    case 2:
      // Buscar aluno (por matricula)
      procMat();
    break;
    case 3:
      // Imprimir lista de alunos
      mostrar();
    break;
    case 4:
      // Remover aluno ( por matricula)
      printf("Digite a matricula:");
      scanf("%i", &matricula);
      procuraMatricula(matricula, removeMatricula);
    break;
    case 5:
      //Verificar se a lista esta vazia
      verifica();
    break;
    case 0:
      //Sair
      printf("Saindo");
      exit(0);
    break;
    default:
      printf("[ERRO] Digite uma opção válida!");
      exit(-1);
    break;
  }
 } while (op != 0); 
 return 0;
}