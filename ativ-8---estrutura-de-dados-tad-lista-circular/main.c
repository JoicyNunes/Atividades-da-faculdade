/*
Lista circular

1-Implemente uma lista circular que represente o gerenciamento de processamento de um sistema operacional, além das funções para adicionar, remover e listar, implemente uma função chamada de processar, que fara um laço enquanto tiver elementos na lista e deduzira -1 do atributo carga do TAD processo, quando carga for igual a 0 chame o metodo para remover o item da lista. Removendo todos os processos da lista encerre o laço

 

typedef struct processo {


  int pid;

  int carga;

  struct processo *prox;

} Processo;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
  int pid;
  int num;
  int carga;
  struct processo *prox;
} Processo;

struct {
    Processo *inicio;
    Processo *ultimo;
} typedef lista;

void adicionar(lista *p){
    int aux;
    int num;
    Processo *novo = (Processo*)malloc(sizeof(Processo)); 
    printf("\nInforme um numero:");
    scanf("%i", &novo->num);
    printf("\nInforme um numero para PID:");
    scanf("%i", &novo->pid);
    printf("\nInforme um numero para proximo:");
    scanf("%i", &novo->prox);
    novo->prox = p->inicio;
    if(p->inicio==NULL){
        p->inicio = novo;
        novo->prox = novo;
    } else {
        Processo *aux = p->inicio;
        while(aux->prox != p->inicio){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void listar(lista *p){
    
    if(p->inicio == NULL){
        printf("Lista Vazia!!!\n");

    }
    
    else {
      
        Processo *aux = p->inicio;
        while(aux != NULL){
            printf("\n PID=%i Carga=%i, Proximo=%i", aux->pid, aux->carga, aux->prox);
            aux = aux->prox;
        }
        
    }
}

void processar(lista *p){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else{
        Processo *aux = p->inicio;
        Processo *prox = p->inicio;
        do{
            printf("PID=%i, carga=%i, Proximo=%i \n",aux->pid, aux->carga, aux->prox);
            aux->carga = aux->carga - 1;
            prox = aux->prox;
            if(aux->carga=NULL) {
                remover(listar, aux->pid);
                aux = prox;    
            }
            
        } while(p->inicio != NULL);
    }
}


void remover(lista *p, int pid){
	printf("remover %i \n", pid);
	if(p->inicio == NULL){
		printf("Lista Vazia !!! /n");
	} else {
		Processo *aux = p->inicio;
		Processo *ant = p->inicio;

		if(pid == p->inicio->pid){
			if(p->inicio != p->inicio->prox){
				p->ultimo->prox = p->inicio->prox;
			} else {
				p->inicio = NULL;
			}
			printf("Item removido %x, PID=%i, carga=%i \n", aux, aux->pid, aux->carga);	
			free(aux);
		} else {
			while(aux != p->ultimo){
				if(pid == aux->pid){
					ant->prox = aux->prox;
					printf("Item removido %x, PID=%i, carga=%i \n", aux, aux->pid, aux->carga);	
					free(aux);
					break;
				}
				ant = aux;
				aux = aux->prox;	
			}	
			if(pid == aux->pid){
				ant->prox = aux->prox;
				printf("Item removido  %x, PID=%i, carga=%i \n", aux, aux->pid, aux->carga);	
				free(aux);
			}
		}
	}
}



int main()
{
    lista  l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    processar(&l1);
    listar(&l1);
    remover(&l1, 1);
    processar(&l1);
    listar(&l1);
    remover(&l1, 2);
    
    
    
    
    return 0;
}


