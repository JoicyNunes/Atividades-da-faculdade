//Faça um algoritmo que armazene em um vetor 5x3 quer armazene a altura, peso de cada pessoa e na terceira coluna 
//calcule o IMC  => PESO/(ALTURA X ALTURA)  de cada individuo de uma família, ao final exiba quantos quilos cada 
//pessoa deve perder para alcançar o IMC  25  (3,00)

//Joicy da Silva Nunes

#include <stdio.h>

int main(int argc, char* argv[]) {

  int vetor1[5][3];

  int peso = 0;
  int altura = 0;
  int contador = 0;

  for(contador = 0; contador < 5; contador++){
    printf("Digite a altura e depois o peso da pessoa %d: ", contador);
    scanf("%i %i", &altura, &peso);
    vetor1[contador][0] = altura;
    vetor1[contador][1] = peso; 
    vetor1[contador][2] = peso/(altura*altura); 
  }

  for(contador = 0; contador < 5; contador++){
    int contaPesosPerdidos = 0;
    if (vetor1[contador][2] > 25) {
      while(vetor1[contador][2] > 25) {
        vetor1[contador][1] = vetor1[contador][1] - 1;
        vetor1[contador][2] = vetor1[contador][1]/(vetor1[contador][0]*vetor1[contador][0]);
        contaPesosPerdidos += 1;
      }
    }
    printf("O membro %.i precisa perder %d quilos para ter o IMC = 25 \n", contador, contaPesosPerdidos);
    contaPesosPerdidos = 0;
  }
  return 0;
}
