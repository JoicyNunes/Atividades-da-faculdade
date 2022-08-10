/*Lista simplismente ligada*/

#include <stdio.h>

struct itm {
    int min;
    int max;
    struct itm *prox;
} typedef item;

struct {
    item *inic;    
} typedef lista;

void inserir(lista *p){
    
    printf("\n===Adiconar===");
    
    item *novo = (item*)malloc(sizeof(item));
    printf("\nInforma um valor minimo e maximo: ");
    scanf("%i %i", &novo->min, &novo->max);
    novo->prox = NULL;
    
    if(p->inic==NULL){
        p->inic = novo;
    }else {
        item *aux = p->inic;
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox=novo;
    }
}

void imprimir(lista *p){
    
    printf("\n==Lista===");
    
    if(p->inic==NULL){
        printf("\nLista Vazia!");
    }else {
        item *aux = p->inic;
        while(aux!=NULL){
            printf("\n %x minimo=%i e maximo=%i", aux, aux->min, aux->max);
            aux= aux->prox;
        }
    }
}

void limites(lista *p){
    int varMin, varMax;
    printf("\n===Limites===");
    
    if(p->inic==NULL){
        printf("\nLista Vazia!");
    }else {
        item *aux = p->inic;
        varMax = aux->max;
        varMin = aux->min;
        while(aux!=NULL){
            if(aux->max > varMax) varMax=aux->max;
            if(aux->min > varMin) varMin=aux->min;
            aux= aux->prox;
        }
             printf("\n %x minimo=%i e maximo=%i",varMin, varMax);
    }
}

void remover(lista *p, int valor){
    
    printf("\n==Remover===");
    
    if(p->inic==NULL){
        printf("\nLista Vazia!");
    }else {
        item *aux = p->inic;
        item *penultimo;
        
        while(aux!=NULL){
            if(aux->min == valor){
                if(aux == p->inic){
                    p->inic=aux->prox;
                }else{
                    penultimo->prox=aux->prox;
                }
                free(aux);
                printf("\n Numero removido %i", valor);
                break;
            }
            penultimo=aux;
            aux=aux->prox;
        }
    }
}

int main()
{
    lista l1 = {NULL};
    
    inserir(&l1);
    inserir(&l1);
    inserir(&l1);
    
    imprimir(&l1);
    limites(&l1);
    remover(&l1, 2);
    imprimir(&l1);
    remover(&l1, 3);
    imprimir(&l1);
    inserir(&l1);
    remover(&l1, 1);
    imprimir(&l1);
    
    return 0;
}
