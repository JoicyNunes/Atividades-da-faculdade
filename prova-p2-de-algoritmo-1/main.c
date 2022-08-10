//Faça um programa que receba e armazene em um vetor 30 números inteiros e verifique 
//qual a maior sequência de números pares informados (1,5)

#include <stdio.h>
int main(int argc, char* argv[]) {
	int valor[30];//vetor com 30 números inteiros
	int x;
	int par=0, MaiorNum;
	
		for(x=0;x<30;x++){
			printf("Informe um número %d: ",x);//informar a sequência de números inteiros
			scanf("%d",&valor[x]);
		}
		
		for(x=0;x<30;x++){
			if(valor[x]%2==0){
				par++;
			}
		}
		
		MaiorNum=(par + 0);//soma da sequência de números pares
		printf("A maior sequência de pares é de %i núemros \n", MaiorNum);
		
			
	return 0;
}



