#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
	char email[40];
	char naturalidade[40];
	char UF_Nasc[30];
	char dataNasc[20];
	char rua[40];
	char numero[10];
	char bairro[40];
	char municipio[40];
	bool ativo;
};

int procurarRec(char procurado[], struct ficha vetor[], int num_fichas)
	{	
	 if(strcmp(procurado, vetor[num_fichas-1].nome) == 0) return num_fichas-1;
	 else if(strcmp(procurado, vetor[num_fichas-1].nome) > 0) 
	 return procurarRec(procurado, vetor, num_fichas-1); 
	 else return -1; 	
	}

int procurar(char procurado[], struct ficha vetor[], int num_fichas, int indice_inicial)
{ 
	int i;
	for(i=indice_inicial; i<num_fichas; i++)
	{
	    if(strstr(vetor[i].nome, procurado) != NULL)
		{
		 return i;
		}
	}
	return -1;					
}

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
	
    setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '6')
	{
		printf("\nEntre com a opção desejada:\n");
		printf("1) Inserir ficha:\n");
		printf("2) Procurar por nome:\n");
		printf("3) Listar toda a base:\n");
		printf("4) Excluir por nome:\n");
		printf("5) Update:\n");
		printf("6) Sair\n");
	    gets(opcao);
		
		if(opcao[0] == '1')
		{   
		    printf("\n-------------------------------------");
			printf("\nEntre com um nome:\n ");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone:\n ");
			gets(agenda[proxima].telefone);
	
			printf("\n-------------------------------------");
		  	agenda[proxima].ativo = true;
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2')
		{
			char procurado[40];
			int incremento=0;
			int selec=1;
			printf("\nEntre com o nome procurado:\n");
			gets(procurado);
			
			while (selec==1)
			{
    			int i = procurar(procurado, agenda, fichas_existentes,incremento);
    			if(i>=0) 
    			{
    			    
    			    printf("\n-------------------------------------");
    				printf("\nOs dados de %s são:", agenda[i].nome);
    				printf("\nTelefone: %s", agenda[i].telefone);
					printf("\n-------------------------------------");
    				incremento++;
    				printf("\nDeseja verificar se existem nomes parecidos no banco de dados? 1:sim /0:Nao ");
    				scanf("%i", &selec);
    			}
    			else 
    			{
    			printf("\nNome não encontrado\n");
    			selec=0;
    			}
			}
			selec=1;
			incremento=0;
		}
		
		if(opcao[0] == '3') 
		{
			printf("==== Dados existentes ====\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
		     	if(agenda[i].ativo == true)
		     	{
					printf("\n-------------------------------------");
    				printf("\nOs dados de %s são:", agenda[i].nome);
    				printf("\nTelefone: %s", agenda[i].telefone);
					printf("\n-------------------------------------");
				}
			}
				if(fichas_existentes == 0)
			  	printf("A base de dados está vazia!\n");
			
		}
		if(opcao[0] == '4') //****************Excluir****************
		{
			char procurado[40];
			printf("\nEntre com o nome que sera excluído:");
			gets(procurado);
			int excluir=0;
			int i = procurar(procurado, agenda, fichas_existentes,0);
			
			if(i>=0)
			{ 
			        printf("\n-------------------------------------");
    				printf("\nOs dados de %s são exluídos:", agenda[i].nome);
    				printf("\nTelefone: %s", agenda[i].telefone);
				printf("\nDeseja realmente excluir esses dados? 0:Não/1: Sim");	
				scanf("%i", &excluir);
			
				if (excluir==1) agenda[i].ativo = false;
			}
			else printf("\n\nNome não encontrado\n");	
		}
		
		if(opcao[0] == '5')
		{
			bool opInvalida = false;
			int selecao;
			char procurado[40];
			printf("\nEntre com o nome que sera atualizado:");
			gets(procurado);
			
			int i = procurar(procurado, agenda, fichas_existentes,0);
			printf("\n\nA Ficha de %s será editada!\n", agenda[i].nome);
			
			if(i>=0)
			{ 
				    printf("\n-------------------------------------");
        			printf("\nEntre com um nome: ");
        			gets(agenda[proxima].nome);
        			printf("\nEntre com um telefone: ");
        			gets(agenda[proxima].telefone);
        			printf("\n-------------------------------------");
			    	agenda[i].ativo = true;
			}
		}		
	}
	return 0;
}
 



