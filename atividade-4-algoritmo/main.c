//4- Faça um laço “faça até” com 10 interações, verifique quantas vezes números
//múltiplos de 2 e de 3 são informados.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int x, num, multi2, multi3;
    
    for(x=1; x<=10; x++){
        printf("Informe um número: ");
        scanf("%i", &num);
        
            multi2 = num % 2;
            
            multi3 = num % 3;
            
            if(multi2==0 && multi3==0){
                printf("Múltiplos de 2 e de 3: %i \n", num);
            }
    }
    return 0;
}

