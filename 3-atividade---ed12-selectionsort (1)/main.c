/*3-Faça um programa que leia 10 numeros e ordene-os pelo tamanho utilizando o algoritmo
da seleção. No final, o algoritmo deve mostrar todos os nomes ordenados.*/

#include <stdio.h>
#include <conio.h>

void selectionSort(int *vetor, int tamanho){
	int i, j, min, aux;
	for(i=0;i<(tamanho-1);i++){
        min = i;
        for(j=(i+1);j<tamanho;j++){
            if(vetor[j]<vetor[min])min=j;
        }
        if(vetor[i]!=vetor[min]){
            aux=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=aux;
        }
    }
}

int main(void){
    int num[10];
	for(int i=0;i<10;i++){
	    printf("Insira um número: ");
	    scanf("%i", &num[i]);
	}
	
	int tamanho=sizeof(num)/sizeof(int);
	selectionSort(&num, tamanho);
	for(int x=0;x<tamanho;x++){
	   printf("\nOs números ordenados:\n=>%i", num[x]);    
	}
    return 0;
}
