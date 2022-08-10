//3. Desenvolva um programa em C do problema a seguir (2,5): Utilizando comandos de seleção aninhados, identifique 
// e calcule a comissão de um vendedor baseado no valor de venda informado:
//0 a 100, comissão de 1%
//101 a 200, comissão de 2%
//201 a 300, comissão de 3 %
//301 a 400, comissão de 4%
//Acima de 400, comissão de 5%

#include <stdio.h>

int main()
{
    float comissao, valor, c=0;
    while (c==0){
    
    printf("Informe o valor da venda do vendedor: ");
    scanf("%f",&valor);
    
    if((valor>=0.0)&&(valor<=100.00)){
    comissao = valor*0.01;
    }
    if((valor>=101.0)&&(valor<=200.00)){
    comissao = valor*0.02;
    }    
    if((valor>=201.0)&&(valor<=300.00)){
    comissao = valor*0.03;
    }   
    if((valor>=301.0)&&(valor<=400.00)){
    comissao = valor*0.04;
    }
    if(valor>400.00){
    comissao = valor*0.05;
    }
    printf("A comissão do vendedor e de R$ %.2f \n", comissao);
}
}

