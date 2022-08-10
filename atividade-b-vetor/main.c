#include <stdio.h>
int main() {
	int FirstArray[10];
	int SecondArray[10];
	int x;
	
		for(x=0;x<10;x++){
			printf("Informe o número para o vetor: ");
			scanf("%d",&FirstArray[x]);
		}
		printf("\n");
		
		for(x=0;x<10;x++){
			if(FirstArray[x]%2==0){
			    SecondArray[x]=FirstArray[x]*2;
			    printf("A multiplicação %d x %d = %d \n", FirstArray[x], 2, SecondArray[x]);
			}
		else{
			SecondArray[x]=FirstArray[x]*3;
			printf("A multiplicação %d x %d = %d \n", FirstArray[x], 3, SecondArray[x]);
		}
		}
	return 0;
}