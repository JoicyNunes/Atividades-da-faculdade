#include <stdio.h>
int main() {
	int valor[20];
	int x;
	int num, impar=0, par=0;
	float perPar, perImpar;
	
		for(x=0;x<20;x++){
			printf("Informe um número %d: ",x);
			scanf("%d",&valor[x]);
		}
		
		for(x=0;x<20;x++){
			if(valor[x]%2==0){
				par++;
			}
		else{
			impar++;
		}
		}
		
		perPar=(par*100)/20;
		printf("O percentual de números pares é de %2.f por cento \n", perPar);
		
		perImpar=(impar*100)/20;
		printf("O percentual de números impares é de %2.f por cento \n", perImpar);
			
	return 0;
}
