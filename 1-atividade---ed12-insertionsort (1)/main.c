/*1-Faça um programa que leia 5 numeros inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo de insert sort. 
No final, o programa deve mostrar todos os nomes ordenados*/

#include <stdio.h>
#include <conio.h>

void insertionSort(int *vetor, int tamanho){
	int i=0;
	int j=1;
	int aux=0;
	while(j<tamanho){
	    printf("\nJ=%i",j);
		aux=vetor[j];
		i=j-1;
		while((i>=0)&&(vetor[i]>aux)){
		    printf(" I=%i",i);
			vetor[i+1]=vetor[i];
			i=i-1;
		}
		vetor[i+1]=aux;
		j=j+1;
	}
 }

int main(){
    int num[5];
	for(int i=0;i<5;i++){
	    printf("Insira um número: ");
	    scanf("%i", &num[i]);
	}
	
	int tamanho=sizeof(num)/sizeof(int);
	insertionSort(&num, tamanho);
	for(int x=0;x<tamanho;x++){
	   printf("\nOs números ordenados:\n=>%i", num[x]);    
	}
    return 0;
}

