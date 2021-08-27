/*
Implementar em C um programa permita realizar as seguintes operações:
1) Criar uma lista encadeada que armazene informações relacionadas a alunos de uma
determinada disciplina, sendo que o tipo aluno deverá conter os seguintes campos: nome,
nota1, nota2 e nota3;
2) Inserir um novo aluno na lista mantendo a lista sempre em ordem alfabética de nome;
3) Buscar um aluno na lista e imprimir suas informações;
4) Remover um aluno na lista (a função receberá o nome do aluno, procurará o mesmo na lista
e removerá o nodo correspondente);
5) Imprimir todos os dados de todos os alunos da lista.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno{
    char nome[10];
    float nota1,nota2,nota3; 
}; 
typedef struct aluno Aluno;
struct dados{
    Aluno pos;
    struct dados *prox;
};
typedef struct dados Dados; 



void ListarTodos(Dados *pontAlunos){
    Dados *p; 
    p= malloc(sizeof(Dados));

    if(pontAlunos == NULL) {
        puts("lista vazia");
    } else {
        for(p=pontAlunos; p!= NULL ; p=p->prox){
            printf("\n nome: %s", p->pos.nome);
            printf("\n nota 1: %f", p->pos.nota1);
            printf("\n nota 2: %f", p->pos.nota2);
            printf("\n nota 3: %f", p->pos.nota3); 
        }
    }
}

int insereOrd (Dados *pontLista, Aluno Dadosaluno){

    Dados *novo; 
    Dados *ant=NULL; 
    Dados *p=pontLista; // pont aux q percorre a lista

    novo = malloc(sizeof(Dados));

    if(!novo) return NULL; 

    novo->pos= Dadosaluno; 

    while ((p!=NULL) && (strcmp(p->pos.nome,Dadosaluno.nome)<0)){
        ant=p;
        p=p->prox;
    }

    if(ant==NULL){
        novo->prox=pontLista;
        pontLista=novo;
    } else {
        novo->prox=ant->prox;
        ant->prox=novo;
    }
}

int excluiAluno (Dados *pontLista, char nome[10]) {
    Dados *ant=NULL; 
    Dados *aux=pontLista;

while(aux!=NULL && (strcmp(aux->pos.nome,nome))){
    ant=aux;
    aux=aux->prox;
}

    if(aux==NULL){
        return pontLista;
    }
    if(ant==NULL){ // remove 1º
        pontLista=aux->prox;
    } else { // remove / ou ->
        ant->prox=aux->prox;
    }
    
    return pontLista;
}


void BuscaAluno(Dados *pontLista, char nome){
    

}


int main (void) {
    int mostraResult, op;
   Aluno al; 
   Dados pontInfo; 
  
    do {

       printf("\n ------------ MENU -----------");
       printf("\n 1 - Inserir alunos."); 
       printf("\n 2 - Exibir alunos.");
       printf("\n 3 - Buscar aluno.");
       printf("\n 4 - Remover aluno da lista.");
       printf("\n 0 - Sair");
       printf("\n DIGITE A OPCAO QUE DESEJA:");
       scanf("%d", &op);

        switch(op){
            case 1:
                printf("\n Nome do aluno:");
                scanf("%s", al.nome); 
                fflush(stdin); 
                printf("\n Nota 1:");
                scanf("%f", &al.nota1 ); 
                printf("\n Nota 2:");
                scanf("%f", &al.nota2);
                printf("\n Nota 3:");
                scanf("%f", &al.nota3);
            mostraResult = insereOrd( &pontInfo, al);
            break;

            case 2:
                printf("\n\n");
                printf("\n INFORMACOES DOS ALUNOS:");
                printf("\n Nome do aluno: %s", al.nome);
                printf("\n Nota 1:", al.nota1);
                printf("\n Nota 2:", al.nota2);
                printf("\n Nota 3:", al.nota3); 

            ListarTodos(&pontInfo);
            break;

            case 3:

                printf("\n");
                printf("Digite o nome do aluno que deseja consultar:");
                scanf("%s", al.nome);

            break;

            case 4:

                printf("\n Digite o nome do aluno que deseja excluir:");
                scanf("%s", al.nome);

             excluiAluno(&pontInfo, al.nome);
            break;

            case 0:
            puts("Saindo..");
            exit(0);
            break;

            default:
            puts("Opcao invalida.");
            break;
        }
    } while (op!=0);
return 0;
}