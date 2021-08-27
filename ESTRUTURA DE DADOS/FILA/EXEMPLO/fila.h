typedef struct fila Fila; 

Fila *cria();
int filaVazia(Fila *f);
int insere(Fila *f, int v);
int retira (Fila *f);
void liberaFila(Fila *f);
void imprime(Fila *f);