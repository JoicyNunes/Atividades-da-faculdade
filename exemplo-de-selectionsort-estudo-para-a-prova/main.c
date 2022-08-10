/*selectionSort*/
#include <stdio.h>
#include <conio.h>

void selection_Sort(int *v, int tamanho){
    int i, j, min, aux;
    for(i=0;i<(tamanho-1);i++){
        min = i;
        for(j=(i+1);j<tamanho;j++){
            printf("\nv[j]=%i", v[j]);
            if(v[j]<v[min]) min = j;
        }
        if(v[i]!=v[min]){
            aux=v[i];
            v[i]=v[min];
            v[min]=aux;
        }
    }
}

int main(void){
    int t[10];
    int x = 0;
    for(x=0;x<10;x++){
        printf("Informe um numero: ", x);
        scanf("%i", &t[x]);
    }
    selection_Sort(&t, 10);
    x=0;
    for(x=0;x<10;x++){
        printf("\n%i", t[x]);
    }
    return 0;
}