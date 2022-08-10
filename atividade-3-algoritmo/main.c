//3- Faça um laço que calcule a média de todos os números informados, 
//a condição de término do laço e quando for digitado ZERO.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
float num, media=0, cont=0;
    do
    {
    printf("Informe um número: ");
    scanf("%f",&num);
    
        if(num!=0){
            media=media+num;
            cont++;
            cont = cont + 1;
            }
    }while(num!=0);
    media=media/cont;
    printf("Média = %f", media);
    
    return 0;
}
