#include<stdio.h>
#include<stdlib.h>

typedef struct Elemento {
    int info;
    struct Elemento *prox;
} TElemento; 

typedef struct Pilha {
    TElemento *topo;
} TPilha;

void inicializaPilha(TPilha *pilha) {
    pilha->topo=NULL;
}

void push(TPilha *pilha) {
    TElemento *novo; 
    novo=(TElemento*)malloc(sizeof(TElemento));

        printf("Inserir Elemento:");
        scanf("%d", &novo->info);
    novo->prox=NULL;

        if(pilha->topo == NULL) {
            pilha->topo=novo;
        } else {
            novo->prox=pilha->topo;
            pilha->topo=novo;
        }
}

void pop(TPilha *pilha){
    TElemento *aux;

        if(pilha->topo == NULL) {
            printf("pilha vazia"); 
        } else {
            aux=pilha->topo;
            pilha->topo=pilha->topo->prox;
            free(aux);
        }
}

void exibir(TPilha *pilha) {
    TPilha *aux = pilha;

        while(aux->topo != NULL) {
            printf(" %d \n", aux->topo->info);
            aux->topo=aux->topo->prox;
        }
}

int main () {
    int op;
    TPilha P1; 
    inicializaPilha(&P1); 

    do {
        printf(" \n ----- MENU ----- \n ");
        printf("1- Empilhar \n");
        printf("2- Desempilhar \n");
        printf("3- Exibir pilha \n");
        printf("Digite a opcao desejada:");
        scanf("%d", &op);

        switch(op) {
            case 1:
                push(&P1);
            break;
            case 2:
                pop(&P1);
            break;
            case 3:
                exibir(&P1);
            break;
            case 0:
                printf("saindo..");
                exit(0);
            break;
            default:   
                printf("opcao invalida!!");
                exit(0); 
            break;
        }
    } while(op!=0);
}