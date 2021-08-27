#include<stdio.h>
#include<stdlib.h>

typedef struct arv{
	struct arv *esq,*dir;
	int dado,rotacao;
} Arv;

FILE *f;
Arv *Cria(){
	return NULL;
}
Arv *Busca(Arv *Raiz,int valor)
{
    Arv *aux;
    if(Raiz!=NULL)
    {
        if(Raiz->dado==valor)
        {
            return aux=Raiz;
        }
        else
        {
            if(valor<Raiz->dado){
                Busca(Raiz->esq,valor);
            }
            else{
                Busca(Raiz->dir,valor);
            }
        }
    }
}
Arv *Balanceamento(Arv *Raiz)
{
    Arv *aux=NULL,*aux2=NULL;
    if(Raiz!=NULL)
    {
        Balanceamento(Raiz->esq);
        Balanceamento(Raiz->dir);
        if((Raiz->rotacao==2)||(Raiz->rotacao==-2))
        {
            if((Raiz->rotacao>0)&&(Raiz->esq->rotacao>0))
            {
                //Rota��o Direita
                aux = Raiz->esq;
                Raiz->esq = aux->dir;
                aux->dir = Raiz;
                Raiz->rotacao = 0;
                Raiz=aux;
            }
            else
            {
                if((Raiz->rotacao<0)&&(Raiz->dir->rotacao<0))
                {
                    //Rota��o Esquerda
                    aux = Raiz->dir;
                    Raiz->dir = aux->esq;
                    aux->esq = Raiz;
                    Raiz->rotacao = 0;
                    Raiz = aux;
                }
                else
                {
                    //Rota��o Dupla Direita
                    if((Raiz->rotacao>0)&&(Raiz->esq->rotacao<0))
                    {
                        aux=Raiz->esq;
                        aux2=aux->dir;
                        aux->dir=aux2->esq;
                        aux2->esq=aux;
                        Raiz->esq=aux2->dir;
                        aux2->dir=Raiz;
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
                    else
                    {
                        //Rota��o Dupla Esquerda
                        if((Raiz->rotacao<0)&&(Raiz->dir->rotacao>0))
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

void corrigir(Arv *Raiz,int valor)//fator de balanceamento
{
    if(Raiz!=NULL)
    {
            if(valor<Raiz->dado){
                Raiz->rotacao++;

            }
            else{
                Raiz->rotacao--;

            }

    }
}


void Insere(Arv **Raiz,int valor){
	if((*Raiz)==NULL){
		(*Raiz)=(Arv*)malloc(sizeof(Arv));
		(*Raiz)->dado=valor;
		(*Raiz)->esq=NULL;
		(*Raiz)->dir=NULL;
		(*Raiz)->rotacao=0;
	}
	else{
		if(valor<=(*Raiz)->dado){
            (*Raiz)->rotacao++;
			Insere(&(*Raiz)->esq,valor);
		}
		else{
		    (*Raiz)->rotacao--;
			Insere(&(*Raiz)->dir,valor);
		}
	}
}
void Imprime_pre(Arv *Raiz){
	if(Raiz!=NULL){
		printf("<%d>",Raiz->dado);
		Imprime_pre(Raiz->esq);
		Imprime_pre(Raiz->dir);
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
void Liberar(Arv *Raiz)
{
    if(Raiz!=NULL)
    {
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
	    			Raiz=Cria();
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
	    			Insere(&Raiz,valor);
	    			Raiz=Balanceamento(Raiz);
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