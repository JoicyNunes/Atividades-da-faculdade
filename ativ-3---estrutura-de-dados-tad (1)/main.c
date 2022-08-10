#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double saldo;
} ContaBancario;

void Saldo(ContaBancario *p, double saldo){
    p -> saldo = saldo;
}
void Deposito (ContaBancario *p, double valor){
    p -> saldo += valor;
}
void Saque (ContaBancario *p, double valor){
    p -> saldo -= valor;
}
void Imprime (ContaBancario p){
    printf("\nSaldo: R$%2.f\n", p.saldo);
}

int main (void)
{
    ContaBancario conta;
        Saldo(&conta, 10000);
            printf("\nSaldo atual: ");
        
        Imprime(conta);
        
        Deposito(&conta, 5000);
        
        Saque(&conta, 8000);
            printf("\nSaldo atualizado: ");
            
        Imprime(conta);

    return 0;
}
