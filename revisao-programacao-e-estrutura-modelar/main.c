/* 7. Dadas duas sequências com n números inteiros entre 0 e 9, interpretadas como dois números inteiros 
de n algarismos, calcular a sequência de números que representa a soma dos dois inteiros.
Exemplo: n = 8,
1ª sequência 8 2 4 3 4 2 5 1
2ª sequência 3 3 7 5 2 3 3 7  +
    -----------------------
    1 1 6 1 8 6 5 8 8
*/
#include <stdio.h>
int main() {

	int valor[2];
	int x, soma=0;
	
	    for(x=0;x<2;x++){
	    printf("Informe uma sequencia de numeros: ");
	    scanf("%d", &valor[x]);
	    soma = soma + valor[x];
	    }
    	printf("A soma das sequencia é %.i", soma);
    	return 0;
}