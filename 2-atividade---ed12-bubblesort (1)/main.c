/*2-Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo
algoritmo de buble sort.*/

#include <stdio.h>
#include <string.h>

void bubbleSort(char *vetor, int tamanho){
    int a, b;
    char j;
    for(a=1;a<tamanho;++a)
    for(b=tamanho - 1;b>=a; --b){
        printf("\nA=%i",a);
            if(vetor[b-1]>vetor[b]){
                printf(" B=%i",b);
                j=vetor[b-1];
                vetor[b-1]=vetor[b];
                vetor[b]=j;
            }
    }
}

int main(){
    char letras[27];
    printf("Digite as letras do alfabeto fora de ordem: ");
    scanf("%s",&letras);
    bubbleSort(letras,strlen(letras));
    printf("\nLetras do alfabeto ordenadas:\n=>%s", letras);    
    
    return 0;
}

