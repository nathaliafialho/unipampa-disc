#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
    int num;
    struct Elemento *prox;
} Lista;

typedef struct elemento {
    Lista *inicio;
    Lista *fim;
} Tperc;


void inicializaLista(Tperc *lista1) {
    lista1->inicio=NULL;
    lista1->fim=NULL;
}

void inicializaListaDois(Tperc *lista2) {
    lista2->inicio=NULL;
    lista2->fim=NULL;
}


void insereLista(Tperc *lista1) {
    Lista *novo1;
    novo1=malloc(sizeof(Lista));

    printf("\n Valor: ");
    scanf("%d", &novo1->num);

    novo1->prox=NULL;
        if (lista1->inicio == NULL) {
                lista1->inicio=novo1;
                lista1->fim=novo1;
        }
        else {
           lista1->fim->prox=novo1;
           lista1->fim=novo1;
        }
}

void insereListaDois(Tperc *lista2) {
    Lista *novo2;
    novo2=malloc(sizeof(Lista));

    printf("\n Valor: ");
    scanf("%d", &novo2->num);

    novo2->prox=NULL;
        if (lista2->inicio == NULL) {
                lista2->inicio=novo2;
                lista2->fim=novo2;
        }
        else {

           lista2->fim->prox=novo2;
           lista2->fim=novo2;
        }

}

void apresentaLista(Tperc *lista1) {
    Lista *aux;
    aux=lista1->inicio; 

        if (aux == NULL) {
            puts("lista vazia.");
        } else {
                while(aux != NULL) {
                    printf(" %d |", aux->num);
                aux=aux->prox;
                }
        }
}

void juntarLista(Tperc *lista1, Tperc *lista2) {
        Lista *aux;
        aux=lista1->inicio;

        while(aux->prox!=NULL){
          aux=aux->prox;
        }
        aux->prox=lista2->inicio;

        for(aux=lista1->inicio;aux!=NULL;aux=aux->prox)
          printf("%d |", aux->num);
}

int main () {
    int op;

    Tperc L1;
    Tperc L2;

    inicializaLista(&L1);
    inicializaLista(&L2);

    do{
        printf("\n -----MENU----- \n");
        printf("1- Inserir na lista 1 \n");
        printf("2- Inserir na lista 2 \n");
        printf("3- Exibir lista 1 \n");
        printf("4- Exibir lista 2 \n");
        printf("5- Juntar as duas listas\n");
        printf("0- Sair \n");
        printf("DIGITE A OPCAO DESEJADA: ");
            scanf("%d", &op);
        switch (op){
            case 1:
                insereLista(&L1);
            break;
            case 2:
                insereListaDois(&L2);
            break;
            case 3:
                apresentaLista(&L1);
            break;
            case 4:
                apresentaLista(&L2);
            break;
            case 5:
             	juntarLista(&L1,&L2);
            break;
            case 0:
            exit(0);
            break;
            default:
                printf("Opcao invalida");
                exit(0);
            break;
        }

    }while(op!=0);

return 0;
}