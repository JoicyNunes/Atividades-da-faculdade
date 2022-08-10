#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

    int main(int argc, char* argv[]) {
	float Arestas[10][3], PerEscaleno, PerIsoscele, PerEquilatero;
	int x, ColunaAresta1 = 0, ColunaAresta2 = 1, ColunaAresta3 = 2, IncremEscaleno=0, IncremIsoscele=0, IncremEquilatero=0,QtdTriangulos=3;
	
    for (x=0; x<QtdTriangulos; x++) {
		printf("Informe a médida da primeira aresta do triangulo %d: ", x+1);
		scanf("%f", &Arestas[x][ColunaAresta1]);

		printf("Informe a médida da segunda aresta do triangulo %d: ", x+1);
		scanf("%f", &Arestas[x][ColunaAresta2]);

		printf("Informe a médida da terceira aresta do triangulo %d: ", x+1);
		scanf("%f", &Arestas[x][ColunaAresta3]);
	}
	
	for (x=0; x<QtdTriangulos; x++) {
		if ((Arestas[x][ColunaAresta1] == Arestas[x][ColunaAresta2]) && (Arestas[x][ColunaAresta2] == Arestas[x][ColunaAresta3]) && (Arestas[x][ColunaAresta3] == Arestas[x][ColunaAresta1])) {
			IncremEquilatero = IncremEquilatero + 1;	
		}
		
		else	if ((Arestas[x][ColunaAresta1] == Arestas[x][ColunaAresta2]) || (Arestas[x][ColunaAresta2] == Arestas[x][ColunaAresta3]) || (Arestas[x][ColunaAresta3] == Arestas[x][ColunaAresta1])) {
			IncremIsoscele = IncremIsoscele + 1;	
		}
		
		else{
			IncremEscaleno = IncremEscaleno + 1;
		}
	}
	PerEquilatero=(IncremEquilatero*100.0)/QtdTriangulos;
	PerIsoscele=(IncremIsoscele*100.0)/QtdTriangulos;
	PerEscaleno=(IncremEscaleno*100.0)/QtdTriangulos;
	
	printf (" \n Equilátero %.f percento. Isóscele %.f percento. Escaleno %.f percento. ",PerEquilatero,PerIsoscele,PerEscaleno);

	printf(" \n FIM DO PROGRAMA ");
	
	return 0;
}