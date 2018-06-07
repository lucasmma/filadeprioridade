/*  Aluno1: Lucas Mendonça Macedo Amaral
    Aluno2: Davi Cunha Dupin
    Aluno3:Lucas Verissimo Botelho
    Materia: Estrutura de dados(Marcos F. Caetano)
                                                    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "algoritmo.h"


//assinaturas----------------------------------------------------
t_arvore *alocafila();
int estavazia(t_arvore *ptr);
t_arvore *acharelemento(t_arvore *ptr, int quantidade);
int verificanode(t_arvore *ptr);
void troca(t_arvore *ptr, t_arvore *aux);
void organiza(t_arvore *ptr, int quantidade);
int alocanafila(t_arvore *ptr, int *quantidade, int prioridade, char *nome);
void organizaquandoremove(t_arvore *ptr);
void removerelemento(t_arvore *ptr, int *quantidade);
void destroifila(t_arvore *ptr, int *quantidade);
//endassinaturas-------------------------------------------------
//funcoes--------------------------------------------------------
t_arvore *alocafila(){//cria uma fila de prioridade
    t_arvore *ptr = (t_arvore*)malloc(sizeof(t_arvore));
    if (ptr==NULL){
        return NULL;
    }
    ptr->nome[0]='\0';
    ptr->esquerda=NULL;
    ptr->direita=NULL;
    return ptr;
}// a variavel quantidade tem q ser criada na main e mandada para a funcao aloca quando for alocar

int estavazia(t_arvore *ptr){//verifica se a fila esta vazia
     if((ptr->nome[0]=='\0'&&ptr->direita==NULL&&ptr->esquerda==NULL)||ptr==NULL)
        return 1;
    return 0;
}

t_arvore *acharelemento(t_arvore *ptr, int quantidade){
    t_arvore *aux=ptr;
    if(quantidade==1||quantidade==0){
        return aux;
    }
    int resto=quantidade%2;
    quantidade=(quantidade-resto)/2;
    if(resto==0){
        aux=acharelemento(aux,quantidade);
        aux=aux->esquerda;
        return aux;
    }
    aux=acharelemento(aux,quantidade);
    aux=aux->direita;
    return aux;
}

int verificanode(t_arvore *ptr){
    if(ptr->direita!=NULL)
        return 2;
    else if(ptr->esquerda!=NULL)
        return 1;
}

void troca(t_arvore *ptr, t_arvore *aux){
    int auxprioridade;
    char auxnome[1000];
    auxprioridade=ptr->prioridade;
    strcpy(auxnome, ptr->nome);
    ptr->prioridade=aux->prioridade;
    strcpy(ptr->nome, aux->nome);
    aux->prioridade=auxprioridade;
    strcpy(aux->nome, auxnome);
    return;
}

void organiza(t_arvore *ptr, int quantidade){//adicionar a recursividade para organizar a fila toda
    t_arvore *aux=ptr;
    int quantidadedeno;
    if(quantidade==1||quantidade==0){
        return;
    }
    if(quantidade!=1){
        aux=acharelemento(ptr, quantidade/2);
    }
    quantidadedeno=verificanode(aux);
    if(quantidade>=2){
        if(quantidadedeno==2){
            if((aux->prioridade<aux->esquerda->prioridade)||(aux->prioridade<aux->direita->prioridade)){
                if(aux->esquerda->prioridade>aux->direita->prioridade){
                    troca(aux, aux->esquerda);
                    quantidade=quantidade-2;
                    organiza(ptr, quantidade);
                    return;
                }
                else{
                    troca(aux, aux->direita);
                    quantidade=quantidade-2;
                    organiza(ptr, quantidade);
                    return;
                }
            }
            else{
                return;
            }
        }
        else{
            if(aux->prioridade<aux->esquerda->prioridade){
                troca(aux, aux->esquerda);
                quantidade=quantidade-2;
                organiza(ptr, quantidade);
                return;
            }
            else{
                return;
            }
        }
    }
}

int alocanafila(t_arvore *ptr, int *quantidade, int prioridade, char *nome){
    if(ptr==NULL){
        return 0;
    }
    t_arvore *aux=ptr;
    if(!estavazia(ptr)){
        *quantidade=*quantidade+1;
    }
    aux=acharelemento(ptr, *(quantidade)/2);
    if(!estavazia(aux)){
        if(*(quantidade)%2==0){
            aux->esquerda=(t_arvore*) malloc(sizeof(t_arvore));
            strcpy(aux->esquerda->nome, nome);
            aux->esquerda->prioridade=prioridade;
        }
        else{
            aux->direita=(t_arvore*) malloc(sizeof(t_arvore));
            strcpy(aux->direita->nome, nome);
            aux->direita->prioridade=prioridade;
        }
    }
    else{
        strcpy(aux->nome, nome);
        aux->prioridade=prioridade;
    }
    organiza(ptr, *quantidade);
    return 1;
}

int novazio(t_arvore *ptr){
    if(ptr->esquerda==NULL&&ptr->direita==NULL)
        return 1;
    return 0;
}

void organizaquandoremove(t_arvore *ptr){
    struct arvore *aux=ptr;
    if(novazio(aux)){
        return;
    }
    int quantidadedeno=verificanode(aux);
    if(quantidadedeno==2){
        if((aux->prioridade<aux->esquerda->prioridade)||(aux->prioridade<aux->direita->prioridade)){
            if(aux->esquerda->prioridade>aux->direita->prioridade){
                troca(aux, aux->esquerda);
                aux=aux->esquerda;
                organizaquandoremove(aux);
                return;
            }
            else{
                troca(aux, aux->direita);
                aux=aux->direita;
                organizaquandoremove(aux);
                return;
            }
        }
        else{
            return;
        }
    }
    else{
        if(aux->prioridade<aux->esquerda->prioridade){
            troca(aux, aux->esquerda);
            aux=aux->esquerda;
            organizaquandoremove(aux);
            return;
        }
    }
}

void removerelemento(t_arvore *ptr, int *quantidade){
    t_arvore *aux;
    printf("%s\n", ptr->nome);
    aux=acharelemento(ptr, *quantidade);
    troca(ptr, aux);
    aux=acharelemento(ptr, *(quantidade)/2);
    if(*(quantidade)%2==0){
        free(aux->esquerda);
        aux->esquerda=NULL;
    }
    else{
        free(aux->direita);
        aux->direita=NULL;
    }
    if(estavazia(ptr)){
        return;
    }
    *quantidade=*quantidade-1;
    organizaquandoremove(ptr);
    return;
}

void destroifila(t_arvore *ptr, int *quantidade){
    while(*quantidade>1){
        removerelemento(ptr, quantidade);
    }
    free(ptr);
    return;
}
//endfuncoes-----------------------------------------------------
