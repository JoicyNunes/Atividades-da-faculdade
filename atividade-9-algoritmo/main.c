//9- Crie um algoritmo onde será informado um valor inteiro inicial, e um laço o usuário deverá informar 
//outro número inteiro, o programa deverá responder se o número atual e menor ou maior que o número inicial 
//informado, o laço somente será interrompido quando o número atual for igual ao número anterior informado. 
//Exiba quantas tentativas foram necessárias para que o número fosse descoberto.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int numA, numB, cont=0;
    
    printf("Infome um número para ser descoberto: ");
    scanf("%i", &numA);
    system("cls");
    
    do
    {
        printf("\nInfome um número: ");
        scanf("%i",&numB);
            
            if(numA>numB){
                printf("É maior que %i\n", numB);
                cont++;
            }   
            else{
                if(numA<numB){
                printf("É menor que %i\n", numB);
                cont++;
                }
                    else{
                    printf("Parabéns você acertou, seu números de tentativas %i\n", cont);
                    }
            }
        }    
    while(numA != numB);
    
    return 0;
}

