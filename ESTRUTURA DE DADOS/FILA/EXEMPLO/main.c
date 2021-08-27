#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
int op, x;
int r;  
Fila *f;

cria(f);

do {

    printf("\n----- MENU -----\n");
    printf("1- Inserir:\n");
    printf("2- Retirar:\n");
    printf("3- Imprimir: \n");
    printf("0- Sair \n");
    scanf("%d", &op);

switch(op){
    case 1:
    printf("Valor a ser inserido:");
    scanf("%d", &x);
    insere(f, x); 
    break;

    case 2:
    r = retira(f);
    printf("retirado: %d", r); 
    break;

    case 3:
    imprime(f);
    break;

    case 0:
    printf("saindo");
    exit(0);
    break;
    
    default:
    printf("ERRO: digite uma opcao valida!");
    exit(0);
    break;
}
}while(op!=0); 

liberaFila(f); 

return 0;
}