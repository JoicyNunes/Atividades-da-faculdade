/*insertionSort*/
#include <stdio.h>
#include <conio.h>

void insertionSort(int *v, int tamanho){
    int i=0;
    int j=0;
    int aux = 0;
    
    while(j<tamanho){
        aux=v[j];
        i=j-1;
        while((i>=0)&&(v[i]>aux)){
            printf("\n %i %i", aux, v[i]);
            v[i+1]=v[i];
            i=i-1;
        }
        v[i+1]=aux;
        j=j+1;
    }
}

int main(void){
    int t[5];
    int x;
    for(x=0;x<5;x++){
        printf("Informe um numero %i: ", x);
        scanf("%i", &t[x]);
    }
    insertionSort(&t, 5);
    x=0;
    for(x=0;x<5;x++){
        printf("\n%i", t[x]);
    }
    return 0;
}
