#include <stdio.h>

void troca(float *a, float *b){
float x;
x = *a;
*a = *b;
*b = x;
}

int main() {
    float x = 1, y = 2;
    
    printf("x = %.2f\t y = %.2f\n", x, y);
    troca(&x, &y);
    printf("x = %.2f\t y = %.2f\n", x, y);
    
    return 0;
}
