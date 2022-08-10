#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float temperatura[10][3]; 
	int x,graus,CTempoMin=0,CTempoMax=1,CTempoMedia=2;
	float MediaTempo=0,SomaTempoMin=0,SomaTempoMax=0,TempoMax=0; 
	
	for (x=0; x<10; x++){
		printf("Informe a temperatura mínima do dia %d em graus celsius:",x+1);
		scanf("%f", &temperatura[x][CTempoMin]);

		printf("Informe a temperatura máxima do dia %d em graus celsius:",x+1);
		scanf("%f", &temperatura[x][CTempoMax]);

		temperatura[x][CTempoMedia] = (temperatura[x][CTempoMax] + temperatura[x][CTempoMin]) / 2;
	}
		
		do{
				printf("\n Escolha a seguinte opção: \n");
				printf("1 - Temperatura mínima de todos os dias. \n");
				printf("2 - Temperatura máxima de todos os dias. \n");
				printf("3 - Maior variação de temperatura de todos os dias. \n");
				printf("4 - Sair do programa. \n");
				scanf("%d",&graus);	
				printf("\n");	
					switch(graus){
								case 1:	
								{
									for(x=0; x<10; x++){
								    printf("Temperatura mínima do dia %d: %.2f graus. A média da temperatura é de %.2f graus celsius \n", x+1, temperatura[x][CTempoMin], temperatura[x][CTempoMedia]);
									}
									break;
								};
										
								case 2:
								{
									for(x=0; x<10; x++){
									printf("Temperatura máxima do dia %d: %.2f graus. A média da temperatura é de %.2f graus celsius \n", x+1, temperatura[x][CTempoMax], temperatura[x][CTempoMedia]);
									}
									break;	
								};
											
								case 3:
								{
									for(x=0; x<10; x++){
									if(temperatura[x][CTempoMax]>TempoMax){
									TempoMax=temperatura[x][CTempoMax];
									}
									}
									printf("Temperatura máxima de todos os dias é de %.2f graus celsius \n", TempoMax );
									break;	
								};	
	    		}
			    		
			if (graus>4)
			{
			printf("Opção Invalida!\n");							
			}
			    		
		}
		while(graus<4 || graus>4);
			
		printf(" \n FIM DO PROGRAMA ");
	return 0;
	
}
