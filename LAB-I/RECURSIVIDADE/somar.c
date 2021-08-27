/*
Faça uma função recursiva que permita somar os elementos de um
vetor de inteiros;
*/
#include <stdio.h>
#define tam 4

int somaVetor(int *vet, int x);

int main (){
	int vet[tam];
	int soma=0;

		for(int i=0;i<tam; i++) {
			printf("\n Digite os valores [%d][%d] :", i+1, tam);
			scanf("%d", &vet[i]);
		}

	soma = somaVetor(vet, tam-1); 

	printf("\n %d \n", soma); 

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