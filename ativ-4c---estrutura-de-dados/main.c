#include <stdio.h>

int main()
{
    
    char *a, *b, abacate, uva;
    a = "abacate";
    b = "uva";

        if (*a < *b) 
        {
        printf ("%s vem antes de %s no dicionário", a, b); 
        }
        else
        {
        printf ("%s vem depois de %s no dicionário", a, b);
        }
}


