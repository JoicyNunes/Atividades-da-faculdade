/******************************************************************************
3-Escreva um programa de lista encadeada simples que armazene dois valores no 
TAD mínimo e máximo.
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

int main()
{
    lista l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    
    printf("\nValor adicionado!");
    
    return 0;
}