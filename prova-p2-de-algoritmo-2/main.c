//Faça um programa que controle e armazene em um vetor a entrada de índice de transito
//de hora em hora, ao final do dia exiba a media, menor e maior índice em km (2,5)

#include <stdio.h>
int main() {
	int valor[24];
	int x;
	float media, SomaMedia, maior, menor=9999, KMh;
	
		for(x=0;x<24;x++){
		printf("Informe o número de índice de transito em km por hora %d: ", x);
		scanf("%f",&KMh);
        SomaMedia=SomaMedia+KMh;
        media=SomaMedia/24.0;
        
        if(KMh>maior)
        {
	       maior=KMh;
	    }
        if(KMh<menor)
		{
			menor=KMh;
		}
}
    	printf("O maior índice é %.2f KM, o menor é %.2f KM e a media é %2.f KM \n", maior,menor,media);
    	
	return 0;   
}

