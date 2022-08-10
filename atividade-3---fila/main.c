#include <stdio.h>
#include <stdlib.h>

struct conta{
    char nome[50];
    int agencia;
    int conta;
    float saldo;
    struct conta *proximo;
} typedef cliente;

struct{
    cliente *primeiro;
} typedef fila;

int filaVazia(fila *f){
    if(f->primeiro == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void colocarFila(fila *f){
    cliente *novo = (cliente*)malloc(sizeof(cliente));
    printf("\nNome do cliente: ");
    scanf("%s", novo->nome);
    printf("Numero da agencia do cliente: ");
    scanf("%i", &novo->agencia);
    printf("Numero da conta do cliente: ");
    scanf("%i", &novo->conta);
    printf("Saldo do cliente: ");
    scanf("%f", &novo->saldo);
    novo->proximo = NULL;
    //Se a fila estiver vazia a pessoa sera a primeira
    if(f->primeiro==NULL){
        f->primeiro = novo; 
        printf("\nPrimeiro cliente da fila!\n");
    } 
    else {
        cliente *aux = f->primeiro;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void listarFila(fila *f){
         if(filaVazia(f)){
        printf("\nFila esta vazia!");
    } 
    else {
        cliente *aux = f->primeiro;
        while(aux != NULL){
            printf("\nCliente: %s\nAgencia: %i Conta: %i Saldo: R$%.2f\n", aux->nome, aux->agencia, aux->conta, aux->saldo);
            aux = aux->proximo;
        }
    } 
}

void removerFila(fila *f){
    printf("\nCliente saiu da fila");
        cliente *aux = f->primeiro->proximo;
        free(f->primeiro);
        f->primeiro = aux;
        printf("\nCliente %s eh o primeiro da fila!\n", aux->nome);
    
}

int main()
{
    fila f = {NULL};
    colocarFila(&f);
    colocarFila(&f);
    colocarFila(&f);
    listarFila(&f);
    removerFila(&f);
    listarFila(&f);
    colocarFila(&f);
    listarFila(&f);
    removerFila(&f);
    removerFila(&f);
    removerFila(&f);
    listarFila(&f);
    
    return 0;
}