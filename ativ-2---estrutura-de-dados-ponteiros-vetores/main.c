#include <stdio.h>
#include <stdlib.h>

void mm(int *v, int n, int *min, int *max)
{
    int i;
        *min = v[0];
        *max = v[0];

    for (i = 1; i < n; i++){ 
        if (v[i] > *max){ 
            *max = v[i];
        }

    else if(v[i] < *min){ 
        *min = v[i];
    }
    }
}

int main()
{ 
    int n, i, *vet, min, max;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

        vet = malloc(n * sizeof(int));

    for (i = 0; i < n; i++){ 
        printf("Digite o número de indíce %d: ", i);
        scanf("%d", &vet[i]);
    }

        mm(vet,n,&min, &max);
        printf("Mínimo: %d, Máximo: %d números.\n", min, max);
    
    return 0;
}
