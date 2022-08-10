/*
*******************************************************************************
Código Base para o Mini-Projeto Agenda de Amigos

Todos estes exercícios a seguir têm por base o código-base ao lado, que é um
mini CRUD (Create-Read-Update-Delete, ou Criar-Ler-Atualizar-Remover).

1) Inclua novos campos, como endereço, e-mail, data de nascimento, etc.

2) Crie uma função procurar, com a assinatura abaixo, de modo que ela possa ser
aproveitada tanto na funcionalidade procurar, quanto na excluir:

*Resposta:
*******************************************************************************
int procurar(char procurado[], struct ficha vetor[], int num_fichas)
	{   int i=0;
    if(num_fichas<= 0) return -1; //não existe
    else if(strcmp(procurado, vetor[i].nome) == 0) return i;//achei
    else return i++ && procurar(procurado, vetor, num_fichas);
	}
*******************************************************************************

 	O retorno dessa função será o índice do elemento encontrado, ou -1, caso o
 	mesmo não tenta sido localizado.

3) Reimplemente a função procurar de modo recursivo (particularmente não há
nenhuma vantagem nesta alteração, é só para treinarmos recursividade).

DICA: Estou colando aqui o exercício 10 da lista de recursividade:

	10) Crie uma função recursiva que procure um número dentro de um
		vetor, a partir de um dado índice. Se achar o mesmo, o método
		retorna o índice onde ele se encontra, senão, retorna -1.

	-> Só para entendermos melhor o problema, a versão interativa
		(não-recursiva) seria assim:

		int busca(int vet[ ], int N, int indiceInicio, int procurado)
		{	int i;
			for(i=indiceInicio; i < N; i++)
			{	if(procurado == vet[i])  return i;
			}
			return -1;
		}

	Agora vamos pensar na versão recursiva.... 

	int buscaRecursiva(int vet[ ], int N, int indiceInicio, int procurado)
	{	if(indiceInicio >= N) return -1; //já olhei em todo o vetor e não achei
		else if(vet[indiceInicio] == procurado) return indiceInicio;
		else return buscaRecursiva(vet, N, indiceInicio + 1, procurado);
	}
**********************************************************************************	
***Forma recursiva:

	int procurarRec(char procurado[], struct ficha vetor[], int num_fichas)
	{	
	 if(strcmp(procurado, vetor[num_fichas-1].nome) == 0) return num_fichas-1;
	 else if(strcmp(procurado, vetor[num_fichas-1].nome) > 0) 
	 return procurarRec(procurado, vetor, num_fichas-1); 
	 else return -1; 	
		
	}
***********************************************************************************

4) Refaça a funcionalidade de exclusão de modo a não ter que copiar todos os
elementos abaixo do excluído.

	Código a ser substituído:
				int j;
			        for(j=i+1; j<fichas_existentes; j++)
			        {
				    	agenda[j-1] = agenda[j];
			        }
			        fichas_existentes--;
			        proxima--;


5) Refaça o procurar de modo a trabalhar mesmo com pedaços de nomes (dica:
pesquise uma função chamada "strstr").

DICA: exemplo de uso da função strstr()
--------

#include <stdio.h>
#include <string.h>
int main () {
	char texto[20] = "Joao da Silva";
	char pedaco1[10] = "Silva";
	char pedaco2[10] = "Santos";
	
	if(strstr(texto, pedaco1) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
		pedaco1, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco1, texto);
		
	if(strstr(texto, pedaco2) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
		pedaco2, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco2, texto);
	return 0;
}


6) Crie uma funcionalidade de alterar (Update do crUd).
*******************************************************************************/

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

/*
int procurar(char procurado[], struct ficha vetor[], int num_fichas)
{ 
	int i;
	for(i=0; i<num_fichas; i++)
	{
		// strcmp() =  função que retorna o numero de caracteres diferentes na comparação
	    if(strcmp(procurado, vetor[i].nome) == 0)
		{
		 return i;
		}
	}
	return -1;					
}
*/

