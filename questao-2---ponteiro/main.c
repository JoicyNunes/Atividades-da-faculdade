#include <stdio.h>
int main()
{
//a recebe 10, b recebe 7, c não inicializado    
int a = 10, b = 7, c; 
//p recebe o endereço de a
int * p = &a;
// q é declarado como inteiro que recebe o endereço de inteiro b.
int * q = &b;
// r é declarado como inteiro que recebe o endereço de inteiro c.
int * r = &c; 
    // o valor armazenado no endereço indicado por r (variável c) recebe uma atribuição sendo igual ao que está 
    // sendo indicado por p (variável a). 
    *r = *p; 
    // o valor armazenado no endereço indicado por p (variável a) recebe uma atribuição sendo igual ao que está 
    //sendo indicado por q (variável b).
    *p = *q; 
     // o valor armazenado no endereço indicado por q (variável b) recebe uma atribuição sendo igual ao que está 
     // sendo indicado por r (variável c).
    *q = *r;
    // É exibido os valores armazenados em a e b. Respectivamente, 7 e 10.
    printf("%d-%d", a, b);  
return 0;
}
