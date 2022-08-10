/*Lista circular*/

#include <stdio.h>

struct itm{
    int pid;
    int carga;
    struct itm *proximo;
} typedef item;

struct{
    item * inicio;
} typedef lista;

void adicionar(lista *p){
    item *novo = (item*)malloc(sizeof(item));
    printf("\nInforme o pid: ");
    scanf("%i", &novo->pid);
    
    printf("\nInforme a carga: ");
    scanf("%i", &novo->carga);
    novo->proximo=p->inicio;
    
    if(p->inicio==NULL){
        p->inicio=novo;
    }else{
        item *aux=p->inicio;
        while(aux->proximo!=novo->proximo && aux->proximo!=NULL){
            aux=aux->proximo;
        }
        aux->proximo=novo;
    }
}

void listar(lista *p){
    if(p->inicio==NULL){
        printf("\nLista vazia!!");
    }else {
        item *aux=p->inicio;
        do{
            printf("\npid=%i carga=%i proximo=%x", aux->pid, aux->carga, aux->proximo);
            aux=aux->proximo;
        } 
        while(aux!=p->inicio);
    }
}

void processar(lista *p){
    printf("\n==========Processar==========");
    
    if(p->inicio==NULL){
        printf("\nLista vazia!!");
    }else {
        item *aux = p->inicio;
        item *proximo;
        while(p->inicio!=NULL){
            aux->carga--;
            printf("\npid=%i carga=%i", aux->pid, aux->carga);
            proximo = aux->proximo;
            if(aux->carga<=0){
                remover(p, aux->pid);
                listar(p);
            }
            aux=proximo;
        }
    }
}

void remover(lista *p, int pid){
    if(p->inicio==NULL){
        printf("\nLista vazia remover");
    }else {
        item *aux = p->inicio;
        item *penultimo;
        do{
            if(aux->pid==pid){
                if(aux==p->inicio){
                    if(p->inicio==aux->proximo){
                        p->inicio==NULL;
                }else{
                    p->inicio=aux->proximo;
                }
            }else{
                penultimo->proximo=aux->proximo;
            }
            free(aux);
            printf("\npid removido %i", pid);
            break;
        }
            penultimo=aux;
            aux=aux->proximo;
        }
        while(aux!=p->inicio);
    }
}

int main()
{
    lista l1={NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    
    listar(&l1);
    processar(&l1);


    return 0;
}