// --------------------------------------- RESPOSTA 5 ---------------------------------------------------
int procurar(char procurado[], struct ficha vetor[], int num_fichas, int indice_inicial)
{ 
	int i;
	for(i=indice_inicial; i<num_fichas; i++)
	{
		
		// OBS: a ordem das variaveis de procura é invertida entre as funções strstr() e strcmp()
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
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Update:");
		printf("\n6) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') //**************Inserir**************************
		{   
		    printf("\n-------------------------------------");
			printf("\nEntre com um nome: ");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone: ");
			gets(agenda[proxima].telefone);
			printf("\nEntre com um email:");
			gets(agenda[proxima].email);
			printf("\nEntre com o local de nascimento:");
			gets(agenda[proxima].naturalidade);
			printf("\nEntre com o UF de nascimento:");
			gets(agenda[proxima].UF_Nasc);
			printf("\nEntre com a data de nascimento:");
			gets(agenda[proxima].dataNasc);
			printf("\nEntre com o nome do endereco:");
			gets(agenda[proxima].rua);
			printf("\nEntre com o numero do endereco:");
			gets(agenda[proxima].numero);
			printf("\nEntre com o bairro:");
			gets(agenda[proxima].bairro);
			printf("\nEntre com o municipio:");
			gets(agenda[proxima].municipio);
			printf("\n-------------------------------------");
		  	agenda[proxima].ativo = true;
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //******************procurar************************
		{
			char procurado[40];
			int incremento=0;
			int selec=1;
			printf("\nEntre com o nome procurado:");
			gets(procurado);
			
			while (selec==1)
			{
    			int i = procurar(procurado, agenda, fichas_existentes,incremento);
    			if(i>=0) 
    			{
    			    
    			    printf("\n-------------------------------------");
    				printf("\nOs dados de %s são:", agenda[i].nome);
    				printf("\nTelefone: %s", agenda[i].telefone);
					printf("\nEmail: %s", agenda[i].email);
					printf("\nNaturalidade: %s", agenda[i].naturalidade);
					printf("\nEstado de nascimento: %s", agenda[i].UF_Nasc);
					printf("\nData de nascimento: %s", agenda[i].dataNasc);
					printf("\nNome do endereco: %s", agenda[i].rua);
					printf("\nNumero: %s", agenda[i].numero);
					printf("\nBairro: %s", agenda[i].bairro);
					printf("\nMunicipio: %s", agenda[i].municipio);
					printf("\n-------------------------------------");
    				incremento++;
    				printf("\nDeseja verificar se existem nomes parecidos no banco de dados? 1:sim /0:Nao ");
    				scanf("%i", &selec);
    			}
    			else 
    			{
    			printf("\n\nNome não encontrado\n");
    			selec=0;
    			}
			}
			selec=1;
			incremento=0;
		}
		
		if(opcao[0] == '3') //*****************Listar tudo********************
		{
			//printf("\n\n");
			printf("==== Dados existentes ====\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
		     	if(agenda[i].ativo == true)
		     	{
					printf("\n-------------------------------------");
    				printf("\nOs dados de %s são:", agenda[i].nome);
    				printf("\nTelefone: %s", agenda[i].telefone);
					printf("\nEmail: %s", agenda[i].email);
					printf("\nNaturalidade: %s", agenda[i].naturalidade);
					printf("\nEstado de nascimento: %s", agenda[i].UF_Nasc);
					printf("\nData de nascimento: %s", agenda[i].dataNasc);
					printf("\nNome do endereco: %s", agenda[i].rua);
					printf("\nNumero: %s", agenda[i].numero);
					printf("\nBairro: %s", agenda[i].bairro);
					printf("\nMunicipio: %s", agenda[i].municipio);
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
					printf("\nEmail: %s", agenda[i].email);
					printf("\nNaturalidade: %s", agenda[i].naturalidade);
					printf("\nEstado de nascimento: %s", agenda[i].UF_Nasc);
					printf("\nData de nascimento: %s", agenda[i].dataNasc);
					printf("\nNome do endereco: %s", agenda[i].rua);
					printf("\nNumero: %s", agenda[i].numero);
					printf("\nBairro: %s", agenda[i].bairro);
					printf("\nMunicipio: %s", agenda[i].municipio);
					
					
				printf("\nDeseja realmente excluir esses dados? 0:Não/1: Sim");	
				scanf("%i", &excluir);
			
				if (excluir==1) agenda[i].ativo = false;
			}
			
			else printf("\n\nNome não encontrado\n");	
		}
		
		if(opcao[0] == '5') //*****************Update********************
		{
			bool opInvalida = false;
			int selecao;
			char procurado[40];
			printf("\nEntre com o nome que sera atualizado:");
			gets(procurado);
			
			int i = procurar(procurado, agenda, fichas_existentes,0);
			
			if(i>=0)
			{       
			        printf("\n\nA Ficha de %s será editada!", agenda[i].nome);
				    printf("\n-------------------------------------");
        			printf("\nEntre com um nome: ");
        			gets(agenda[i].nome);
        			printf("\nEntre com um telefone: ");
        			gets(agenda[i].telefone);
        			printf("\nEntre com um email:");
        			gets(agenda[i].email);
        			printf("\nEntre com o local de nascimento:");
        			gets(agenda[i].naturalidade);
        			printf("\nEntre com o UF de nascimento:");
        			gets(agenda[i].UF_Nasc);
        			printf("\nEntre com a data de nascimento:");
        			gets(agenda[i].dataNasc);
        			printf("\nEntre com o nome do endereco:");
        			gets(agenda[i].rua);
        			printf("\nEntre com o numero do endereco:");
        			gets(agenda[i].numero);
        			printf("\nEntre com o bairro:");
        			gets(agenda[i].bairro);
        			printf("\nEntre com o municipio:");
        			gets(agenda[i].municipio);
        			
        			printf("\n-------------------------------------");
			    	agenda[i].ativo = true;
			}
			else printf("\n\nNome não encontrado\n");
			
		}		
	}
	return 0;
}
 



