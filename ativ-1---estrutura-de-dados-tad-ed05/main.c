#include <stdio.h>
#include <stdlib.h>

struct cx{
int codigo;
float peso;
struct cx *proximo; //endereço do proximo item
} typedef caixa;

struct {
caixa *topo;
} typedef pilha;

void push(pilha *p){
printf("\nPUSH");
caixa *novo = (caixa*)malloc(sizeof(caixa));
printf("\nInforme um codigo:");
scanf("%i", &novo->codigo);
printf("\nInforme um peso:");
scanf("%f", &novo->peso);
printf("\n Novo elemento criado end %x", novo);
novo->proximo = p->topo;
p->topo = novo;
}

void pop(pilha *p){
printf("\nPOP");
if(p->topo!=NULL) {
caixa *atual = p->topo->proximo;
printf("-elemento a ser removido %x ,\nproximo elemento %x", p->topo, p->topo->proximo);
free(p->topo);
p->topo = atual;
} else {
printf("-pilha vazia");
}
}

void mostrar(pilha *p){
if(p->topo!=NULL) {
printf("\nTopo da pilha %x, codigo=%i, peso=%f", p->topo,
p->topo->codigo, p->topo->peso);
} else {
printf("\npilha vazia");
}
}

int main()
{
pilha pilha1 = {NULL};

push(&pilha1);
mostrar(&pilha1);
push(&pilha1);
mostrar(&pilha1);
pop(&pilha1);
mostrar(&pilha1);

push(&pilha1);
mostrar(&pilha1);
pop(&pilha1);
mostrar(&pilha1);
pop(&pilha1);
pop(&pilha1);
mostrar(&pilha1);
return 0;
}