#include "arv.h"


// /*    Cria arvore   */


/*    Insere elementos na arvore   */
void *insereArvore (arvore *arv, int x) {
  if (arv == NULL) {  // se arv vazia adiciona elemento 'x' 
      arv = (arvore*)malloc(sizeof(arvore));
      arv->info = x;
      arv->pai = NULL;
      arv->esquerda=NULL;
      arv->direita = NULL;
  } else if (x < arv->info) { // se valor inserido em 'x' for menor que pai
    arv->esquerda = insereArvore(arv->esquerda, x);
    arv->esquerda->pai= arv;
  } else if (x > arv->info) { // se valor inserido em 'x' for maior que pai 
    arv->direita = insereArvore(arv->direita, x);
    arv->direita->pai=arv;
  } else if (x == arv->info) { // se valor inserido em 'x' for igual ao valor de pai
    printf("[erro]!!");
  }
  return arv;
}

/*    Busca elementos na arvore   */
void *buscaArvore (arvore *arv, int x) {
  if(arv == NULL) {  // se arv igual a null = vazia
    printf("arvore vazia!");
  } else {
    if (arv->info == x) { // se achar valor a ser buscado, imprime 
      printf(" %d", x);
    } else if (arv->info > x) {  // se o valor a ser buscado é menor que pai, percorre arvore da esquerda
      return buscaArvore(arv->esquerda, x);
    } else { // se o valor a ser buscado é maior que pai, percorre arvore da direita 
      return buscaArvore(arv->direita, x); 
    }
  }
}

/*   Valor minimo   */
arvore *minimum(arvore *arv) {
  while (arv->esquerda != NULL) { // busca o menor valor da arvore da esquerda(menor elemento)
    arv=arv->esquerda;
  }
  return arv;
}


/*    Valor maximo   */
arvore *maximum (arvore *arv) {
  while (arv->direita != NULL) { // busca o maior valor da arvore da direita(maior elemento)
    arv=arv->direita;
  }
  return arv; 
}

/*    Imprime Pre-ordem   */
void imprime_pre(arvore *arv) {
  printf("(");
  if(arv != NULL) {
    printf("%d", arv->info);
    imprime_pre(arv->esquerda);
    imprime_pre(arv->direita);
  }
  printf(")");
}

/*    Imprime Pos-ordem   */
void imprime_pos(arvore *arv){
  printf(")");
  if(arv != NULL) {
    imprime_pre(arv->esquerda);
    imprime_pre(arv->direita);
    printf("%d", arv->info);
  }
  printf(")");
}

/*    Imprime Simétrico    */
void imprime(arvore *arv) {
  printf("(");
    if(arv != NULL) {
      imprime_pre(arv->esquerda);
      printf("%d", arv->info);
      imprime_pre(arv->direita);
    }
  printf(")");
}


/*   Libera arvore  */
arvore *liberaArvore(arvore *arv) {
  if (arv != NULL) {
    liberaArvore(arv->esquerda);
    liberaArvore(arv->direita);
    free(arv);
  }
  return NULL;
}


/*    Nodo Predecessor   */
int predecessorArvore(arvore *arv) {
  if(arv->esquerda != NULL) {
    printf("%d", maximum(arv->esquerda));
  }
  arvore *aux = arv->pai;
  while( aux != NULL && arv==aux->esquerda){
    arv=aux;
    aux=arv->pai;
  }
  printf("predecessor: %d", aux->info);
}


/*    Nodo Sucessor   */
int sucessorArvore(arvore *arv){
  if(arv->direita != NULL) {
    printf("%d", minimum(arv->direita));
  }
  arvore *aux = arv->pai;

  while (aux!=NULL && arv== aux->direita) {
    arv=aux;
    aux=arv->pai;
  }
  printf("sucessor: %d", aux->info);
}


/*    Retira elemento da arvore   */
// arvore *retiraArvore(arvore *arv, int x) {
//   if(arv == NULL) { // se arv igual null = vazia
//     printf("arvore vazia");  
//   } else if (x < arv->info) { // se elemento x for menor que elemento pai retira do ramo da esquerda 
//     arv->esquerda = retiraArvore(arv->esquerda, x);
//   } else if (x > arv->info) { // se elemento x for maior que pai retira do ramo da direita
//     arv->direita = retiraArvore(arv->direita, x);
//   } else { // condicoes 
//           if (arv->esquerda == NULL && arv->direita == NULL) { // arvore sem filhos retorna NULL
//             return NULL;
//           } else if (arv->direita == NULL) { // se arvore vazia na direita, percorre o lado esquerdo
//             arvore *aux = arv; 
//             arv = arv->esquerda;
//             free(aux);
//           } else if (arv->esquerda == NULL) { // se arvore vazia na esquerda, percorre o lado direito
//             arvore *aux = arv;
//             arv= arv->direita;
//             free(aux);
//           } else {
//             arvore *index = arv->esquerda;
//               while (index->direita != NULL) {
//                 index=index->direita;
//               }
//             arv->info= index->info;
//             index->info= x;
//             arv->esquerda= retiraArvore(arv->esquerda, x);
//           }
//   }
//   return arv;
// }