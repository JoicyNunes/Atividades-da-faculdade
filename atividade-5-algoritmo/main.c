//5- Reutilizando o algoritmo do caixa eletrônico, implemente um laço faça enquanto verifique se o usuário 
//deseja continuar, caso a variável coletada for igual 1 reinicie o laço, mantendo o valor do saldo.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int Operacao, Sair;
	float Saldo, Saldo2, Saldo3, Saque, Deposito;
	Saldo = 10000;
	Saldo2 = 0;
	Saldo3 = 0;
	Sair = 0;
	do {	
	printf("Informe 1-Saldo, 2-Saque, 3-Deposito, 4-Sair: ");
	scanf("%i",&Operacao);
	switch(Operacao) {
		case 1:{
			Saldo=Saldo+Saldo3-Saldo2;
			printf("\nSeu Saldo é no valor de R$ %.2f\n\n",Saldo);
			break;
		}
		case 2:{
		printf("\nInforme o valor do Saque: ");
		scanf("%f", &Saque);
		
		if(Saque>Saldo){
		printf("Saldo Insuficiente \n\n");
		}
		if(Saque<Saldo){
		Saldo2=Saldo-Saque;
		printf("O saque foi realizado com sucesso, saldo restante no valor de R$ %.2f \n\n", Saque);
		}
	break;
		}
		case 3:{
			printf("\nInforme o valor a ser depositado: ");
			scanf("%f",&Deposito);
			Saldo3=Saldo+Deposito;
			printf("O valor total do deposito é R$ %.2f\n\n",Saldo3);
			break;
		}		
		case 4:{
			printf("Obrigado, até a próxima!");
			Sair = 1;
			break;
		}
		default:{
			printf("Operação não programada!\n");
			break;
		}
	}
} while (Sair != 1);
	return 0;
}

