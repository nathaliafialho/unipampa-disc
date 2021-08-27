#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qntBanda 5
typedef enum gen {
    pagode=1, rock=2, rap=3, mpb=4
} genero;

typedef struct banda { 
    int integrantes, ranking;
    char nome[51];
    genero gen; 
} Banda;


void verificaFavorito(Banda **b, int tam);
void inicializaBanda(int tam, Banda **b);
void insereBandas(Banda **b, int tam);
void imprime(Banda **b, int tam);
void pesquisaRanking(Banda **b, int tam);
void pesquisaGenero(Banda **b, int tam);

int main () {
    Banda *band[qntBanda];
     int op;

    do {
        printf("\n ---------- MENU ---------- \n");
        printf("1- Inserir banda:\n");
        printf("2- Mostrar dados inseridos:\n");
        printf("3- Buscar pelo ranking: \n");
        printf("4- Buscar pelo genero musical:\n");
        printf("5- Verificar se a banda escolhida está no ranking:\n");
        printf("0- Sair\n\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                insereBandas(band, qntBanda);
            break;

            case 2:
                imprime(band, qntBanda);
            break;

            case 3:
                pesquisaRanking(band, qntBanda);
            break;

            case 4:
                pesquisaGenero(band, qntBanda);
            break;

            case 5:
               verificaFavorito(band,qntBanda);
            break;

            case 0:
                printf("saindo..");
                exit(0);
            break;
            
            default:
                printf("ERRO! Digite uma opção válida!");
                exit(0);
            break;
        }
    } while(op!=0); 
    return 0;
}

/* inicializa vetor de bandas com NULL - vazio*/
void inicializaBanda(int tam, Banda **b) {
    for(int i=0;i<tam;i++){
        b[i]=NULL;
    }    
}

/* funcao para inserer bandas */
void insereBandas(Banda **b, int tam){
        for(int i=0;i<tam;i++){
            if(i < 0 || i >= tam){
                printf("erro de alocacao");
            } else {
                b[i]= (Banda*)malloc(sizeof(Banda));
                printf("\nDIGITE AS INFORMAÇÕES DA BANDA -> [%d] \n", i+1);
                printf("Digite o nome:");
                scanf("%s", b[i]->nome);
                printf("Digite o genero:\n pagode=1 \n rock=2 \n rap=3 \n mpb=4 \n");
                scanf("%d", &b[i]->gen);
                printf("Numero de integrantes da banda:");
                scanf("%d", &b[i]->integrantes);
                printf("Digite a posicao no ranking:");
                scanf("%d", &b[i]->ranking);
            }
        }   
}

/*imprime as informaçoes das bandas inseridas */
void imprime(Banda **b, int tam){
        for(int i=0;i<tam;i++){
            printf("\n\n Mostrando banda [%d]\n", i+1);
            printf("Nome: %s \n",b[i]->nome);
            printf("Numero de Integrantes: %d \n", b[i]->integrantes);
            printf("Posicao do ranking: %d \n", b[i]->ranking);
            printf("Genero:");
                switch (b[i]->gen){
                case pagode:
                    printf("pagode");
                    break;
                case rock:
                    printf("rock");
                    break;
                case rap:
                    printf("rap");
                    break;
                case mpb:
                    printf("mpb");
                    break;
                }
        }
}

/*pesquisa por ranking*/
void pesquisaRanking(Banda **b, int tam){
    int num;
        printf("\n Informe um numero de 1 a 4: ");
        printf("\n\n");
        scanf("%d", &num);

        for(int i=0; i<tam; i++){
            if(b[i]->ranking == num){
                imprime(b, tam);
            }
        }
}

/*pesquisa por genero*/
void pesquisaGenero(Banda **b, int tam){
    int numeroGenero; 
    printf("Digite o numero correspondente ao genero: \n pagode=1 \n rock=2 \n rap=3 \n mpb=4 \n");
    scanf("%d", &numeroGenero);
        for(int i=0; i<tam;i++){
            if(b[i]->gen == numeroGenero){
                imprime(b, tam);
            }
        }
}


/*verifica se a banda está entre as favoritas*/
void verificaFavorito(Banda **b, int tam) {
    char nome1[51];
    int index=0;

    printf("\nNome da banda:\n");
    scanf("%s[^\n]", nome1); 

            for(int i=0;i<tam;i++){
                if(strcasecmp(b[i]->nome, nome1) == 0) {
                        index++; //incrementa se são iguais
                }
            }
    if(index > 0 ) {
        printf("\nbanda favorita!\n\n");
    } else {
        printf("\nbanda não esta entre as favoritas!\n\n");
    }
        
}