/*
Implemente uma Lista Duplamente Encadeada a partir da estrutura abaixo:
        struct lista{
            int elemento;
            struct lista *ant;
            struct lista *prox;
        }
        typedef struct lista Lista;
Para manipular a lista desenvolva as seguintes funções ou procedimentos:
a) Criação da lista duplamente encadeada vazia;
b) Verificar se a lista duplamente encadeada está vazia;
c) Obter o tamanho da lista duplamente encadeada;
d) Obter o valor do elemento de uma posição dada;
e) Obter a posição de elemento cujo valor é dado;
f) Inserir um elemento na lista duplamente encadeada, dada a sua posição;
g) Remover um elemento de uma determinada posição;
h) Lembre-se: em cada uma das operações, identifique possíveis situações de erros do usuário e
exiba mensagens para ele nestas situações. (Ex. o programa deve exibir mensagens no caso do
usuário tentar remover um item numa lista que está vazia etc.). 
*/
#include<stdio.h>
#include<stdlib.h>


struct lista {
    int elemento;
    struct lista *ant; 
    struct lista *prox; 
}; 
typedef struct lista Lista;

struct info { // cria o inicio da lista
Lista *inicio;
Lista *fim; 
};
typedef struct info TLista; 

Lista *inicio=NULL;
Lista *fim=NULL;

int tamanho_lista(TLista *lista);

void inicializaLista(TLista *lista) {
    lista->inicio=NULL;
    lista->fim=NULL; 
}

void insereLista(TLista *lista) {

    Lista *novo; 
    novo=malloc(sizeof(Lista));

    printf("\n Informe elemento:");
    scanf("%d", &novo->elemento); 

    novo->prox=NULL;
    novo->ant=NULL; 

    if(lista->inicio==NULL) { // se inicio da lista é igual a NULL
        lista->inicio =novo;
        lista->fim = novo; 
    } else { // se ja tiver na lista
        lista->inicio->ant=novo; // dx de apontar p NULL e aponta p novo
        novo->prox=lista->inicio; // criando o duplo encadeamento
        lista->inicio=novo; // novo elemento é o novo final da lista
    }

}

void exibeLista(TLista *lista) {
    Lista *aux; 

        if (lista->inicio == NULL) {
            printf("\n Lista vazia.");
        } else {
            aux = lista->inicio; 
                while(aux != NULL) {
                    printf("\n Elemento: %d", aux->elemento); 
                    aux=aux->prox;
                }
            printf("\n Fim da Lista.");
        }
}

void buscaElem (TLista *lista) {

}

int tamanho_lista(TLista *lista) {
    int i=0;
    Lista *aux= lista; 

                if(lista == NULL) {
                    printf("\n Lista vazia.");
                    return 0; 
                } 
        while(aux != NULL) {
            i++; 
            aux=aux->prox;
        }
    return i; 
}




void removeElem(TLista *lista) {


}


int main (void) {
    int op;
    int x=0; 
    TLista ListaD; 
    inicializaLista(&ListaD); 

do{

    printf("\n -------MENU------\n");
    printf("1- Inserir elemento na lista:\n");
    printf("2- Exibir lista:\n");
    printf("3- Remover elemento da lista:\n");
    printf("4- Exibir o tamanho da lista:\n");
    printf("0- Sair:\n");
    printf("\n DIGITE A OPCAO DESEJADA:");
    scanf("%d", &op);

        switch(op){
            case 1:
            insereLista(&ListaD);
            break;
            case 2:
            exibeLista(&ListaD);
            break;
            case 3:
        // removeElem(&ListaD);
            break;
            case 4:
            tamanho_lista(&ListaD);
            break;
            case 5:
            
            break;
            case 0:
                printf("\n Saindo.. ");
                exit(0); 
            break;
            default:
                printf("\n Opcao invalida.");
                exit(0);
            break;
            }
            
}while(op!=0); 


return 0;
}