# Grafos BFS 

Implemente todas as funções básicas de busca em um grafo BFS.
  - Criação do grafo.
  - Inserção de arestas.
  - Busca BFS.
  - Impressão dos resultados.
  - Sair.

         struct grafo{
            int v; //número de vértices
            int matriz[][]; //matriz de adjacência
          };
        typedef struct gafo Grafo;

        struct resultado{
          int *cor;
          int *predecessor;
          int *distancia;
        };
        typedef struct resultado Resultado;

 Use matriz ou lista de adjacências e crie uma versão para a busca.
