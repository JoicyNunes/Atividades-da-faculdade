#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pixel
{	int R, G, B;
} PIXEL;

void limparImagem(PIXEL** original, int linhas, int colunas, int maxValor)
{	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
		{	original[l][c].R = 255;
			original[l][c].G = 255;
			original[l][c].B = 255;
		}
	}
}

void Franca(PIXEL** original, int linhas, int colunas, int maxValor)
{	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<(colunas*0.33); c++)
		{	original[l][c].R = 0;
			original[l][c].G = 255;
			original[l][c].B = 0;
		}
		for(c=(colunas*0.34); c<(colunas*0.67); c++)
		{	original[l][c].R = 255;
			original[l][c].G = 255;
			original[l][c].B = 255;
		}
		for(c=(colunas*0.68); c<colunas; c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
		

}
//CARACOL
void caracol(PIXEL** original, int linhas, int colunas, int maxValor)
{	int l, c;
//reta >
	for(l=(linhas*0.1); l<(linhas*0.15); l++)
	{	for(c=0; c<(colunas*0.98); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}		
	}
//descida	
	for(l=(linhas*0.15); l<(linhas*0.95); l++)
	{	for(c=(colunas*0.95); c<(colunas*0.98); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//reta <	
	for(l=(linhas*0.9); l<(linhas*0.95); l++)
	{	for(c=(colunas*0.2); c<(colunas*0.98); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//subida	
	for(l=(linhas*0.3); l<(linhas*0.95); l++)
	{	for(c=(colunas*0.2); c<(colunas*0.23	); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//reta >	
	for(l=(linhas*0.3); l<(linhas*0.35); l++)
	{	for(c=(colunas*0.2); c<(colunas*0.8); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//descida	
	for(l=(linhas*0.35); l<(linhas*0.75); l++)
	{	for(c=(colunas*0.77); c<(colunas*0.8); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//reta <	
	for(l=(linhas*0.7); l<(linhas*0.75); l++)
	{	for(c=(colunas*0.4); c<(colunas*0.77); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//subida	
	for(l=(linhas*0.45); l<(linhas*0.75); l++)
	{	for(c=(colunas*0.37); c<(colunas*0.4); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//reta >	
	for(l=(linhas*0.45); l<(linhas*0.5); l++)
	{	for(c=(colunas*0.37); c<(colunas*0.6); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//descida	
	for(l=(linhas*0.5); l<(linhas*0.65); l++)
	{	for(c=(colunas*0.57); c<(colunas*0.6); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}
//reta <	
	for(l=(linhas*0.6); l<(linhas*0.65); l++)
	{	for(c=(colunas*0.5); c<(colunas*0.57); c++)
		{	original[l][c].R = 249;
			original[l][c].G = 0;
			original[l][c].B = 0;
		}
	}	
//subida	
	for(l=(linhas*0.55); l<(linhas*0.6); l++)
	{	for(c=(colunas*0.5); c<(colunas*0.52); c++)
		{	original[l][c].R = 249;
			original[l][c].B = 0;
			original[l][c].G = 0;
		}
	}	
}


PIXEL** lerImagem(char * nomeArquivo, int *pLinhas, int *pColunas, int *pMaxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//leia tipo do arquivo
	char buffer[1001];
	fgets (buffer, 1000, fp); //Primeira linha
	if(strstr(buffer, "P3") == NULL) // o tipo de arquivo eh diferente de P3?
	{	printf( "\nErro no tipo do arquivo\n\n");
		exit(-2);
	}

	//leia comentario
	fgets (buffer, 1000, fp);
	
	//leia dados da imagem
	fscanf(fp, "%d%d%d", pColunas, pLinhas, pMaxValor);

	//criando a matriz
	PIXEL **mat;
	int i;
	mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
	for(i=0; i< *pLinhas; i++)
		mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

	int l, c;
	for(l=0; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
		{	fscanf(fp, "%d", &mat[l][c].R);
			fscanf(fp, "%d", &mat[l][c].G);
			fscanf(fp, "%d", &mat[l][c].B);
		}
	}
	fclose(fp);
	return mat;
}

void escreverImagem(char * nomeArquivo, PIXEL ** mat, int linhas, int colunas, int maxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	// Arquivo ASCII, para leitura
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//escreva tipo do arquivo
	fprintf (fp, "P3\n");
	//escreva comentario
	fprintf (fp, "#Figura modificada...\n");
	//colunas, linhas
	fprintf(fp, "%d %d\n", colunas, linhas);
	//maxValor
	fprintf(fp, "%d\n", maxValor);

	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
			fprintf(fp, "%d\n%d\n%d\n", mat[l][c].R, mat[l][c].G, mat[l][c].B);
	}
	fclose(fp);
}

int main(int argc, char * argv[])
{	char opcao[10]="0";
	int linhas=0, colunas=0, maxValor=0;
	PIXEL **mat=NULL;
	int tamanhoBorrao = 8;
	char nomeArquivo[100]="";
	char nomeArquivoLeitura[100]="";
	char nomeArquivoEscrita[100]="";
	while(opcao[0] != '6')
	{	printf("\n\nMini-photoshop\n\n");
		printf("1) Ler imagem\n");	
		printf("2) Gravar imagem\n");	
		printf("3) Limpar Imagem\n");	
		printf("4) Bandeira Franca\n");	
		printf("5) Caracol\n");
		printf("6) Sair\n");
		printf("\nEntre a opcao desejada: ");	
		fgets(opcao, 10, stdin);
		switch(opcao[0])
		{	case '1':
				printf("\n\nEntre com o nome da imagem (sem extensao): ");
				fgets(nomeArquivo, 100, stdin);
				nomeArquivo[strlen(nomeArquivo)-1]='\0';
				strcpy (nomeArquivoLeitura, nomeArquivo);
				strcat (nomeArquivoLeitura, ".ppm");
				mat = lerImagem(nomeArquivoLeitura, &linhas, &colunas, &maxValor);
				break;
			case '2':
				strcpy (nomeArquivoEscrita, nomeArquivo);
				strcat (nomeArquivoEscrita, "_editada.ppm");
				printf("\n\nA imagem sera salva como %s\n", nomeArquivoEscrita);
				escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
				break;
			case '3':
				limparImagem(mat, linhas, colunas, maxValor);
				break;
	
			case '4':
				franca(mat, linhas, colunas, maxValor);
				break;

			case '5':
				caracol(mat, linhas, colunas, maxValor);
				break;

		}
	}
	return 0;
}
