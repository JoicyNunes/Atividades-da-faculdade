/*bubbleSort*/
#include <stdio.h>
#include <conio.h>

void bubbleSort(char *vetor, int tamanho){
    int i, j;
    char aux;
    
    for(j=tamanho-1;j>=1;j--){
        for(i=0;i<j;i++){
            if(vetor[i]>vetor[i+1]){
                aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}

int main(void){
    char t[] = {"fatec ipiranga"};
    int tamanho = sizeof(t)/sizeof(char);
    printf("\nTamanho=%i", tamanho);
    bubbleSort(&t, tamanho);
    int x=0;
    printf("\nOrdenado!!");
    for(x=0;x<tamanho;x++){
        printf("\n%c", t[x]);
    }
    return 0;
}
