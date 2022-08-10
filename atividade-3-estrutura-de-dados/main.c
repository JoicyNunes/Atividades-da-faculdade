#include <stdio.h>

int fibonacci(int numero){
  
    if (numero == 1) 
    return 1;
  
    if (numero == 2) 
    return 1;
  
    else
    return fibonacci(numero - 1) + fibonacci(numero - 2);
    
}

int main(){
  int n;
  int i;
  
    printf("Digite o número de termos da sequencia: ");
    scanf("%d", &n);

    printf("\nOs %d da sequência são: \n", n);
    
        for (i = 1; i <= n; i++) 
  
  {
    printf("%d ", fibonacci(i));
  }
 
    return 0;
}
