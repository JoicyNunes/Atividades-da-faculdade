
#include <stdio.h>

int main()
{
    int n, atual, anterior, i, grupos=1;
    printf("Quantos números? \n");
    scanf("%d",&n);
    
    printf("Entre com o número: ");
    scanf("%d", &anterior);
    
    for(i=2; i<=n; i++){
        printf("Entre com o número: ");
        scanf("%d", &atual);
        if(atual != anterior){
            grupos++;
        }
            anterior = atual;
        }
    printf("Há %d grupos!", grupos);
    return 0;
}
