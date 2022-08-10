//Faça um algoritmo que armazene em um vetor 5x3 quer armazene a altura, peso de cada pessoa e na terceira coluna 
//calcule o IMC  => PESO/(ALTURA X ALTURA)  de cada individuo de uma família, ao final exiba quantos quilos cada 
//pessoa deve perder para alcançar o IMC  25  (3,00)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	float ind[5][3], ColunaA=0, ColunaB=0;
	int x;

    printf("Informe a altura e peso dos pacientes: ");
	for(x=0;x<5;x++){
		printf("Informe a altura do paciente %d: ",x + 1);
		scanf("%f",&ind[x][0]);
		
		printf("Informe o peso do paciente %d: ",x + 1);
		scanf("%f", &ind[x][1]);
		
		ind[x][2]=ind[x][1]/(ind[x][0]*ind[x][0]);
	}
	for (x=0;x<5;x++){
	    
	    printf("O paciente %d tem o ICM %.2f", x+1, ind[x][2]);
		if(ind[x][2]<25){
	 	ColunaB=(25*(ind[x][0]*ind[x][0]))-ind[x][1];
	 	printf("O individuo %d tem %f de altura, %.2f kg e precisa ganhar %.2f kg ",x, ind[x][0],ind[x][1],ColunaB);
		}
		
		else{
	 	ColunaA=ind[x][1]-(25*(ind[x][1]*ind[x][0])-ind[x][0]);
	    printf("O individuo %d tem %f de altura, %.2f kg e precisa perder %.2f kg ",x, ind[x][0],ind[x][1],ColunaA);
        }
    }
}