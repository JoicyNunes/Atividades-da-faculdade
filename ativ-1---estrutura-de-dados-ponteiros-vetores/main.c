/*1- Suponha que os elementos do vetor v são do tipo int e cada int
ocupa 8 bytes no seu computador. Se o endereço de v[0] é 55000, qual o
valor da expressão v + 3?*/

#include <stdio.h>

int
main ()
{
    int v[] = {55000};
    int *p;
    p = &v[0];
 
    printf("%x = %i \n", *(v+3));//v[3]
 
 

  return 0;
}
