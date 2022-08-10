#include <stdio.h>
#include <locale.h>

int procurarLinha(int L, int C, int mat[L][C], int procurado)
{ // Método para retornar a linha em que procurado aparece na matriz (A1 ou A2)
  int indLinha, indColuna, retorno = 0;

  for (indColuna = 0; indColuna < C; indColuna++)
  {
    for (indLinha = 0; indLinha < L; indLinha++)
    {
      if (mat[indLinha][indColuna] == procurado)
        retorno = indLinha;
    }
  }
  return retorno;
}

void diaSemana(int dia)
{ // Método para mostrar dia da Semana a partir do valor

  switch (dia)
  {

  case 0:
    printf("\nO dia é Domingo!");
    break;
  case 1:
    printf("\nO dia é Segunda!");
    break;
  case 2:
    printf("\nO dia é Terça!");
    break;
  case 3:
    printf("\nO dia é Quarta!");
    break;
  case 4:
    printf("\nO dia é Quinta!");
    break;
  case 5:
    printf("\nO dia é Sexta!");
    break;
  case 6:
    printf("\nO dia é Sábado!");
    break;
  }
}

//Calendário permanente de 1901 a 2092

int A1[28][4], A2[28][4];
int B[28][12] =
    {{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1}};
int C[7][6];

int main()
{
  int l, c, x;
  //populando a tabela A1
  x = -3;
  for (c = 0; c < 4; c++)
    for (l = 0; l < 28; l++, x++)
      if (x < 1)
        A1[l][c] = -1;
      else if (x < 100)
        A1[l][c] = x;
      else if (x == 100)
        A1[l][c] = 0;
      else
        A1[l][c] = -1;

  //populando a tabela A2
  x = -19;
  for (c = 0; c < 4; c++)
    for (l = 0; l < 28; l++, x++)
      if (x < 1)
        A2[l][c] = -1;
      else
        A2[l][c] = x;

  //populando a tabela C
  x = 1;
  for (c = 0; c < 6; c++)
    for (l = 0; l < 7; l++, x++)
      if (x > 37)
        C[l][c] = -1;
      else
        C[l][c] = x;

  int dia, mes, ano, resposta, soma;
  setlocale(LC_ALL, "Portuguese");
  printf("Entre com uma data no formato DD/MM/AAAA: ");
  scanf("%d/%d/%d", &dia, &mes, &ano);

  int valorB;
  int restoAno = ano % 100; // Separação das dezenas do ano
  int linha;                // Variável que vai utilizar o valor encontrado (linha na matriz do ano) para localizar na matriz do mês

  if (ano < 1901 || ano > 2092)
    printf("Erro!! O ano deve ser de 1901 a 2092.\n");

  else
  {

    if (ano >= 1901 && ano <= 2000)
    {
      linha = procurarLinha(28, 4, A1, restoAno); // Escolha da matriz A1, pois a 1ª dezena do ano está entre 19 e 20 e o resto (2ª dezena) do ano está entre 01 e 00

      valorB = B[linha][mes - 1]; // Valor localizado na matriz B
      soma = valorB + dia;        // Soma do valor da matriz B com o dia

      resposta = procurarLinha(7, 6, C, soma); // Variável resposta trará o valor da soma e procurará na na matriz C

      diaSemana(resposta); // Trará a resposta do switch case
    }
    else if (ano > 2000 && ano <= 2092)
    { // Escolha da matriz A2, pois a 1ª dezena do ano é 20 e o resto (2ª dezena) do ano está entre 01 e 92
      linha = procurarLinha(28, 4, A2, restoAno);

      valorB = B[linha][mes - 1]; // Valor localizado na matriz B
      soma = valorB + dia;        // Variável resposta trará o valor da soma e procurará na na matriz C

      resposta = procurarLinha(7, 6, C, soma); //resposta == linha onde se encontra valor da soma

      diaSemana(resposta); // Trará a resposta do switch case
    }
  }

  return 0;
}