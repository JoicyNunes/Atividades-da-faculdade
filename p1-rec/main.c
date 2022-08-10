//Informe três números inteiros, utilizando comandos de seleção encadeados, defina qual o menor, do meio e o 
//maior número. Caso os números forem iguais, mostre a mensagem : Números Iguais, verifique

#include <stdio.h>

int main()
{
    float numero;
    {
    
    printf("Informe três números inteiros: ");
    scanf("%f",&numero);
    
    if(numero){
        numero = numero>10;
        numero = numero>=10;
        numero = numero<10;
    }
    printf("O maior número é %.f, o meio %.f, menor %.f.", numero);
    
    else(numero){
        numero = 10;
    }
    printf("número iguais %.f \n", numero);
}
}