#include <stdio.h>

int main()
{
    int n, x, soma;
    
    for(n = 1; n<=10000; n++){
    
    soma = 0;

    for(x = 1; x<n; x++){
        if(n%x == 0){
        soma = soma + x;
        }
    }
    if(soma==n){
        printf("%d Perfeito \n", n);
}
}
}