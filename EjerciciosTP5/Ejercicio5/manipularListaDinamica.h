/* Escribir un TDA para cargar y mostrar los elementos de una lista dinámica, en donde el nodo tenga un
campo identificador de tipo entero y un campo descripción de tipo cadena de caracteres. Luego desarrolle
un programa para probar dicho TDA. */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* Tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	int id;
	tString descripcion;
} tDato;

typedef struct nodo {
	tDato dato;
	struct nodo * siguiente;
} tLista;

/* Interfaz */
void inicializarLista(tLista*);
bool listaVacia(tLista*);
void cargarDatos(tLista**, tDato);
void visualizarLista(tLista*);

/* Implementacion de funciones */

void inicializarLista(tLista * pLista) {
	pLista = NULL;
}

bool listaVacia(tLista * pLista) {
	return pLista == NULL;
}

void cargarDatos(tLista** pLista, tDato pDato){
	tLista * nuevoNodo;
	nuevoNodo = (tLista*)malloc(sizeof(tLista));
	if(listaVacia(*pLista)){
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = NULL;
	} else {
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = *pLista;
	}
	*pLista = nuevoNodo;
	printf("\nElemento agregado!\n");
}

void visualizarLista(tLista* pLista) {
	tLista * aux;
	aux = pLista;
	if(listaVacia(pLista)){
		printf("\nLista vacia!\n");
		free(aux);
		return;
	}
	printf("\nElementos guardados\n");
	while(aux != NULL){
		printf("%3d | %s \n", aux->dato.id, aux->dato.descripcion);
		aux = aux->siguiente;
	}
}
