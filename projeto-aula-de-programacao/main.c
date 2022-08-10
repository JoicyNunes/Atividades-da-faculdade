#include<stdio.h>
#include<stdbool.h>
bool todosRepetidos(int cpf[])
{
    int i;
    for(i=1; i<11; i++);
        if(cpf[0]!=cpf[i]);
            return false;
    return true;
}

void imprimeRegiaoOrigem(int cpf [])
{
    switch (cpf[8])
    {
    case 0:
        printf("\nA origem do CPF é Rio Grande do Sul.");
        break;
        
    case 1:
        printf("\nA origem do CPF é Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins.");
        break;
        
    case 2:
        printf("\nA origem do CPF é Amazonas, Pará, Roraima, Amapá, Acre e Rondônia.");
        break;
        
    case 3:
        printf("\nA origem do CPF é Ceará, Maranhão e Piauí.");
        break;
    case 4:
        printf("\nA origem do CPF é Paraíba, Pernambuco, Alagoas e Rio Grande do Norte.");
        break;
        
    case 5:
        printf("\nA origem do CPF é Bahia e Sergipe.");
        break;
        
    case 6:
        printf("\nA origem do CPF é Minas Gerais.");
        break;
        
    case 7:
        printf("\nA origem do CPF é Rio de Janeiro e Espírito Santo.");
        break;
    
    case 8:
        printf("\nA origem do CPF é São Paulo.");
        break;
        
    case 9:
        printf("\nA origem do CPF é Paraná e Santa Catarina.");
        break;
    
    default:
    	printf("Origem inválida.");
        break;
    }
    
}

int calculaDigito(int cpf[], int  mult[], int N)
{
    int soma=0, i;
	for(i=0; i<N; i++)
	{	
	    soma = soma + cpf[i]*mult[i];
	}
	return ((soma*10) % 11)%10;  
}
int main()
{
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	
	printf("Entre com os 11 dígitos do CPF:");
	for(i=0;i<11;i++)
	     scanf("%d", &cpf[i]);
	
	if(calculaDigito(cpf, m1, 9) == cpf[9] 
	&& calculaDigito(cpf, m2, 10) == cpf[10] 
	&&!todosRepetidos(cpf))	
		{
		 printf("\nCPF é válido.\n");
		 imprimeRegiaoOrigem(cpf);
		}
	else printf("\nErro no CPF.\n");
	
    return 0;
}
