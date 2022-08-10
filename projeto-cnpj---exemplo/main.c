#include<stdio.h>
#include<stdbool.h>
#include<string.h>
/*
    cpf -> vetor com os dígitos do cpf
    mult -> vetor com os multiplicadores, de tamanho N
    N -> Tamanho do vetor mult e também a quantidade de operações (9 ou 10)
*/
int calculaDigito(int cpf[], int mult[], int N)
{   int soma=0, i;
    for(i=0; i<N; i++)
	{	soma = soma + cpf[i]*mult[i];
	}
	return ((soma*10) % 11)%10;
}

/*
    Retorna true se todos os 11 dígitos de um CPF forem iguais, caso contrário,
    retorna false.
*/
bool todosRepetidos(int cpf[])
{   int i;
    for(i=1; i<11; i++)
    {   if(cpf[0]!=cpf[i])
            return false;
    }
    return true;
}

/*
    Imprime a região onde o CPF foi inscrito
*/
void imprimeRegiaoOrigem(int cpf[])
{   char regioes[][100] = {
        "Rio Grande do Sul",
        "Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins",
        "Amazonas, Pará, Roraima, Amapá, Acre e Rondônia",
        "Ceará, Maranhão e Piauí",
        "Paraíba, Pernambuco, Alagoas e Rio Grande do Norte",
        "Bahia e Sergipe",
        "Minas Gerais",
        "Rio de Janeiro e Espírito Santo",
        "São Paulo",
        "Paraná e Santa Catarina"};
    printf("%s", regioes[ cpf[8] ]);
}

/*
    Lê CPF como string e processa adequadamente, transformando-o
    num vetor numérico, preenchendo zeros à esquerda, se necessário.
*/
void leiaCPF(int cpf[])
{   char texto[30];
    fgets(texto, 30, stdin);
    int i, j=10;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>='0' && texto[i]<='9')
        {
            cpf[j] = texto[i] - '0';
            j--;
        }
    }
    
    while(j>=0)
    {   cpf[j] = 0;  //zero à esquerda
        j--;
    }
}

/*
    Imprime um CPF com pontos e hífen nas posições corretas 
*/
void imprimeCPF(int cpf[])
{   int i;
    for(i=0; i<11; i++)
    {   printf("%d", cpf[i]);
        if(i==2 || i==5) printf(".");
        else if(i==8) printf("-");
    }
}

int main()
{   int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com o CPF: ");
	leiaCPF(cpf);
  	
	if(todosRepetidos(cpf) == false && calculaDigito(cpf, m1, 9) == cpf[9] &&
	   calculaDigito(cpf, m2, 10) == cpf[10])
	{  imprimeCPF(cpf);
	   printf("  ->  CPF válido, inscrito na seguinte região: ");
	   imprimeRegiaoOrigem(cpf);
	}
	else printf("\nErro no CPF.");
	return 0;
}
