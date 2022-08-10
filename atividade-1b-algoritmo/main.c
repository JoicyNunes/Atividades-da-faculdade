//1- Dado o algoritmo abaixo escrito em C:
//int i, a, b; for(i=0; i<20; i++) { scanf("%d",&a); scanf("%d",&b); r = a + b; printf("%d\n", r); }
//a- Reescreva com o laço enquanto faça (while);
//b- Reescreva com o laço faça enquanto (do while);
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

int i = 0;
int cont = 0;
int a = 0;
int b = 0; 

 do
 {
    printf("Informe um número para a: ");
    scanf("%d",&a);
        if(i>a){
        a = i;
    }
    cont = cont + 1;

    printf("Informe um número para b: ");
    scanf("%d",&b); 
        if(i>b){
        b = i;
    }
    cont = cont + 1;

}
    while (i<20, i++);
    i = a + b; 
    printf("%d\n", i); 
    
    cont = 0;
}