#include <stdio.h>

int main()
{
 int Saldo = 10000, Saque, Deposito, opcao;

	printf("Informe 1-Saldo, 2-Saque, 3-Deposito: ");
	scanf("%i",&opcao);
	
switch(opcao){

	case 1:{
		Saldo = Saldo + 0;
		printf("Seu Saldo é no valor de R$ %.2i \n", Saldo);
	break;
}

	case 2:{
		printf("Informe o valor do Saque: ");
		scanf("%i", &Saque);
		
		if(Saque>10000){
		printf("Saldo Insuficiente");
		}
		
		if(Saque<10000){
		Saque=Saldo-Saque;
		printf("O saque foi realizado com sucesso, saldo restante no valor de R$ %.2i \n", Saque);
		}
		
	break;
}
	
	case 3:{
		printf("Informe o valor a ser depositado: ");
		scanf("%i", &Deposito);
		Deposito=Deposito+Saldo;
		printf("O valor total do deposito é R$ %.2i", Deposito);
	break;
}

	default:{
		Saque>10000;
		break;
	}
			
}
}
