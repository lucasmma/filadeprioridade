/*  Aluno1: Lucas Mendonça Macedo Amaral
    Aluno2: Davi Cunha Dupin
    Aluno3:Lucas Verissimo Botelho
    Materia: Estrutura de dados(Marcos F. Caetano)
                                                    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "algoritmo.h"






//funcoes-------------------------------------------------
/*void menu(){
    printf("1-Adicionar na Fila\n");
    printf("2-Chamar o proximo da fila\n");
    printf("3-Sair");
}
*/
int main(){
    t_arvore *ptr;
    int quantidade=1;
    ptr=alocafila();
    alocanafila(ptr, &quantidade, 8, "Lucas");
    alocanafila(ptr, &quantidade, 10, "Mateus");
    alocanafila(ptr, &quantidade, 70, "Davi");
    alocanafila(ptr, &quantidade, 100, "pedro");
    alocanafila(ptr, &quantidade, 1000, "lucas");
    alocanafila(ptr, &quantidade, 2, "mel");
    proximodafila(ptr, &quantidade);
    proximodafila(ptr, &quantidade);
    proximodafila(ptr, &quantidade);
    proximodafila(ptr, &quantidade);
    proximodafila(ptr, &quantidade);
    proximodafila(ptr, &quantidade);
    destroifila(ptr, &quantidade);
    return 0;
}
