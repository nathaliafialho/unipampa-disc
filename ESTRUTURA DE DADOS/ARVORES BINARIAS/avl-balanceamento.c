#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	struct arv *esq,*dir;
	int dado,rotacao;
} Arv;
FILE *f;

//cria a raiz da arvore AVL com NULL
Arv *Cria(){ 
	return NULL; // inicia raiz como nula 
}

Arv *Busca(Arv *Raiz,int valor) { 
    Arv *aux;
    if(Raiz!=NULL) // se raiz for diferente de NULL
    { 
        if(Raiz->dado==valor) {
            return aux=Raiz; 
                        /*
                        se o valor digitado pelo usuario for igual ao valor da raiz,
                        retorna o ponteiro aux que é o valor da raiz
                        */
        } else { // se for um valor diferente da raiz, entra no else 
            if(valor<Raiz->dado){ 
                Busca(Raiz->esq,valor);
                        /*
                        se o valor digitado pelo usuario for menor que raiz,
                        o ponteiro faz a busca na arvore pelo lado esquerdo
                        */
            }
            else{ 
                Busca(Raiz->dir,valor);
                         /*se o valor digitado pelo usuario for maior que o valor da raiz,
                            o ponteiro faz a busca na arvore pelo lado direito
                        */
            }
        }
    }
}


Arv *Balanceamento(Arv *Raiz) {
    Arv *aux=NULL,*aux2=NULL;
    if(Raiz!=NULL)
    {

        Balanceamento(Raiz->esq); 
        Balanceamento(Raiz->dir);


        if((Raiz->rotacao==2)||(Raiz->rotacao==-2)) // se o fb for 2 ou -2 
        {
            if((Raiz->rotacao>0)&&(Raiz->esq->rotacao>0)) // se fb positivo e subarvore da esquerda tambem tem um fb positivo 
            {
                //Rotacao Direita
                aux = Raiz->esq; // aux é o filho a esquerda da raiz 
                Raiz->esq = aux->dir; // o filho a esquerda da raiz recebe o filha a direita 
                aux->dir = Raiz; // o filho a direita passa a ser a nova raiz da arvore
                Raiz->rotacao = 0;
                Raiz=aux; // a raiz passa a ser quem tiver no nó 
            }
            else 
            {
                if((Raiz->rotacao<0)&&(Raiz->dir->rotacao<0)) // se fb for negativo e subarvore da direita estiver fb negativa
                {
                    //Rotacao Esquerda
                    aux = Raiz->dir; // ponteiro aux vai receber o filho a direita da raiz 
                    Raiz->dir = aux->esq; // o filho a direita aponta p filho a esquerda do nó 
                    aux->esq = Raiz; // o nó da esquerda aponta p raiz
                    Raiz->rotacao = 0;
                    Raiz = aux; // a raiz se torna quem tiver no nó
                }
                else
                {
                    //Rotacao Dupla Direita
                    if((Raiz->rotacao>0)&&(Raiz->esq->rotacao<0)) // se fb positivo e subarvore da esquerda estiver um fb negativo
                    {
                        aux=Raiz->esq; // aux aponta p filho a esquerda da raiz
                        aux2=aux->dir;  // aux2 aponta p filho a direita de aux ->( que aponta p filho a esquerda da raiz)
                        aux->dir=aux2->esq; // acontece a rotação dos nodos
                        aux2->esq=aux; //  aux2 se torna pai de aux 
                        Raiz->esq=aux2->dir; // aux2 passa a ser a raiz da arvore, aux filho a esquerda 
                        aux2->dir=Raiz;   // aux2(atual raiz) passa a ser pai da raiz antiga, que se torna filho a direita de aux2 e aux passa a ser filho a esquerda de aux2 
                        if(aux2->rotacao==-1)
                        {
                            Raiz->rotacao=1;
                        }
                        else
                        {
                            Raiz->rotacao=0;
                        }
                        if(aux2->rotacao==1)
                        {
                            aux->rotacao=-1;
                        }
                        else
                        {
                            aux->rotacao=0;
                        }
                        Raiz=aux2; // aux2 passa a ser a nova raiz 
                    }
                    else
                    {
                        //Rotacao Dupla Esquerda
                        if((Raiz->rotacao<0)&&(Raiz->dir->rotacao>0)) // se fb negativo e subarvore da direita estiver um fb positivo
                        {
                            aux=Raiz->dir;
                            aux2=aux->esq;
                            aux->esq=aux2->dir;
                            aux2->dir=aux;
                            Raiz->dir=aux2->esq;
                            aux2->esq=Raiz;
                            if(aux2->rotacao==-1)
                            {
                                Raiz->rotacao=1;
                            }
                            else
                            {
                                Raiz->rotacao=0;
                            }
                            if(aux2->rotacao==1)
                            {
                                aux->rotacao=-1;
                            }
                            else
                            {
                                aux->rotacao=0;
                            }
                            Raiz=aux2;
                        }
                    }
                }
            }
        }
           return Raiz;
    }
}

