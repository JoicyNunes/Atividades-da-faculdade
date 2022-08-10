#include <stdio.h>

void func_saldo(float *p){
    printf("\nSeu saldo é de R$ %.2f\n", *p);
}

void func_saque(float *p){
    float saque;
    
    printf("\nInforme o valor que deseja sacar: ");
    scanf("%f", &saque);

    if (saque > *p){
        printf ("\nSaldo Insuficiente!\n");
    }

    else{
    printf("\nSaque realizado com sucesso no valor de R$ %.2f.", saque);
    *p -= saque;
    printf("\nSeu saldo atual é no valor de R$ %.2f.\n", *p);
    }
}

void func_deposito(float *p){
    float deposito;
    
    printf("\nInforme o valor que deseja depositar: ");
    scanf("%f", &deposito);

    *p += deposito;
    printf("\nSeu saldo atulizado para o valor de R$ %.2f.\n", *p);

}

int main(int argc, char* argv[])
{ 
    int opcao;
    float saldo, saque, deposito, r;
    float *p;

    p = &saldo;
    *p = 10000;

    do{
        printf ("\nEscolha a opção desejada: \n1-Saldo 2-Saque 3-Deposito 4-Saida\n");
        scanf ("%i", &opcao);

    switch (opcao){
        case 1:{
        func_saldo(p);
    break;
    }

        case 2:{
        func_saque(p);
    break;
    }

    case 3:{
    func_deposito(p);
    break;
    }

    case 4 :{
    return 4;
    }

    default :{
        r = 0;
        printf ("Opção inválida!\n");
        }
    }
}
    while (opcao =! 0);
    
    return 0;
}
