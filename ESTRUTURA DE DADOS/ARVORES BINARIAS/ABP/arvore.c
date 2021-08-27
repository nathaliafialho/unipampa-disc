#include "arvore.h"

struct arvore{
	int n;
	struct arvore *esq;
	struct arvore *dir;
};

arv cria(){
	printf("arvore criada com sucesso! \n");
	return NULL;
}

int vazia(arv a){
	if(a==NULL){
        return 0;
    } else{
        return 1;
    }
}

int dados(){
	int num;
	printf("valor: ");
    scanf("%d",&num);
	return num;
}


arv insere(arv a,int num){
	if(vazia(a)==0){
		a=(arv)malloc(sizeof(arv));
        a->dir=NULL;
        a->esq=NULL;
        a->n=num;
    
    return a;
	}else {
		if(num==a->n){
			printf("numero já existe\n");
		} else if(num<a->n) {
			a->esq=insere(a->esq,num);
		}else{
			a->dir=insere(a->dir,num);
		}
	}
return a;
}

void busca(arv a,int num){
	if(vazia(a)!=0){
        if(num==a->n){
            printf("%d encontrado\n",num);
        }else if(num<a->n){
                busca(a->esq,num);
        }else if(num>a->n){
                busca(a->dir,num);
        }else {
            return 0;
        }
    }
}

int altura(arv a){
	if(a==NULL)return -1;
	else {
		int e=altura(a->esq);
		int d=altura(a->dir);
			if(e<d){
				return d+1;
			}else{ 
				return e+1;
			}
	}
}

arv exclui(arv a,int v){
	if(a==NULL)return a;
	else if(v<a->n){
		a->esq=exclui(a->esq,v);
	}else if(v>a->n){
		a->dir=exclui(a->dir,v);
	}else{
		if(a->dir==NULL&&a->esq==NULL){
			free(a);
			a=NULL;	
		}else if(a->esq==NULL){
			arv b=a;
			a=a->dir;
			free(b);
		}else if(a->dir==NULL){
			arv b=a;
			a=a->esq;
			free(b);
		}else{
			arv b=a->dir;
			a->n=b->n;
			a->dir=exclui(a->dir,b->n);
		}
	}return a;
}
void preEsq(arv a){
	if(vazia(a)!=0){
		printf("<");
		printf("%d",a->n);
		preEsq(a->esq);
		preEsq(a->dir);
		printf(">");
	}
}
void centro_esq(arv a){
	if(a!=NULL){
		centro_esq(a->esq);
		printf("%d, ",a->n);
		centro_esq(a->dir);
	}
}
void posfEsq(arv a){
	if(a!=NULL){ 
		posfEsq(a->esq);
		posfEsq(a->dir);
		printf("%d, ",a->n);
    }

}
arv libera(arv a){
	if(vazia(a)!=0){
		libera(a->esq);
		libera(a->dir);
		free(a);
	}return NULL;
}