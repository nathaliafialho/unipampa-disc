#include "tFila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){ 
	int op;
	Tfila x;
	Fila *f;
	Pilha *p;
	criaFilaVazia(&f);
	CriarPilhaVazia(&p);
	do {
		printf("\n-----MENU------\n");
        printf("1- Inserir elemento:\n");
        printf("2- Retirar elemento:\n");
        printf("3- Inverter fila:\n");
        printf("4- Exibir fila:\n");
        printf("0- Sair:\n");
        printf("Digite a opcao desejada:");
		scanf("%d", &op);

		switch (op) {
		    case 1:
                printf("\n Elemento:");
                scanf("%d", &x);
                enfileirar(&f, x);
	        break;

		    case 2:
                printf("\n Elemento retirado: %d\n", x);
                desenfileirar(&f, x);
	        break;

		    case 3:
                inverterFila(&f);
		    break;

		    case 4: 
                mostraElem(&f);
		    break;

		    case 0:
                printf("saindo..");
                exit(0);
            break;

		    default:
                printf("\nERRO: opcao invalida!\n");
                exit(0);
            break;
		}
	}while (op!=0);  
	return 0;
}
