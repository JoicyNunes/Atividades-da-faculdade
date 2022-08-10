#include <stdio.h>

int main()
{
    int y, *p, x;
    
        y = 0;
        p = &y;
        x = *p;
        x = 4;
        
    ++(*p);
    x--;
    *(p + 10);
   
printf ("y = %d \n ", y);

return 0;
}


