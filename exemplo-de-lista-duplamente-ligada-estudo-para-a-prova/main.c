/*Lista duplamente ligada*/
#include <stdio.h>

struct item {
    int codigo;
    char nome[50];
    struct itm *anterior;
    struct itm *proximo;
} typedef pessoa;

struct{
    pessoa *inicio;
} typedef lista;

void inserir(lista *p){
    pessoa *novo = (pessoa*)malloc(sizeof(pessoa));
    printf("\nInforme o codigo: ");
    scanf("%i", &novo->codigo);
    
    printf("\nInforme o nome: ");
    scanf("%s", &novo->nome);
    novo->proximo=NULL;
    
    if(p->inicio==NULL){
        novo->anterior=NULL;
        p->inicio=novo;
    }else {
        pessoa *aux = p->inicio;
        
        while(aux->proximo!=NULL){
            aux=aux->proximo;
        }
        aux->proximo=novo;
        novo->anterior=aux;
        printf("\n aux=%x novo=%x", aux->proximo, novo->anterior);
    }
}

void imprimir(lista *p){
    if(p->inicio==NULL){
        printf("\n Lista vazia!");
    }else {
        pessoa *aux=p->inicio;
        do{
            printf("\nCodigo=%i Nome=%s", aux->codigo, aux->nome);
            aux=aux->proximo;
        }
        while(aux!=NULL);
    }
}

void remover(lista *p, int codigo){
    if(p->inicio==NULL){
        printf("\n Lista vazia!");    
    }else {
        pessoa *aux=p->inicio;
        
        while(aux!=NULL){
            if(aux->codigo == codigo){
                if(aux == p->inicio){
                    p->inicio = aux->proximo;
                }else {
                    pessoa *aux2 = aux->anterior;
                    pessoa *aux3 = aux->proximo;
                    aux2->proximo = aux3;
                    aux3->anterior = aux2;
                }
                free(aux);
                printf("\nCodigo removido %i", codigo);
                break;
            }
            aux = aux->proximo;
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
    
    remover(&l1, 2);
    imprimir(&l1);
    remover(&l1, 3);
    imprimir(&l1);
    inserir(&l1);
    remover(&l1, 1);
    imprimir(&l1);

    return 0;
}
