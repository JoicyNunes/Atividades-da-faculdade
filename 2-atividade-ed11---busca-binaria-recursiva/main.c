/*2-Crie um algoritmo de busca binária, usando recursão*/

#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int c, int *v, int inicio, int fim){
    int meio = (inicio + fim)/2;
    printf("meio=%i\n", meio);
    if(inicio > fim){
        return - 1;
    }else if(v[meio] == c){ 
        return meio;
    }else if (v[meio] < c){ 
        return buscaBinaria(c, v, meio + 1, fim);
    }else{
        return buscaBinaria(c, v, inicio, meio - 1);
    }
}

int compInt(int c, int b)
{
	if (c < b)
		return -1;
	else if (c > b)
		return 1;
	else
	return 0;
}

int main() {
    int t[] = {2,4,5,7,9,11,16,27,42,45,50};
    int tamanho =  sizeof(t)/sizeof(int);
    int inicio = 0;
    int fim = tamanho - 1;
    int pos = buscaBinaria(45, t, inicio, fim);
    
    if (pos==-1) {
		printf("nao encontrado !");
	} else {
		printf("Pos=%i, valor=%i \n", pos, t[pos]);
	}
	return 0;
}

