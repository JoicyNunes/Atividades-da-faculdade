/******************************************************************************
4-Crie uma função para listar o menor valor para minimo de todas as ocorrencias 
e o maior valor para o maximo de todas as ocorrencias
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct itm {
    int min,max;
    struct itm *proximo;
} typedef item;

struct {
    item *inicio;
} typedef lista;

void adicionar(lista *p){
    int aux;
    item *novo = (item*)malloc(sizeof(item));
    printf("\nInforme um valor:");
    scanf("%i",&novo ->min);
    
    printf("\nInforme um valor:");
    scanf("%i",&novo ->max);
    
    if(novo->min > novo->max){
        aux = novo->max;
        novo->max = novo->min;
        novo->min = novo->max;
    } 
    
    novo->proximo = NULL;
    
    if(p->inicio==NULL){
        p->inicio=novo;
    }
    
    else {
        item *aux = p->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void listar(lista *p){
    if(p->inicio == NULL){
        printf("Lista Vazia!!!\n");

    }
    
    else {
        item *aux = p->inicio;
        while(aux != NULL){
            printf("\nminimo=%i maximo=%i", aux->min, aux->max);
            aux = aux->proximo;
        }
        
    }
}

int main()
{
    lista l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    listar(&l1);
    
    return 0;
}