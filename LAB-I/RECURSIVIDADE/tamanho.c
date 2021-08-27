/*
Faça uma função recursiva que permita calcular a média de um vetor de
tamanho N (pode reutilizar a função anterior);
*/

#include <stdio.h>
#define tam 4

int somaVetor(int *vet, int x);
float mediaVet( int *vet, int n, int aux, float soma);

int main (void){
	int vet[tam];
	int i=0, soma=0;
	float media=0; 

		for(i=0;i<tam; i++) {
			printf("\n Digite os valores [%d][%d] :", i+1, tam); 
			scanf("%d", &vet[i]);
		}

	soma = somaVetor(vet, tam-1); 
	media = mediaVet(vet, tam-1, tam, somaVetor(vet,tam-1));

	printf("\n soma dos vetores: %d \n", soma); 
	printf("\n media dos vetores: %.1f \n", media);

return 0;
}

int somaVetor(int *vet, int x) {
	int s=0;

		if(x == 0) {
			return vet[x]; 
		} else {
			return vet[x] + somaVetor(vet, x-1); 
		}
}

float mediaVet( int *vet, int n, int aux, float soma) {
		if(n>0) return soma/aux; // divide a soma pela quantidade de vetores inseridos [tam]
		soma += vet[n];
		return mediaVet(vet, n-1, aux, soma);
}

