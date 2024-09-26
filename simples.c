#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    char nome[50];
    struct no* prox;
} no;

no* criar_no(int valor, char nome[]){
    no* novo_no = (no*)malloc(sizeof(no));
    if (novo_no == NULL){
        printf("erro");
        return NULL;
    }
    novo_no-> valor = valor;
    strcpy(novo_no-> nome, nome);
    novo_no->prox = NULL;
    return novo_no;
}

void imprimir_no(no *cabeca){
    no *temp = cabeca;
    while (temp!=NULL){
        printf("valor: %i \n nome: %s \n",temp -> valor, temp-> nome);
        temp=temp->prox;
    }
}

void inserir_nodo(no **cabeca, int valor, char nome[]){
    no* novo_no = criar_no(valor, nome);
    if(novo_no !=NULL){
    novo_no->prox = *cabeca;
    *cabeca = novo_no;
    }
}






int main(){
    
    no *cabeca = NULL;
    
    inserir_nodo (&cabeca, 25, ("luiz"));
    inserir_nodo (&cabeca, 35, ("gustavo"));
    inserir_nodo (&cabeca, 45, ("italo"));
    
    imprimir_no (cabeca);
    return 0;
}
