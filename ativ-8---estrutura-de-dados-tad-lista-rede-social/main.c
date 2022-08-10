#include <stdio.h>
#include <stdlib.h>

/* 
lista duplamente ligada

2-Implemente uma lista duplamente encadeada para simular uma rede social de pessoas conhecidas, implemente todas as funções



typedef struct pessoa {


  char[30] nome;

  struct pessoa *ant;

  struct pessoa *prox;

} Pessoa;
 */

typedef struct pessoa {
  char nome;
  char nome1;
  struct pessoa *ant;
  struct pessoa *prox;
} Pessoa;

Pessoa *criarListar(){
	Pessoa *lista=(Pessoa*)malloc(sizeof(Pessoa)); 
	lista->prox = NULL;
	return lista;
}

int listaVazia(Pessoa *p)
{
 	if(p->prox==NULL){
 		return 1;	
	} else {
		return 0;
	}
}

void colocarNome(Pessoa *lista)
{
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	printf("Informe o nome do seu amigo: "); 
	scanf("%s", &novo->nome);
	novo->prox = NULL;  
	novo->ant = NULL;  
	
	if(listaVazia(lista)){
		lista->prox = novo;
		novo->ant = lista;	
	} else {
		Pessoa *temp = lista->prox;
		while(temp->prox != NULL){
			temp = temp->prox;
		}
		temp->prox = novo;
		novo->ant = temp;
	}
}


void colocarNome1(Pessoa *lista)
{
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	printf("Informe o nome do proximo amigo: "); 
	scanf("%s", &novo->nome1);
	novo->prox = NULL;  
	novo->ant = lista;	
	
	if(listaVazia(lista)){
		lista->prox = novo;	
	} else {
		
		novo->prox = lista->prox;
		while(novo->prox != NULL){
    		lista->prox->ant = novo;
		}
		lista->prox = novo;
	}
}




void removerLista(Pessoa *lista, char nome)
{
   if(listaVazia(lista)==0){
   		Pessoa *temp = lista->prox; 
		Pessoa *ant = lista; 
		while(temp != NULL){
			if(temp->nome==nome){
				ant->prox = temp->prox;
				temp->prox->ant = ant;
				printf("Voce nao eh mais amigo de %s \n", temp, temp->nome);
				free(temp);
				break;			
			} else {
				ant = temp;
				temp = temp->prox;
			}
		}
   }
}


void exibe(Pessoa *lista)
{
   	Pessoa *temp = lista->prox;
	while(temp != NULL){
		printf("Pessoa %s Ant=%s Prox=%s \n", temp, temp->nome, temp->ant, temp->prox);
		temp = temp->prox;
	}
}
int main() {


	
	Pessoa *lista = criarListar();
	colocarNome(lista);
	colocarNome1(lista);
	colocarNome(lista);
	colocarNome1(lista);
	exibe(lista);
	removerLista(lista,1);
	exibe(lista);
	
	return 0;
}



