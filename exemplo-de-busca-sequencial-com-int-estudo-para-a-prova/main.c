/*Busca Sequencial*/

#include <stdio.h>
#include <stdlib.h>

int compInt(int c, int b){
    if(c < b) 
        return -1;
    else if(c > b) 
        return 1;
    else 
        return 0;
}

int buscaInt(int c, int n, int *v){
    int meio, cmp, ini=0;
    int fim=n-1;
    
    while(ini<=fim){
        meio=(ini+fim)/2;
        cmp=compInt(c,v[meio]);
        if(cmp<0){
            fim=meio-1;
        }else {
            if(cmp>0){
                ini=meio+1;
            }else {
                return meio;
            }
        }
    }
    return -1;
}

int buscaIntR(int c, int n, int *v, int ini, int fim){
    int meio, cmp;
    if(ini>fim){
        return -1;
    }else {
        meio=(ini+fim)/2;
        cmp=compInt(c,v[meio]);
        if(cmp<0){
            fim=meio-1;
            buscaIntR(c, n, v, ini, fim);
        }else {
            if(cmp>0){
                ini=meio+1;
                buscaIntR(c, n, v, ini, fim);
            }else {
                return meio;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int t[] = {2,4,5,7,9,11,16,27,42,45,50};
    int tamanho = sizeof(t)/sizeof(int);
    
    int pos = buscaInt(45,tamanho,t);
    if(pos==-1){
        printf("Nao encontrado!");    
    }else {
        printf("Pos=%i, valor=%i \n", pos, t[pos]);
    }
    
    int pos2 = buscaIntR(27, tamanho, t, 0, tamanho-1);
    if(pos2==-1){
        printf("Nao encontrado!");
    }else {
        printf("Pos=%i, valor=%i \n", pos2, t[pos2]);
    }

    return 0;
}
