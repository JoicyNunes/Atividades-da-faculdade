#include <stdio.h>
int main() {
	int maior=10, menor=10;
	int valor[20];
	int x;
	float media, SomaMedia;
	
		for(x=0;x<20;x++){
		printf("Informe um número %d: ", x);
		scanf("%d",&valor[x]);
        SomaMedia=SomaMedia+valor[x];
        media=SomaMedia/20.0;
		}
        printf("\n");
        
        for(x=0;x<20;x++){
	        if(valor[x]>=maior){
	            maior=valor[x];
	        }
            if(valor[x]<=menor){
		        menor=valor[x];
		    }
        }
    	printf("O maior número informado é %d \n", maior);
    	printf("O menor número informado é %d \n", menor);
    	printf("A média do número informado é %.2f \n", media);
}

