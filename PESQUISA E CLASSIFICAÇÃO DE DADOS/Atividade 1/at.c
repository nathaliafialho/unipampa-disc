#include <stdio.h>
#include <stdlib.h>
#include "at.h"

FILE *abrir(char arq) {
  FILE *arquivo; 
  if (arq == 'a') {
    arquivo = fopen("input.txt", "wt");
  } else if (arq == 'd') {
    arquivo = fopen("input.txt", "rt");
  } else if (arq == 'b') { 
    arquivo = fopen("insertion.txt", "wt");
  } else if (arq == 's') {
    arquivo = fopen("shell.txt", "wt");
  } else if (arq == 'i') {
    arquivo = fopen("quick.txt", "wt");
  } else if (arq == 'y') {
    arquivo = fopen("insertion.txt", "rt");
  } else if (arq == 'p') {
    arquivo = fopen("shell.txt", "rt");
  } else if (arq == 'k') {
    arquivo = fopen("quick.txt", "rt");
  }
  if(arquivo == NULL) { 
    printf("Erro ao abrir arquivo\n");
    exit(1);
  }
  return arquivo;
}

//InsertionSort
double insertion(FILE *arq, int qnt, int *vet) {
  vet = leVetor(arq, qnt, 'd');
  clock_t t;
  int aux;
  printf("Sorteando..\n");
  t=clock();

  for(int x = 1; x < qnt; x++) {
    aux=vet[x];
    int y= x=1;
      while (y >= 0 && vet[y > aux]) {
        vet[y+1] = vet[y];
        y--;
      }
      vet[y+1] = aux;
  }  
}

int quick(int *vetor, int ini, int fim) {
  int x, y, aux, index; 
  x = ini;
  y = fim;
  index = vetor[(ini+fim)/2];

  do {
    while(vetor[x] < index && x < fim) {
      x++;
    }
    while(index < vetor[y] && y > ini) {
      y--;
    }
    if(x <= y) { 
      aux = vetor[x];
      vetor[x] = vetor[y];
      vetor[y] = aux;
      x++;
      y--;
    }
  } while (x <= y);
  if(ini < y) {
    quick(vetor, ini, y);
  }
  if(x < fim) {
    quick(vetor, x, fim);
  }
}

// QuickSort
double sortQuick(FILE *arq, int qnt, int *vet) {
  vet = leVetor(arq, qnt, 'd');
  clock_t t;
  printf("Sorteando..");
  t = clock();
  quick(vet, 0, qnt);
  t = clock() - t;
  escreve(arq, qnt, vet, 'i');
  free(vet);
  return ((double)t)/(CLOCKS_PER_SEC/1000); 
}

//ShellSort
double shell(FILE *arq, int qnt, int *vet) {
 vet = leVetor(arq, qnt, 'd');
 clock_t t;
 int x, y, aux;
 int id = 1;
 printf("Sortendo..");
 t = clock();
 while ( id < qnt ) {
   id = 3 * id + 1;
 }
 while ( id > 1 ) { 
   id = id / 3;
    for (x = id; x < qnt; x++) {
      aux = vet[x];
      y = x;
      while ( x >= id && aux < vet[y-id]) {
        vet[y] = vet[y-id];
        y = y - id;
      }
      vet[y] = aux;
    }
 }
 t = clock() - t;
 escreve(arq, qnt, vet, 's');
 free(vet);
 return ((double)t)/(CLOCKS_PER_SEC/1000);
}

void numeros(FILE *arq, int qnt){
  int *aux; 

  aux = (int*)malloc(qnt * sizeof(int));
  for(int i = 0; i < qnt; i++) {
    aux[i] = rand()%(qnt*2);
  }
  arq = abrir('a');

  for(int x = 0; x < qnt; x++) {
    fprintf(arq, "%d\n", aux[x]);
  }
  printf("\nNúmeros gerados com sucesso!\n");
  fclose(arq);
  free(aux);
}

int* leVetor(FILE *arq, int qnt, char q){
  int *aux, i=0;
  aux= (int*)malloc(qnt * sizeof(int));
  arq = abrir(q);
  while(!feof(arq)){
    fscanf(arq, "%d", &aux[i]);
    i++;
  }
  fclose(arq);
  return aux;
}

void escreve(FILE *arq, int qnt, int *vet, char q){ 
  arq = abrir(q);
  for(int i = 0; i < qnt; i++) {
    fprintf(arq, "%d\n", vet[i]);
  }
  fclose(arq);
}

void mostraVetor(FILE *arq, int qnt, char q){
  int *vetor = leVetor(arq, qnt, q);
  for(int i = 0; i < qnt; i++) {
    printf("%d\n", vetor[i]);
  }
  free(vetor);
}