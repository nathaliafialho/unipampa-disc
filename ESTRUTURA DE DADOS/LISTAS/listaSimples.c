#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elemento {
    int info;
    struct Elemento *prox; 
} TElemento; 

typedef struct Lista {
    TElemento *inicio; 
    TElemento *fim;
} TLista; 

void inicializaLista(TLista *lista) {
    lista->inicio=NULL;
    lista->fim=NULL; 
}

void insereLista(TLista *lista, int x) {
    TElemento *novo;
    novo=(TElemento*)malloc(sizeof(TElemento));

    novo->info=x;
    novo->prox=NULL;

            if (lista->inicio==NULL) {
                lista->inicio=novo;
                lista->fim=novo;
            } else {
                lista->fim->prox=novo;
                lista->fim=novo;
            }
}

void apresentaLista(TLista *lista) {
    TElemento *aux; 

        aux=lista->inicio;

            if(aux==NULL) {
                puts("lista vazia");
            } else {

                    while (aux != NULL) {
                        printf(" %d | ", aux->info);
                        aux=aux->prox;
                    }
            }
}

int main () {
    int op, q;  
    TLista L1; 
    inicializaLista(&L1);  
    do {
        printf("\n----- MENU -----\n");
        printf("1- Inserir na lista\n");
        printf("2- Exibir na lista\n");
        printf("0- Sair\n");
        printf("Digite a opcao desejada:");
        scanf("%d",&op); 
            switch(op) {
                case 1:
                    printf("Digite o elemento a ser inserido:");
                    scanf("%d", q);
                    insereLista(&L1, q);
                break;
                case 2:
                    apresentaLista(&L1);
                break;
                case 0:
                    printf("Saindo..");
                    exit(0);
                break;
                default:
                    printf("Opcao invalida..");
                    exit(0);
                break;
            }
    } while (op!=0); 
return 0;
}