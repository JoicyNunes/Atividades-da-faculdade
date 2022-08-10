/*1-Reescreva o algoritmo de busca sequencial usando recursão*/

#include <stdio.h>
#include <stdlib.h>

int buscaRecursiva(int x, int n, int v[], int j){
    if(j == n){
        return - 1;
    } else if(v[j] == x){
        return j;
    }else{
        return buscaRecursiva(x, n, v, j + 1);
    }
}

int main(int argc, char *argv[]) {
	int vet[] = {3,5,7,1,27,1,13,6,17,23};
	int n =  sizeof(vet)/sizeof(int);
	int j = 0;
	int pos = buscaRecursiva(23,n,vet, j);
	if(pos==-1){
		printf("nao encontrado !");
	} else {
		printf("Pos=%i, valor=%i \n", pos, vet[pos]);
	}
	return 0;
}


