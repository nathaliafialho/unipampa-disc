#include "hash.h"
#define MAX 101

int funcao_hash(int cod) {
  return (cod % MAX);
}

Lista *cria() {
  Lista *l = malloc(sizeof(Lista)*MAX);
  l->tam = 0 ;
    for(int i=0; i<MAX; i++) {
      l[i].ini = NULL;
      l[i].fim = NULL;
    }
  return l;
}

int buscar(Lista *l, int cod) {
  int x = 0;
  
      for (Nodo *aux = l; aux != NULL; aux = aux->prox) { 
        if (aux->cod == cod) {
          return x;
        }
        x++;
      }
  return -1;
}

void consulta (Lista *l) {
  int cod, auxIndex, codBusca, i=0;
  
  printf ("Código do produto:");
  scanf("%d", cod);

  auxIndex = funcao_hash(cod);

  Nodo *l = l[auxIndex].ini;
  codBusca = Buscar(l, cod);
  if (codBusca == -1) { 
    printf("Não encontrado!");
  } else {
    Nodo *aux = l;
    while ( i != codBusca) {
      aux = aux->prox;
      i++;
    }
    printf("Código: %d \t Nome: %s \t Valor: %.2f \n", aux->cod, aux->descricao, aux->valor);
  }
}

void inserirHash(Lista *l) {
  int cod, auxIndex;
  char desc[30];
  float valor; 

    printf("Codigo do produto:");
    scanf("%d", cod);
    printf("Descrição do produto:");
    gets(desc);
    fflush(stdin);
    printf("Valor do produto:");
    scanf("%.2f", &valor);
    fflush(stdin);

    auxIndex = funcao_hash(cod);
    printf("Index: %d", auxIndex);
    Nodo *lista = l[auxIndex].ini;  // acha a lista correspondente ao indice

    Nodo *aux2 = malloc(sizeof(Nodo));
    aux2->cod = cod;
    strcpy(aux2->descricao, desc);
    aux2->valor = valor;
    aux2->prox = NULL;

    if (lista == NULL) { 
      l[auxIndex].ini = aux2;
      l[auxIndex].fim = aux2;
      l->tam++;
    } else {
      int busca = buscar(l, cod);
        if (busca == -1) {  // se ja tem item na posicao do vetor, insere no final
          l[auxIndex].fim->prox = aux2;
          l[auxIndex].fim = aux2;
          l->tam++;
        } else {
          printf("\nJá existe essa chave!\n");
        }
    }
  printf("Quantidade de elementos: %d \n", l->tam);
}

void excluir_hash(Lista *l) {
  int cod, auxIndex, busca;

  printf("Codigo do produto:");
  scanf("%d", &cod);

  auxIndex = funcao_hash(cod);
  Nodo *lista = l[auxIndex].ini;

  if ( lista == NULL) {
    printf("Código não existe na tabela!\n");
  } else {
    busca = buscar(l, cod);
    if (busca == -1) {
      printf("Código não existe na tabela!\n");
    } else {
      Nodo *aux = lista;
        if (aux->cod == cod) {
          l[auxIndex].ini = aux->prox;  
          l->tam--;
          printf("Item excluido com sucesso!\n");
        }
        while (aux->prox->cod != cod) {
          aux = aux->prox;
        }
        if (l[auxIndex].fim == aux->prox) {
          aux->prox = NULL;
          l[auxIndex].fim = aux;
        } else {
          aux->prox = aux->prox->prox;
        }
        l->tam--;
        printf("Item removido!");
    }
  }
}

void mostrarTudo(Lista *l) {
  for (int i=0; i<MAX; i++) { 
    Nodo *aux = l[i].ini;
     if (aux == NULL) {
       printf("Posicao -> %d", i);
     } else {
       printf("Posicao -> %d", i);
        while(aux != NULL) {
          printf("Codigo: %d - Nome: %s - Valor: %.2f", aux->cod, aux->descricao, aux->valor);
          aux= aux->prox;
        }
        printf("\n");
     }
  }
  printf("Falor de carga da tabela: %.2f", ((float)l->tam/MAX));
}


void fim (Lista *l) { 
  for (int i=0; i<MAX; i++) {
    Nodo *aux = l[i].ini;
     if(aux != NULL) {
       while(aux != NULL) {
         Nodo *aux2 = aux;
         aux = aux->prox;
         free(aux2);
       }
     }
     l[i].ini = NULL;
  }
}