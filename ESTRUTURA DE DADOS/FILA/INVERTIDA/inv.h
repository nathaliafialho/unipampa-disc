typedef struct p Tfila;
typedef struct q Fila;
typedef struct t Pilha; 

void criaFilaVazia(Fila *f);
void CriarPilhaVazia(Pilha *p);
int filaVazia(Fila *f);
int pilhaVazia(Pilha*p);
int filaCheia(Fila *f);
int pilhaCheia(Pilha *p);
void enfileirar(Fila *f, Tfila x);
void empilhar(Pilha *p, Tfila x);
void desenfileirar(Fila *f,Tfila x);
void desempilhar(Pilha *p, Tfila x);
void mostraElem(Fila *f);
void inverterFila (Fila *f);
void liberaFila(Fila *f);
void liberaPilha(Pilha *p);