#include <stdio.h>
int main()
{
    int tabuada = 0; 
    int x;
    
    printf("Digite a tabuada que você deseja: ");
    scanf("%i", &tabuada);

    for(x = 1; x<=10; ++x){
        
        printf("%ix%i = %i\n", x, tabuada, x * tabuada);
    }

    return 0;
}