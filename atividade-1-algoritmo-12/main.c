#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	int vestibular[10][3]; 
	int erro = 0; 
	int cadastrado = 0; 
	int CPF = 0; 
	int idade = 0;
	int curso = 0; 
	int cadastros = 10;
	int ColunaCPF = 0; 
	int ColunaIdade = 1;
	int ColunaCurso = 2; 
	int ADS = 0;
	int GECOM = 0; 
	int EVENTOS = 0;
	int RH = 0; 
	int SomaIdade = 0;
	float MediaIdade;

	for (int x = 0; x < cadastros; x++)
	{
		printf("\nInforme o CPF do aluno %d: ", x);
		scanf("%d", &CPF);
		cadastrado = 0;


		for (int y = 0; y < cadastros; y++)
		{
			if (vestibular[y][ColunaCPF] == CPF)
			{
				printf("\nCPF já Cadastrado!\n");
				x = x - 1;
				cadastrado = 1;
			}
		}

		if (cadastrado == 0)
		{
			vestibular[x][ColunaCPF] = CPF;
			printf("\nCPF cadastrado com sucesso!\n");

			erro = 0;
			do
			{
				printf("\nInforme a idade do aluno %d: ", x);
				scanf("%d",&idade);
				if (idade>1&&idade<150){
					vestibular[x][ColunaIdade] = idade;
					SomaIdade=SomaIdade+vestibular[x][ColunaIdade];
					erro = 1;
				}
				else
				{
					printf("Idade valida! \n ");
					erro = 0;
				}
			} while (erro == 0);

			erro = 0;

			do
			{
				printf("\nInforme o curso desejado do aluno %d 1-ADS, 2-GECOM, 3-EVENTOS, 4-RH: ", x);
				scanf("%d",&curso);


				if (curso == 1 || curso == 2 || curso == 3 || curso == 4)
				{
					vestibular[x][ColunaCurso] = curso;

					switch (curso)
					{
					case 1:
					{
						ADS = ADS + 1;
						break;
					};

					case 2:
					{
						GECOM = GECOM + 1;
						break;
					};

					case 3:
					{
						EVENTOS = EVENTOS + 1;
						break;
					};
					case 4:
					{
						RH = RH + 1;
						break;
					};
					}
					erro = 1;
				}
				else
				{
					printf("Opção inválida!\n");
					erro = 0;
				}
			} while (erro == 0);

			erro = 0;
		}
	}

	MediaIdade = SomaIdade / cadastros;
	printf("A média de idade dos inscritos é de %2.f anos \n", MediaIdade);
	printf("Foram inscritos %d alunos no curso de ADS. %d alunos no curso de GECOM. %d alunos no curso de EVENTO e %d alunos no curso de RH.\n", ADS, GECOM, EVENTOS, RH);

	return 0;

}
