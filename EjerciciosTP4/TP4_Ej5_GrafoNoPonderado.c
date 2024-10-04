/* Escribir en lenguaje C, la declaracion del tipo de dato tGrafoNoPonderado, para un grafo no ponderado
de hasta 7 vertices. Utilizar la implementacion de grafos con arrays. Ademas, escribir las funciones para:
a) iniciar el grafo
b) agregar un vertice al grafo
c) agregar un arco al grafo
d) visualizar la matriz de adyacencia de un grafo
*/

#include <stdio.h>
#include <stdbool.h>
#define N 7

/* Declaracion de tipos de datos personalizados */
typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
} tArco;

typedef bool conjuntoVertices[N];
typedef bool conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoNoPonderado;

/* Declaracion de los prototipos */
void inicializarGrafo( tGrafoNoPonderado * );
void agregarVertice( tGrafoNoPonderado * , int );
void agregarArco( tGrafoNoPonderado * , tArco);
int maximoVertice( tGrafoNoPonderado *);
void visualizarMatrizAdyacencia( tGrafoNoPonderado *);
bool existeVertice( tGrafoNoPonderado *, tVertice );
void menu(tGrafoNoPonderado *);

/* Declaracion de las variables globales */

/* Funcion principal */
int main() {

	tGrafoNoPonderado grafo;

	inicializarGrafo(&grafo );
	menu(&grafo);

	return 0;
}

void inicializarGrafo( tGrafoNoPonderado * pGrafo ) {
	int x, y;

	for( x=0; x<=N; x++ ) {
		pGrafo->vertices[x] = 0;
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y] = 0;
		}
	}
}

void menu(tGrafoNoPonderado * pGrafo){
	
	int opcion = 4;
	

	do {
		printf("\n\t***** MENU *****\n");
		printf("1- Agregar Vertice\n");
		printf("2- Agregar Arco\n");
		printf("3- Visualizar matriz de adyacencia\n");
		printf("4- Salir\n");
		printf("*Ingrese la opcion elegida: ");
		scanf("%d", &opcion);
		printf("\n");

		switch(opcion){
			case 1:{
				int vertice;
				printf("Ingrese el valor del vertice: ");
				scanf("%d", &vertice);
				agregarVertice(pGrafo, vertice);
				break;
			}
			case 2:{
				tArco arco;
				printf("\nIngrese el vertice de origen: ");
				scanf("%d", &arco.origen);
				printf("\nIngrese el vertice de destino: ");
				scanf("%d", &arco.destino);
				agregarArco(pGrafo, arco);
				break;
			}
			case 3:{
				visualizarMatrizAdyacencia(pGrafo);
				break;
			}
			case 4:{
				printf("\nHa decidido salir del programa");
				break;
			}
			default:{
				printf("\nOpcion no valida. Reintente\n");
				break;
			}	
		}
	}while(opcion != 4);
}

void agregarVertice( tGrafoNoPonderado * pGrafo, int pVertice) {

	pGrafo->vertices[pVertice] = 1;
	printf( "\nSe agrego el vertice %d\n", pVertice );
}

void agregarArco( tGrafoNoPonderado * pGrafo , tArco pArco)  {

	if( pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1 ) {
		pGrafo->arcos[pArco.origen][pArco.destino]= 1;
		printf( "\nSe agrego el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	}
}

int maximoVertice( tGrafoNoPonderado * pGrafo )  {
	int x, max;
	max = 0;

	for( x=0; x<N; x++ ) {
		if( pGrafo->vertices[x] == 1) {
			max = x;
		}
	}
	return max;
}

void visualizarMatrizAdyacencia( tGrafoNoPonderado * pGrafo )  {
	int x, y, maxVer;
	bool existeArista = false;

	maxVer= maximoVertice( pGrafo );

	/*Nota: Se muestra vertices del 1 al maximo encontrado(siempre menor a N). El vertice de la posicion 0 es ignorado.
	En cualquier caso cambiar x=1 e y=1 por x=0 e y=0 respectivamente */
	printf( "\n MATRIZ DE ADYACENCIA \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo->arcos[x][y] == true ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );
			if( existeArista ) {
				printf("1 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

bool existeVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	return pGrafo->vertices[pVertice] == 1;
}
