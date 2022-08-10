#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int cont = 0;
    int num = 99;
	int maior = 0;
	int media = 99;
	int menor = 99;
    printf("Informe uma sequencia de números interios: ");
    scanf("%i", &num);
	while(num > 99);
	{
		scanf("%i", &num);	
		if(num > maior){
			maior = num;	
		}		
		cont = cont + 1;
	}
	printf("O maior numero informado foi %i \n", maior);
	cont = 0;
	{
	   scanf("%i", &num);	
	   if(num < media){
			media = num;	
	    }
	    cont = cont + 1;
	}
	printf("A media do numero informado foi %i \n", media);
	cont = 0;
	{ 
	    scanf("%i", &num);	
		if(num < menor){
			menor = num;	
		}		
		cont = cont + 1;
	}
	printf("O menor numero informado foi %i \n", menor);
	cont = 0;
	return 0;
}
