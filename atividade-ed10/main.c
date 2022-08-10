/******************************************************************************
Nome: Joicy da Silva Nunes Turma: ADS - 3º semestre noturno.

1-Conte a quantidade total de elementos
2-mostre o maior valor entre todos os itens
3-mostre o menor valor entre todos os itens
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/***************** Arvore.h *********************/

typedef struct _no {
   int info;
   struct _no *esq;
   struct _no *dir;
} no;

typedef struct {
	no *raiz;
} arvore;



/*Cria um no em uma arvore!*/
void inserir (arvore *a, int v){
		    no *novo = (no*)malloc(sizeof(no));
	novo->info = v;
    novo->dir = NULL;
	novo->esq = NULL;   

   printf("\nADICIONANDO %i %x", v, novo);

    if(a->raiz == NULL){
       a->raiz = novo;
    } else {
		no *aux = a->raiz; 
		while(aux!=NULL){
			if(novo->info > aux->info){
				printf("->");
				//direita
				if(aux->dir==NULL){
					aux->dir = novo;
					break;
				} else {
					aux = aux->dir;
				}
			} else {
				printf("<-");
				//esquerda
				if(aux->esq==NULL){
					aux->esq = novo;
					break;
				} else {
					aux = aux->esq;
				}
			}
		}
	}
}


no* criarItem(int v){
	no *novo = (no*)malloc(sizeof(no));
	novo->info = v;
	novo->dir = NULL;
	novo->esq = NULL;   
   	return novo;		
}


/*Cria um no em uma arvore!*/
no* inserirRecursivo(no *n, int v){
   if(n==NULL){
   	   n = criarItem(v);
	   printf("\nADICIONANDO RECURSIVO %i %x", v, n);
   } else {
   		if(v > n->info){
   			printf("->");
   			n->dir = inserirRecursivo(n->dir, v);	
		} else {
			printf("<-");
			n->esq = inserirRecursivo(n->esq, v);
		}		
   }
   return n;
}
 

	
/*Cria um no em uma arvore!*/
no* removerRecursivo(no *n, int v){
	if(n == NULL){
		printf("\nnao encontrei vazia !!");
		return NULL;		
	} else {
		if(n->info==v){
			printf("\nitem removido %i !!", v);
			free(n);
			return NULL;		
		} else {
			if(v > n->info){
	   			printf("->");
	   			n->dir = removerRecursivo(n->dir, v);	
			} else {
				printf("<-");
				n->esq = removerRecursivo(n->esq, v);
			}	
		}
	}
}



void listar(no *item){
	if(item != NULL){
		printf("\n %i %x", item->info, item);
		if(item->esq!=NULL) {
			printf("<-");
			listar(item->esq);
		}	
		if(item->dir!=NULL) {
			printf("->");
			listar(item->dir);	
		}
	}
}

void pesquisar(no *item, int v){
	if(item != NULL){
		if(v == item->info){
			printf("\n ACHEI !!! %i %x", item->info, item);
		} else {
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
	if(item == NULL){
		return 0;
	} else {
		if(item->esq!=NULL) return altura(item->esq)+1;
		if(item->dir!=NULL) return altura(item->dir)+1;
	}
}

int quantidade(no *item){
    if(item == NULL)
    return 0;
    else return 1 + quantidade(item->esq) + quantidade(item->dir);
}

int menor(no *a){
	if(a->esq != NULL){
		return menor(a->esq);
	}else{
		return a->info;
	}
}

int maior(no *a){
	if(a->dir != NULL){
		return maior(a->dir);
	}else{
		return a->info;
	}
}

/****************** Prog.c **********************/

int main () {

arvore a = {criarItem(50)};

inserirRecursivo(a.raiz,30);
inserirRecursivo(a.raiz,90);
inserirRecursivo(a.raiz,20);
inserirRecursivo(a.raiz,40);
inserirRecursivo(a.raiz,95);
inserirRecursivo(a.raiz,10);
inserirRecursivo(a.raiz,35);
inserirRecursivo(a.raiz,45);

int q = quantidade(a.raiz);
printf("\nA quantidade de elementos %i\n=================", q);

int m = menor(a.raiz);
printf("\nO menor elemento %i\n=================", m);

int n = maior(a.raiz);
printf("\nO maior elemento %i\n=================", n);

printf("\nlistar\n=================");
listar(a.raiz);


printf("\npesquisar\n=================");
pesquisar(a.raiz, 213);


printf("\npesquisar\n=================");
pesquisar(a.raiz, 40);

printf("\nremover\n=================");

removerRecursivo(a.raiz, 10);
removerRecursivo(a.raiz, 199);
removerRecursivo(a.raiz, 45);
removerRecursivo(a.raiz, 50);

return 0;


}
