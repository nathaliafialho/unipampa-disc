/*
Crie um programa em C, que contenha uma função recursiva para
encontrar o menor elemento em um vetor. A leitura dos elementos do
vetor e a impressão do menor elemento devem ser feitas no programa
principal.
*/

#include <stdio.h>
#include <stdlib.h>
#define x 5

int menorVet(int num[], int p, int q);

int main (void) {
    int num[x], i; 
    int resultMenor=menorVet(num, x, num[x]); 

    for(i=0;i<x;i++) {
        printf("\n Digite um numero [%d][%d]:", i+1, x);
        scanf("%d", &num[i]); 
    }

    printf("\n Menor numero: %d", resultMenor); 

return 0;
}

int menorVet(int num[], int p, int q) {

    if ( p < 0) {
        return q;  // tiver no fim vai parar
    }
    if ( num[x] < q){ // se o valor atual é menor
     q=num[x]; 
    }

return menorVet(num, p, q); 
}