void corrigir(Arv *Raiz,int valor) { //fator de balanceamento
        if(Raiz!=NULL) {
                if(valor<Raiz->dado){
                    Raiz->rotacao++;
                }
                else{
                    Raiz->rotacao--;
                }
        }
}


void Insere(Arv **Raiz,int valor){

	if((*Raiz)==NULL){ // arvore vazia ou nó folha
		(*Raiz)=(Arv*)malloc(sizeof(Arv)); // 
		(*Raiz)->dado=valor; // raiz começa a ser o valor inicial digitado 
		(*Raiz)->esq=NULL; // filho a esquerda recebe NULL
		(*Raiz)->dir=NULL; // filho a direita recebe NULL
		(*Raiz)->rotacao=0; 
	}
	else{
		if(valor<=(*Raiz)->dado){ 
            (*Raiz)->rotacao++; 
             // se o valor for menor que o dado faz a inserção a esquerda 
			Insere(&(*Raiz)->esq,valor);
		}
		else{
		    (*Raiz)->rotacao--;
			Insere(&(*Raiz)->dir,valor);
            // se o valor for maior q o dado atual faz a insercao a direita 
		}
	}
}
void Imprime_pre(Arv *Raiz){
	if(Raiz!=NULL){
		printf("<%d>",Raiz->dado); // imprime a raiz
		Imprime_pre(Raiz->esq); // imprime a raiz esquerda  
		Imprime_pre(Raiz->dir); // imprime a raiz direita
	}
}
void Imprime_sim(Arv *Raiz){
	if(Raiz!=NULL){
		Imprime_sim(Raiz->esq);
		printf("<%d>",Raiz->dado);
		Imprime_sim(Raiz->dir);
	}
}
void Imprime_pos(Arv *Raiz){
	if(Raiz!=NULL){
		Imprime_sim(Raiz->esq);
		Imprime_sim(Raiz->dir);
		printf("<%d>",Raiz->dado);
	}
}

int Maior(int a, int b){
    return (a>b) ? a : b;
    /* se a maior que b então retorna a, se nao retorna b 
    */
}

int Altura(Arv *Raiz){
   if(Raiz == NULL)
   {
        return -1;
   }
   else
    {
        return 1 + Maior(Altura(Raiz->esq), Altura(Raiz->dir));

    }
}

void Liberar(Arv *Raiz) {
    if(Raiz!=NULL) {
        /*
        se a raiz for diferente de NULL chama recursivamente
        os nodos a esquerda e direita e libera eles 
        */
        Liberar(Raiz->esq);
        Liberar(Raiz->dir);
        free(Raiz);
    }
}


int main(void){
	int menu,valor,controle=0;
	Arv *Raiz,*aux,*aux2;
	do{
	   	printf("1 - Criar uma arvore\n2 - Inserir um elemento\n3 - Imprimir o conteudo da arvore\n4 - Imprimir a altura da arvore\n5 - Buscar na arvore\n6 - Sair \n ");
	    scanf("%d",&menu);
	    switch(menu){
	    	case 1:{
                if(controle==0){
	    			Raiz=Cria(); // cria arvore 
	    			printf("Arvore criada com sucesso\n");
	    			controle++;
	    		}
	    		else{
	    			printf("J� existe uma arvore criada\n");
	    		}
	    		break;
	    	}
	    	case 2:{
	    		if(controle!=0){
	    			printf("Digite um valor para inserir\n");
	    			scanf("%d",&valor);
	    			Insere(&Raiz,valor); // insere o valor inserido na raiz se raiz==NULL
	    			Raiz=Balanceamento(Raiz); // faz o balanceamento da arvore se fb >= |2|
	    			printf("Valor adicionado com sucesso\n"); 
	    		}
	    		else{
	    			printf("Crie uma arvore primeiro\n");
	    		}
	    		break;
	    	}
	    	case 3:{
	    		if(Raiz!=NULL && controle!=0){ 
	    			printf("Pre ordem= ");
		    		Imprime_pre(Raiz); 
		    		printf("\nSimetrico= ");
	    			Imprime_sim(Raiz);
	    			printf("\nPos ordem= ");
	    			Imprime_pos(Raiz);
	    			printf("\n");
	    		}
	    		else
                {
                    printf("Crie uma arvore primeiro ou adicione uma valor a arvore\n");
                }
	    		break;
	    	}
	    	case 4:{
	    	    if(controle!=0){
                    valor=Altura(Raiz);
                    printf("Altura da arvore igual a %d\n",valor+1);
                }
	    	    else
                {
                    printf("Crie uma arvore primeiro\n");
                }
                break;
            }

            case 5:
                                {
                                    printf("Digite um valor para buscar\n");
                                    scanf("%d",&menu);
                                    if (aux=Busca(Raiz,menu)){
                                    printf("Valor encontrado %d\n",aux->dado);
                                    }else{
                                    printf("Valor inexistente\n");
                                    };
                                    break;
                                }

		    default:{
			    printf("EXIT\n");
		    }
	    }
	}while(menu<5);
	return 0;
}