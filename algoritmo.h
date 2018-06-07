/*  Aluno1: Lucas Mendonça Macedo Amaral
    Aluno2: Davi Cunha Dupin
    Aluno3:Lucas Verissimo Botelho
    Materia: Estrutura de dados(Marcos F. Caetano)
                                                    */


typedef struct arvore{
    int prioridade;
    struct arvore *esquerda;
    char nome[100];
    struct arvore *direita;
} t_arvore;



//assinaturas----------------------------------------------------
t_arvore *criaprioridade();
int estavazia(t_arvore *ptr);
t_arvore *percorrefila(t_arvore *ptr, int quantidade);
int verificanode(t_arvore *ptr);
void troca(t_arvore *ptr, t_arvore *aux);
void organiza(t_arvore *ptr, int quantidade);
int alocanafila(t_arvore *ptr, int *quantidade, int prioridade, char *nome);
void organizaquandoremove(t_arvore *ptr);
void proximodafila(t_arvore *ptr, int *quantidade);
void destroifila(t_arvore *ptr, int *quantidade);
//endassinaturas-------------------------------------------------
