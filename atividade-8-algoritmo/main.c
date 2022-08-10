//8- Faça um algoritmo que conte de 1 a 100 e a cada múltiplo de 3 e 5 
//simultaneamente emita uma mensagem: “Múltiplo de 3 e 5”.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int x, multi3, multi5;
    
    for(x=1; x<=100; x++){
        
        multi3=x%3;
        
        multi5=x%5;
        
            if(multi3==0 && multi5==0){
                printf("Múltiplo de 3 e 5 = % i\n", x);
            }
    }
    return 0;
}
