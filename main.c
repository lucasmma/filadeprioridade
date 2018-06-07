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
void menu(){
    t_arvore *ptr=alocafila();
    int prioridade,quantidade=1;
    char nome[100];
    int x;
    while(1){
        printf("1-Adicionar na Fila\n");
        printf("2-Chamar o proximo da fila\n");
        printf("3-Sair\n");
        scanf("%d", &x);
        if(x==1){
            printf("Digite o nome; ");
            scanf("%s", nome);
            printf("Digite a prioridade: ");
            scanf("%d", &prioridade);
            alocanafila(ptr, &quantidade, prioridade, nome);
        }
        else if(x==2){
            proximodafila(ptr, &quantidade);
        }
        else if(x==3){
            destroifila(ptr, &quantidade);
            return;
        }
    }
}

int main(){
    menu();
    return 0;
}
