/*- Crie um programa em C, que contenha uma função recursiva que
receba dois inteiros positivos k e n e calcule k^n. Utilize apenas
multiplicações. O programa principal deve solicitar ao usuário os valores
de k e n e imprimir o resultado da chamada da função*/

#include <stdio.h>
#include <stdlib.h>

int multiplica(int x, int y);

int main (void) {
    int prim,seg;
    int result;  

    printf("\n --- MULTIPLICACAO DE  K * N --- \n");
    printf("\n K:");
    scanf("%d", &prim);
    printf("\n N:");
    scanf("%d", &seg); 

    result = multiplica(prim,seg); 

    printf("\n Resultado: %d \n", result); 
return 0;
}

int multiplica(int x, int y) {
        if (y==0) {
            return 0;
        } else {
            return x + multiplica(x, y-1); 
            // a * b = (a + a + ... + a) = a + (a * (b-1))
        }
}