//6- Crie um laço e verifique qual a maior sequência de números pares informados, o laço fara 10 iterações.
//Ex: 1, 2,3,4,6,8,5,3,2,5,8,4,0   
//Sequência: 4,6,8   
//O programa vai retornar: 3

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int num, sequencia=0, maiorSeq=0, x, exc2;
    
    for(x=0; x<10; x++)
    {
        printf("Informe um número: ");
        scanf("%i", &num);
        
        exc2 = num%2;
            if(exc2==0){
                    sequencia++;
                    sequencia = sequencia + 1;
                        if(sequencia>maiorSeq){
                            maiorSeq=sequencia;
                        }
            }else {
                sequencia=0;
            }
    }
    printf("O maior número da sequência é %i", maiorSeq);
    return 0;
}
