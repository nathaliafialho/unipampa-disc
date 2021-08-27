#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *abrir(char arq);
void numeros(FILE *arq, int qnt);
int* leVetor(FILE *arq, int qnt, char q);
void escreve(FILE *arq, int qnt, int *vet, char q);
void mostraVetor(FILE *arq, int qnt, char q);
double insertion(FILE *arq, int qnt, int *vet);
int quick(int *vetor, int ini, int fim);
double shell(FILE *arq, int qnt, int *vet);
double sortQuick(FILE *arq, int qnt, int *vet);