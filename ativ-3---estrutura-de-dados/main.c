#include <stdio.h>

int main()
{
int x, y, *p;
    y = 0; 
    p = &y; 
    x = *p; 
    x = 4; 
    (*p)++; 
    x--; 
    (*p) += x;
    
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("p = %d \n", *p);
    

    return 0;
}
