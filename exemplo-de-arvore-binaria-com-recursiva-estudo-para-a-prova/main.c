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

no* inserirRecursivo(no *n, int v){
    if(n==NULL){
        n = criarItem(v);
        printf("\nAdiconando Recursivo %i %x", v, n);
    }else {
        if(v > n->info){
            printf("->");
            n->dir = inserirRecursivo(n->dir, v);
        }else {
            printf("<-");
            n->esq = inserirRecursivo(n->esq, v);
        }   
    }
    return n;
}

no* removerRecursivo(no *n, int v){
    if(n==NULL){
        printf("\nArvore vazio !!");
        return NULL;
    }else {
        if(n->info==v){
            printf("\nitem removido %i!", v);
            free(n);
            return NULL;
        }else {
            if(v > n->info){
                printf("->");
                n->dir = removerRecursivo(n->dir, v);
            }else {
                printf("<-");
                n->esq = removerRecursivo(n->esq, v);
            }
        }
    }
}

void listar(no *item){
    if(item != NULL){
        printf("\n %i %x", item->info, item);
        if(item->esq!=NULL)listar(item->esq);
        if(item->esq!=NULL)listar(item->dir);
    }
}

void pesquisar(no *item, int v){
    if(item!=NULL){
        if(v==item->info){
            printf("\nACHEI! %i %x", item->info, item);
        }else {
            if(item->esq!=NULL){
                printf("<-");
                pesquisar(item->esq, v);
            }
            if(item->esq!=NULL){
                printf("->");
                pesquisar(item->dir, v);
            }
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

int contar(no *item){
    if(item==NULL){
        return 0;
    }else{
        return 1 + contar(item->esq)+contar(item->dir);
    }
}

int maior(no *item){
    if(item->dir==NULL){
        return item->info;
    }else {
        printf("->");
        return maior(item->dir);
    }
}

int menor(no *item){
    if(item->esq==NULL){
        return item->info;
    }else {
        printf("<-");
        return menor(item->esq);
    }
}

int main()
{
    arvore a = {criarItem(50)};
    
    inserirRecursivo(a.raiz, 30);
    inserirRecursivo(a.raiz, 90);
    inserirRecursivo(a.raiz, 20);
    inserirRecursivo(a.raiz, 40);
    inserirRecursivo(a.raiz, 95);
    inserirRecursivo(a.raiz, 10);
    inserirRecursivo(a.raiz, 35);
    inserirRecursivo(a.raiz, 45);
    
    int x = contar(a.raiz);
    printf("\nTotal de elementos: %i \n", x);
    
    int m = maior(a.raiz);
    printf("\nMaior elemento: %i \n", m);
    
    int m2 = menor(a.raiz);
    printf("\nMenor elemento %i \n", m2);
    
    printf("\n=====Listar=====");
    listar(a.raiz);
    
    printf("\n=====Pesquisar=====\n");
    pesquisar(a.raiz, 213);
    
    printf("\n=====Pesquisar=====\n");
    pesquisar(a.raiz, 40);
   
    printf("\n======Remover=====\n");
    removerRecursivo(a.raiz, 10);
    removerRecursivo(a.raiz, 199);
    removerRecursivo(a.raiz, 45);
    removerRecursivo(a.raiz, 50);
    
    return 0;
}
