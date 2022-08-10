#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int times = 4, colunas = 4, x = 0;
	int tabela[10][4];
	int ColunaVitorias = 0;
	int ColunaEmpates = 1;
	int ColunaDerrotas = 2;
	int ColunaTotalPontos = 3;
	int vitorias = 0;
	int empates = 0;
	int derrotas = 0;
	int PontosPrimeiro = 0;
	int PontosSegundo = 99;
	int PontosTerceiro = 99;
	int TimePrimeiro = 0;
	int TimeSegundo = 0;
	int TimeTerceiro = 0;

	for (x = 1; x < times; x++)
	{
		printf("\n =========== TIME %d ============== ", x);
		printf("\n Informe as vitorias do time %d: ", x);
		scanf("%d",&vitorias);

		printf(" Informe os empates do time %d: ", x);
		scanf("%d",&empates);

		printf(" Informe as derrotas do time %d: ", x);
		scanf("%d",&derrotas);

		tabela[x][ColunaVitorias] = vitorias * 3;
		tabela[x][ColunaEmpates] = empates * 1;
		tabela[x][ColunaDerrotas] = derrotas * 0;
		tabela[x][ColunaTotalPontos] = tabela[x][ColunaVitorias] + tabela[x][ColunaEmpates] + tabela[x][ColunaDerrotas];

		printf("\n >>>>>> RESULTADO DO TIME %d: %d PONTOS <<<<<<< \n ", x, tabela[x][ColunaTotalPontos]);

		if (tabela[x][ColunaTotalPontos] > PontosPrimeiro)
		{
			TimePrimeiro = x;
			PontosPrimeiro = tabela[x][ColunaTotalPontos];
		}

		if (tabela[x][ColunaTotalPontos] < PontosTerceiro)
		{
			TimeTerceiro = x;
			PontosTerceiro = tabela[x][ColunaTotalPontos];
		}

    if (PontosPrimeiro > PontosSegundo && PontosPrimeiro> PontosTerceiro)
		{
			TimePrimeiro = PontosPrimeiro;
			TimeSegundo = PontosSegundo;
			TimeTerceiro = PontosTerceiro;

			PontosPrimeiro = TimePrimeiro;

			if (PontosSegundo > PontosTerceiro)
			{
				PontosSegundo = TimeSegundo;
				PontosTerceiro = TimeTerceiro;
			}
			else
			{
				PontosSegundo = TimeTerceiro;
				PontosTerceiro = TimeSegundo;
			}

		}

	if (PontosSegundo > PontosPrimeiro  && PontosSegundo > PontosTerceiro)
		{	
			TimePrimeiro = PontosPrimeiro;
			TimeSegundo = PontosSegundo;
			TimeTerceiro = PontosTerceiro;

			PontosPrimeiro = TimeSegundo;

			if (PontosPrimeiro > PontosTerceiro)
			{
				PontosSegundo = TimePrimeiro;
				PontosTerceiro = TimeTerceiro;
			}
			else
			{
				PontosSegundo = TimeTerceiro;
				PontosTerceiro = TimePrimeiro;
			}
		
		}
		

	if (PontosTerceiro > PontosPrimeiro  && PontosTerceiro > PontosSegundo)
		{
			TimePrimeiro = PontosPrimeiro;
			TimeSegundo = PontosSegundo;
			TimeTerceiro = PontosTerceiro;

			PontosPrimeiro = TimeTerceiro;

			if (PontosPrimeiro > PontosSegundo)
			{
				PontosSegundo = TimePrimeiro;
				PontosTerceiro = TimeSegundo;

			}
			else
			{
				PontosSegundo = TimeSegundo;
				PontosTerceiro = TimePrimeiro;
			}

		}
		printf("\n ============ RESULTADO DO %d PASSO ============ ", x);
		printf("\n O primeiro colocado é o time %d com %d pontos  ", TimePrimeiro, PontosPrimeiro);
		printf("\n O segundo colocado é o time %d com %d pontos ", TimeSegundo, PontosSegundo);
		printf("\n O terceiro colocado é o time %d com %d pontos \n ", TimeTerceiro, PontosTerceiro);
	}
	printf("\n ============ RESULTADO FINAL ============ \n  ");
	printf("\n O primeiro colocado é o time %d com %d pontos  ", TimePrimeiro, PontosPrimeiro);
	printf("\n O segundo colocado é o time %d com %d pontos ", TimeSegundo, PontosSegundo);
	printf("\n O terceiro colocado é o time %d com %d pontos \n ", TimeTerceiro, PontosTerceiro);

}
