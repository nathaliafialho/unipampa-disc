#include "lista.h"

listaGen *init = NULL;
int i=0;

// Procurar por matricula 
listaGen* procuraMatricula (int mat, void (*callback)(void*, int)) {
  listaGen *aux;
  listaGen *aux2 = init; 
  aluno *Aux = (aluno*) init->type;
  int test = 0;

  if ( aux2 == init && Aux->matricula == mat) {
    aux = aux2; 
    test = 1;
  } else {
      while (aux2->prox != NULL) {
        aux = aux2->prox;
        Aux = (aluno*)(aux)->type;
          if((Aux->matricula) == mat){
            break;
          } 
        aux2 = aux2->prox;
      }
      if((aux2 == init && aux2->prox == NULL) || (aux2->prox == NULL && Aux->matricula != mat)) {
        aux2 = NULL;
      }
  }
  callback(aux2, test);
}


// Mostrar dados
void mostrar() {
  listaGen *aux = init;
  printf("\nMATRICULA\tNOME");
  while(aux != NULL) {
    aluno *Aux = (aluno*) aux->type;
    printf("\n%i\t->\t%s", Aux->matricula, Aux->nome);
    printf("\n");
    aux=aux->prox;
  }
  printf("\n");
}

// Matricula  
void matricula (void *mat, int i) {
  listaGen *aux = (listaGen*) mat;

  if (aux == NULL) {
    printf("Matricula não encontrada");
  } else {
    aluno *al; 

    if(aux == init && aux->prox == NULL) {
      al = (aluno*)((aux)->type);
    } else {
      al = (aluno*)((aux->prox)->type);
    } 
    printf("\nMatricula\t\tNome");
    printf("\n%i\t\t%s", al->matricula, al->nome);
  }
}

void verifica() {
  if ( init == NULL) {
    printf("Lista vazia");
  } else {
    printf("Contem dados na lista");
  }
}

// Inserir 
void insere(void *estrutura){
  listaGen *nova = (listaGen*)malloc(sizeof(listaGen));
  nova->type=estrutura;
  nova->prox=NULL;

    if(init == NULL) {
      init = nova; 
    } else {
      listaGen *aux = init;
        while(aux->prox != NULL) {
          aux=aux->prox;
        }
        aux->prox=nova;
    }
}

//Inserir aluno na estrutura
void inserirAluno() {
  aluno *novoAluno = (aluno*)malloc(sizeof(aluno));
  
  i++;
  novoAluno->matricula = i;

  //Inserir nome
  printf("Nome do aluno:");
  scanf("%s", novoAluno->nome);

  // Inserir Matricula  (erro)
  // printf("Matricula:");
  // scanf("%i", novoAluno->matricula);

  insere(novoAluno);
}

// Procura aluno por matricula
void procMat() {
  if (init == NULL){
    printf("Lista vazia");
  } else {
    int matri=0;
    printf("Numero da matricula:");
    scanf("%i", &matri);
    procuraMatricula(matri, matricula);
  }
}

void removeMatricula (void *estrutura, int i) {
  listaGen *rmv = (listaGen*) estrutura;
  listaGen *aux;
  if(rmv == NULL) {
    printf("Matricula não encontrada");
  } else {
      if (rmv == init && rmv->prox == NULL ) {
        free(rmv);
        init == NULL;
      } else if ((rmv == init) && i == 1) {
        init = rmv->prox;
        free(rmv);
      } else {
        aux =(rmv->prox)->prox;
        free(rmv->prox);
        rmv->prox=aux;
      }
      printf("Aluno excluido");
  }
}