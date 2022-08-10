/*Busca Sequencial*/

#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int x, int n, int v[]){
    int j, p=-1;
    for(j=0;j<n;j++){
        if(x==v[j]){
            p=j;
            break;
        }
    }
    return p;
}

int buscaSequencialR(int x, int n, int v[], int j){
    if(x==v[j]){
        return j;
    }else {
        if(j>=n){
            return -1;
        }else {
            buscaSequencialR(x, n, v, j+1);
        }
    }
}

int main(int argc, char *argv[]){
    int vet[] = {3,5,7,1,27,1,13,6,17,23};
    int n = sizeof(vet)/sizeof(int);
    
    int pos = buscaSequencial(27,n,vet);
    if(pos==-1){
        printf("Nao encontrado!");    
    }else {
        printf("Pos=%i, valor=%i \n", pos, vet[pos]);
    }
    
    int pos2 = buscaSequencialR(27,n,vet,0);
    if(pos2==-1){
        printf("Nao encontrado!");
    }else {
        printf("Pos=%i, valor=%i \n", pos2, vet[pos2]);
    }
    
    pos2= buscaSequencialR(274,n,vet,0);
    if(pos2==-1){
        printf("Nao encontrado!");    
    }else {
        printf("Pos=%i, valor=%i \n", pos2, vet[pos2]);
    }
    
    return 0;
}
