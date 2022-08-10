#include <stdio.h>

int dobro(int N){
 
    if(N == 2)
    return 1;
 
    else
    return 2 * N;
}

int main(){ 
    
int N;

    printf("Informe um número: ");
    scanf("%d",&N);
    
    N = dobro(N);
  
    printf("O dobro é igual a %d", N);
 
    return 0;
}


