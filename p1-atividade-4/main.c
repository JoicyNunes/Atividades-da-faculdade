//4.Desenvolva um programa em C do problema a seguir (2,5): Utilizando comandos de seleção aninhados, faça o 
//cálculo do salário líquido através de um salário bruto informado seguindo as devidas regras:
//Primeiro deduzir o INSS de 11% do salário bruto antes de verificar a faixa do IR
//Faixa de R$ 1,00 a R$ 1020,00 Isento de IR
//Faixa de R$ 1020,01 a R$ 2.500,00 7% de taxa de IR
//Faixa de R$ 2500,01 a R$ 3.800,00 15% de taxa de IR
//Faixa de R$ 3800,01 e acima, 27.5% de taxa de IR
//Salário Líquido = (Salário bruto – INSS) – IR

#include <stdio.h>

int main()
{
    float INSS, bruto, liquido, IR, c=0;
    while (c==0){
    
    printf("Informe seu salário bruto: ");
    scanf("%f",&bruto);
   
    INSS = (bruto*0.11 - 0.00100);
    
    if(bruto<1020.00){
    printf("Não obteve o desconto de R$ %0.2f do IR. \n", IR);
    }
    if((bruto>=1020.01)&&(bruto<=2500.00)){
    IR = bruto*0.07;
    }
    if((bruto>=2500.01)&&(bruto<=3800.00)){
    IR = bruto*0.15;
    }    
    if(bruto>=3800.01){
    IR = bruto*0.275;
    }   
    
    liquido = (bruto - INSS) - IR;
    
    printf("O salário liquidado e de R$ %.2f. \n", liquido);
    printf("Com o desconto de R$ %.2f do INSS. \n", INSS);
    
    if(bruto>=1020.00){
    printf("Com o desconto de R$ %.2f do IR. \n", IR);
    }
  }
}



