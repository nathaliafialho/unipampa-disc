/*Faça uma função recursiva que receba um número inteiro positivo par N
e imprima todos os números pares de 0 até N em ordem decrescente.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int par(int n);

int main() {
    int numero; 

    printf("digite um numero:");
    scanf("%d", &numero); 

    par(numero);
    printf("\n\n"); 
return 0; 
}

int par(int n) {
    if(n==0) return 0;

    if(n%2 == 0) printf("\n %d", n); 

    par(n-1); 
}