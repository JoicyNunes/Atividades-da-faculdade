/*Arvore binaria*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *esq;
    struct _no *dir;
}no;

typedef struct{
    no *raiz;
}arvore;

void inserir(arvore *a, int v){
    no *novo=(no*)malloc(sizeof(no));
    novo->info=v;
    novo->dir=NULL;
    novo->esq=NULL;
    
    printf("\nAdiconando %i %x", v, novo);
    
    if(a->raiz == NULL){
        a->raiz=novo;
    }else {
        no *aux = a->raiz;
        while(aux!=NULL){
            if(novo->info > aux->info){
                printf("->");
                if(aux->dir==NULL){
                    aux->dir=novo;
                    break;
                }else{
                    aux=aux->dir;
                }
            }else {
                printf("<-");
                if(aux->esq==NULL){
                    aux->esq=novo;
                    break;
                }else {
                    aux = aux->esq;
                }
            }
        }
    }
}

no* criarItem(int v){
    no *novo=(no*)malloc(sizeof(no));
    novo->info=v;
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

void inserirRecursivo(no *n, no *novo){
    if(n==NULL){
        printf("\nAdiconando Recursivo %i %x", novo->info, novo);
    }else {
        if(novo->info > n->info){
            inserirRecursivo(n->dir, novo);
        }else {
            inserirRecursivo(n->esq, novo);
        }   
    }
}

void remover(arvore *a, int valor){
    printf("\nRemovendo %i", valor);
    if(a->raiz==NULL){
        printf("Arvore vazio !!");
    } else {
        no *aux=a->raiz;
        no *anterior = NULL;
        while(aux!=NULL){
            if(valor==aux->info){
                printf("item removido!");
                free(aux);
                break;
            }else {
                anterior = aux;
                if(valor > aux->info){
                    printf("->");
                    aux=aux->dir;
                }else {
                    printf("<-");
                    aux=aux->esq;
                }
            }
        }
        if(anterior!=NULL && valor > anterior->info){
            anterior->dir = NULL;
        }else{
            anterior->esq=NULL;
        }
    }
}

int altura(no *item){
    if(item==NULL){
        return 0;
    }else {
        if(item->esq!=NULL)return altura(item->esq)+1;
        if(item->dir!=NULL)return altura(item->dir)+1;
    }
}

void listar(no *item){
    if(item != NULL){
        printf("\n %i %x", item->info, item);
        if(item->esq!=NULL)listar(item->esq);
        if(item->esq!=NULL)listar(item->dir);
    }
}

int main()
{
    arvore a = {NULL};
    
    inserir(&a, 50);
    inserir(&a, 30);
    inserir(&a, 90);
    inserir(&a, 20);
    inserir(&a, 40);
    inserir(&a, 95);
    inserir(&a, 10);
    inserir(&a, 35);
    inserir(&a, 45);
    
    listar(a.raiz);
    
    int h = altura(a.raiz);
    printf("\n Total de niveis: %i", h);
   
    remover(&a, 10);
    remover(&a, 45);
    remover(&a, 50);
    
    return 0;
}
