#include <stdio.h>
int main()
{
//x e y são var. inteiras; p e q são var. ponteiro (end. memória)
int x, y, *p, *q; 
    //y recebe 19
    y = 19; 
    //p recebe o endereço de memória de y
    p = &y;
    // x (uma variável inteira) recebe o conteúdo apontado por p (variável de endereço de memória).
    x = *p; 
    //x recebe 7
    x = 7; 
    // p (variável de endereço de memória) incrementa 1 no que aponta no end. da variável, ou seja, na variável Y.
    (*p)++; 
    // A variável X é decrementada em 1.
    x--; 
    // p (variável de endereço de memória) está sendo atribuída ao que está localizada em p, no caso, a variável 
    //Y somando com o valor de X. O resultado é 26.
    (*p) = (*p) + x; 
        // Será exibido o valor armazenado em Y.
        printf ("y = %d\n", y); 
return 0;
}



