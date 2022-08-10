//7 - Uma rainha requisitou os serviços de um monge e disse-lhe que pagaria qualquer preço.
//O monge, necessitando de alimentos, indagou à rainha sobre o pagamento, se poderia ser feito 
//com grãos de trigo dispostos em um tabuleiro de 64 casas, de tal forma que o primeiro quadro 
//deveria conter apenas um grão e os quadros subsequentes, o dobro do quadro anterior. A rainha 
//achou o trabalho barato e pediu que o serviço fosse executado, sem se dar conta de que seria 
//impossível efetuar o pagamento. Faça um algoritmo para calcular o número de grãos que o monge 
//esperava receber.
//100.000 grãos = 1kg

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int x;
    float grao, soma, kg;
    grao = 1;
    soma = 0;
    
    printf("Calculo a ser pago em grãos do monge!");
    
    for (x=0; x<64; x++)
    {
        grao = grao*2;
        soma = soma + grao;
    }
    
    kg = soma/100000;
    printf("\nTotal de grãos em quilo é %.0f kg", kg);
    
    return 0;
}
