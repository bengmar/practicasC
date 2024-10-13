#include<stdio.h>
#include "manipularListaDinamica.h"

/* prototipos de funciones */
void menu(tLista*);

/*Variables globales*/
tLista * lista;
	
int main() {
	inicializarLista(lista);
	menu(lista);
	return 0;
}

/* Definicion de funciones */

void menu(tLista* pLista) {
	int opcion = 0;
	do{
		printf("\nMENU DE OPCIONES");
		printf("\nOpcion 1: Agregar elementos");
		printf("\nOpcion 2: Visualizar elementos cargados");
		printf("\nOpcion 0: Salir");
		printf("\nOpcion elegida: ");
		scanf("%d", &opcion);
		
		switch(opcion) {
				case 1 : {
					tDato datos;
					printf("\nIngrese el id a asignar: ");
					scanf("%d", &datos.id);
					printf("\nIngrese la descripcion: ");
					fflush(stdin);
					scanf("%[^\n]s", datos.descripcion);
					cargarDatos(&pLista, datos);
					break;
				}
				case 2: {
					visualizarLista(pLista);
					break;
				}
				case 0: {
					printf("\nSaliendo...");
					break;
				}
				default:{
					printf("\nOpcion no valida. Reintentar!\n");
					break;
				}
		}
	} while(opcion != 0);
}
