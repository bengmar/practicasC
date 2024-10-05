/* Escribe en lenguaje c, la declaración de un tipo de dato tGrafoPonderado para un grafo ponderado de
hasta 10 vertices, donde el peso corresponde a kg. Utilizar la implementación de grafos con arrays.
Ademas, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo
c) agregar un arco al grafo
d) visualizar la matriz de pesos
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

/* Declaracion de tipos de datos personalizados */
typedef int tVertice;

typedef float tPeso;

typedef struct {
	tVertice origen;
	tVertice destino;
	tPeso peso;
}tArco;

typedef bool conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoPonderado;

/*Prototipado de funciones*/
void inicializarGrafo(tGrafoPonderado*);
void agregarVertice(tGrafoPonderado*, tVertice);
void agregarArco(tGrafoPonderado*, tArco);
void visualizarMatrizPesos(tGrafoPonderado*);
int maximoVertice(tGrafoPonderado*);
bool existeVertice(tGrafoPonderado*, tVertice);
void menu(tGrafoPonderado*);

/* Funcion principal */
int main() {
	tGrafoPonderado grafo;
	inicializarGrafo(&grafo);
	menu(&grafo);
	return 0;
}

/* Definicion de funciones */
void inicializarGrafo(tGrafoPonderado* pGrafo) {
	int x, y;
	for(x=0; x<N; x++) {
		pGrafo->vertices[x] = 0;
		for(y=0; y<N; y++) {
			pGrafo->arcos[x][y] = 0.0;
		}
	}
	printf("\nGrafo ponderado inicializado!");
}

void agregarVertice(tGrafoPonderado * pGrafo, tVertice pVertice) {
	if(pVertice < N) {
		pGrafo->vertices[pVertice] = true;
		printf("\nVertice activado!");
	} else {
		printf("Vertice no valido. Debe ser menor a %d ", N);
	}
	
}

void agregarArco(tGrafoPonderado * pGrafo, tArco pArco) {
	if(pGrafo->vertices[pArco.origen] != 0 && pGrafo->vertices[pArco.destino] != 0) {
		pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
		printf("\nArco(%d,%d) activado correctamente", pArco.origen, pArco.destino);
	} else {
		printf("\nArco invalido. Razon: ");
		if(!existeVertice(pGrafo, pArco.origen) && !existeVertice(pGrafo, pArco.destino)) {
			printf("Los vertices %d y %d no se encuentran activados!", pArco.origen, pArco.destino);
		} else if (!existeVertice(pGrafo, pArco.origen)){
			printf("El vertice %d no se encuentra activado!", pArco.origen);
		} else {
			printf("El vertice %d no se encuentra activado!", pArco.destino);
		}
	}
}

int maximoVertice(tGrafoPonderado * pGrafo) {
	int x;
	int max = 0;
	for(x=0; x<N; x++) {
		if(pGrafo->vertices[x] == 1){
			max = x;
		}
	}
	return max;
}

bool existeVertice(tGrafoPonderado * pGrafo, tVertice pVertice) {
	return pGrafo->vertices[pVertice] == 1;
}

void visualizarMatrizPesos(tGrafoPonderado * pGrafo) {
	int x, y;
	int maximo = maximoVertice(pGrafo);
	printf("\n\tMATRIZ DE PESOS\n");
	//Se visualiza desde el vertice 1 hasta N-1
	for(x=1; x<=maximo; x++) {
		for(y=1; y<=maximo; y++){
			if((pGrafo->arcos[x][y] != 0.0) && existeVertice(pGrafo,x) && existeVertice(pGrafo, y)) {
				printf(" %.2f |", pGrafo->arcos[x][y]);
			} else {
				printf(" 00.00 |");
			}
		}
		printf("\n");
	}
}

void menu(tGrafoPonderado * pGrafo) {
	int opcion = 4;
	do {
		printf("\n\n\tMENU");
		printf("\nOpcion 1: Ingresar Vertice");
		printf("\nOpcion 2: Ingresar Arco");
		printf("\nOpcion 3: Visualizar Matriz De Pesos");
		printf("\nOpcion 4: Cerrar");
		printf("\n*OPCION ELEGIDA: ");
		scanf("%d", &opcion);
		
		switch(opcion) {
			case 1: {
				tVertice vertice;
				printf("\nIngrese el vertice: ");
				scanf("%d", &vertice);
				agregarVertice(pGrafo, vertice);
				break;
			}
			case 2: {
				tArco arco;
				printf("\nIngrese el vertice de origen del arco: ");
				scanf("%d", &arco.origen);
				printf("\nIngrese el vertice de destino del arco: ");
				scanf("%d", &arco.destino);
				printf("\nIngrese el peso a almacenar en el arco: ");
				scanf("%f", &arco.peso);
				agregarArco(pGrafo, arco);
				break;
			}
			case 3: {
				visualizarMatrizPesos(pGrafo);
				break;
			}
			case 4: {
				printf("\nCerrando el programa...");
				break;
			}
			default: {
			 		printf("\nOpcion no valida. Reintente");
					break;
			}
			
		}
	} while(opcion != 4);
}

