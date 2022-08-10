#include <stdio.h>

typedef struct {
    int numero;
    float saldo;
} ContaBancaria;

void saldo(ContaBancaria* conta, int numero, double saldo){
    (*conta).numero = numero;
    (*conta).saldo = saldo;
}

void deposito (ContaBancaria *conta, double deposito){
    (*conta).saldo += deposito;
}

void saque (ContaBancaria* conta, double valor){
    
    (*conta).saldo -= valor;

}
    return 0;
}
