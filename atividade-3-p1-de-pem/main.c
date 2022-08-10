#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double produtoEscalar (double A[ ], double B[ ], int N)
{
    int x;
    double soma=0, mult=0;
    
    for(x=1;x<=N;x++)
    {
        mult = A[x] * B[x];
        soma = soma + mult;
    }
    printf("O Produto Escalar dos vetores: %.f \n", soma);
    return soma;
}
  
int main()
{
    double A[100], B[100];
    int N, x;
   
    printf("Infome o tamanho do vetor: ");
    scanf("%d", &N); 
   
    for(x=1;x<=N;x++)
    {
        printf("De um número para o %dº vetor A: ", x);
        scanf("%lf", &A[x]);
        printf("De um número para o %dº vetor B: ", x);
        scanf("%lf", &B[x]); 
        printf("\n");
    }
    
   produtoEscalar(A,B,N);
}