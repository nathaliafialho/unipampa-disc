#include "arvore.h"

int main() {
	arv a;
	int op,num;

	do{
    printf("\n--------MENU--------\n");
    printf("[1] -> Criar\n");
    printf("[2] -> Inserir\n");
    printf("[3] -> Remover\n");
    printf("[4] -> Imprimir\n");
    printf("[5] -> Liberar\n");
    printf("[0] -> Sair\n");
    printf("--------------------\n");
    printf("Digite a opcao desejada:");
		scanf("%d",&op);
		switch(op){
			case 1:
            a=cria();
            break;

			case 2:
            num=dados();
			a=insere(a,num);
            break;

			case 3:
			printf("Exclui: ");
            scanf("%d",&num);
			a=exclui(a,num);
            break;

			case 4:
			printf("Pre-fixada a esquerda:\n");
            preEsq(a);
			printf("\nCentral a esquerda:\n");
            centro_esq(a);
			printf("\nPos-fixada a esquerda:\n");
            posfEsq(a);
			break;

			case 5:
            a=libera(a);
            break;

            case 0:
            printf("Saindo..");
            exit(0);
            break;

			default:
             printf("ERRO: opcao invalida!\n");
             exit(0);
             break;
		}

	}while(op!=0);

return 0;
}