#include "info_bfs.h"

int main (){
  int op, vertices, aux_vert, aux; 
  Grafo *graf; 
  Resultado *result; 
  
  do {
    printf("\n----- GRAFOS BFS -----\n");
    printf(" 1. Criar Grafo:\n");
    printf(" 2. Inserir arestas:\n");
    printf(" 3. Busca BFS:\n");
    printf(" 4. Resultados:\n");
    printf(" 0. Sair:\n");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    switch(op) {
      case 1:
      // Criar grafo 
      printf("\nNumero de vertices:\n");
      scanf("%d", &vertices);
      graf = cria_grafo(vertices);
      printf("\nGrafo criando com sucesso!!\n");
      break;
      case 2:
      // Inserir arestas 
      printf("\nInforme origem e destino da aresta:");
      scanf("%d", &vertices);
      scanf("%d", &aux_vert);
      insereAresta(graf, vertices, aux_vert);
      printf("\nAresta inserida com sucesso!!\n");
      break;
      case 3:
      // Busca BFS
      printf("\nInforme a origem da busca:\n");
      scanf("%d", &vertices);
      result = bfs(graf, vertices);
      imprime_bfs(graf, result);
      break;
      case 4:
      // Imprimir grafo
      printf("\n 1 - Matriz de adjacencia");
      printf("\n 2- Lista de adjacencia\n");
      scanf("%d", &aux);
      if (aux == 1) {
          imprimeMatriz(graf);
      } else if (aux == 2) {
        imprimeListaAdj(graf);
      }
      break;
      case 0:
      // Sair
      printf("\nSaindo..");
      exit(0);
      break;
      default:
      printf("\nERRO! Digite uma opção válida!\n");
      exit(0);
      break;
    }
  } while (op != 0);
return 0;
}
