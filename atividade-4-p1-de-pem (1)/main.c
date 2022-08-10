#include <stdio.h>
#include <locale.h>
int somaBorda (int L, int C, int  mat[L][C])
{
    int coluna,linha,soma=0;
    for (coluna=1;coluna<=C;coluna++) 
    {
        for (linha=1;linha<=L;linha++) 
        {		
            if (((linha==1) || (linha==L))  && (coluna<=C))
    		{
    		    soma = soma + mat[linha][coluna];
            }
               	
            if (((coluna==1) || (coluna==C))  && ((linha>1) && (linha<L)))
    		{
    		    soma = soma + mat[linha][coluna];
    		}
        }
    }
     return soma;  
}   

int main() 
{
    int tamanholinha=0,linha=0,tamanhocoluna=0,coluna=0,valor=0,teste=0,valorsoma=0;
    
    
    printf("Informe o tamanho da linha da matriz: ");
    scanf("%d", &tamanholinha);

    printf("\nInforme o tamanho da coluna da matriz: ");
    scanf("%d", &tamanhocoluna);
    
    int matriz[tamanholinha][tamanhocoluna];
    
   	for (coluna=1; coluna<=tamanhocoluna; coluna++) 
	{
	    for (linha=1;linha<=tamanholinha;linha++) 
        {		
           if (((linha==1) || (linha==tamanholinha))  && (coluna<=tamanhocoluna))
		   {
			    printf("\nInforme o conteúdo da linha %d x coluna %d: ",linha,coluna);
			    scanf("%d",&valor);      
				matriz[linha][coluna] = valor;
           	}
           	
           	if (((coluna==1) || (coluna==tamanhocoluna))  && ((linha>1) && (linha<tamanholinha)))
			{
			    printf("\nInforme o conteúdo da linha %d x coluna %d: ",linha,coluna);
				scanf("%d",&valor);
				matriz[linha][coluna] = valor;	
			}
    	}
   }
   
    valorsoma=somaBorda(tamanholinha,tamanhocoluna,matriz);
    printf("\nA soma da borda da matriz é igual a: %d ",valorsoma); 
    
   return 0; 
  
}


