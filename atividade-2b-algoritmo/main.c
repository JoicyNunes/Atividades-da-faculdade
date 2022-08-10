//2- Dado o algoritmo abaixo escrito em C:
//int x = 10; while(x>0) {prinf("%d",x); x--; }
//a- Reescreva com o laço faça até (for);
//b- reescreva com o laço faça enquanto (do while);

#include <stdio.h>
#include <stdlib.h>

int main(){
int x = 10;
    do
    {
    printf("%d", x);
        x--;
        x=x-1;
    }
    while(x>0);
    
    return 0;
}
