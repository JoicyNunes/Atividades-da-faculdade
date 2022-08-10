#include <stdio.h>
int somaQuadradros(int n)
{
	if (n == 0) 
  	  return 0;
  	  
	else {
	    if (n < 0){
	        n = n * (-1);
	    }
	    return somaQuadradros(n-1) + n * n;
	}
}

int main()
{
	int n;
	printf("Digite um valor para n: ");
	scanf("%d", &n);
	printf("O total da soma é: %d", somaQuadradros(n));
	return 0;
}

