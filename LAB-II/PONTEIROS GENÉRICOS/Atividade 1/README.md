# Implementação de Lista encadeada genérica 

Implementar em C uma TAD de lista encadeada genérica com informações do tipo Aluno. A Lista deverá ser implementada como um TAD - tipo abstrato de dados - codificado usando arquivo fonte de header (.h) e arquivo fonte com a implementação das funções definidas no arquivo header (.c).

Deve possuir as seguintes funções: 

 1. Cria lista
 2. Insere na lista (no inicio)
 3. Percorre a lista (considerando as situações de busca, impressão e retirada de elementos)
 4. Verifica se a lista está vazia
 5. Libera a lista (memoria alocada)

Segue a estrutura do tipo de informação Aluno da lista:

      struct aluno {
        int matricula;
        char nome[50];
      }

O programa DEVE possuir um MENU com as seguintes opções:

 1. Inserir aluno;
 2. Buscar aluno (por matricula);
 3. Imprimir alunos;
 4. Retirar aluno
 5. Verifica se a lista está vazia
 6. Sair
 