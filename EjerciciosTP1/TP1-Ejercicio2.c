#include <stdio.h>
#include <stdlib.h>

typedef int indice;
typedef indice *apuntIndice;

indice i;
apuntIndice apuntI;


int main(void) {
	/*2.a: Devuelve 0 ya que el apuntador no "apunta" a alguna dirección de memoria válida.
	Es buena practica en ese caso inicializar el apuntador en NULL.*/
    printf("contenido apuntI: %p\n", apuntI);   
    apuntI = NULL;
    printf("contenido apuntI: %p\n", apuntI);  
	
	printf("\n----------------------------\n\n");
	
    apuntI = malloc(sizeof(int));
    printf("contenido apuntI: %p\n", apuntI);
    printf("contenido *apuntI antes de guardar un valor: %d \n", *apuntI);
    *apuntI = 2;
    printf("contenido *apuntI con valor nuevo: %d\n", *apuntI);
    i = 4;
    printf("contenido luego de asignar a i el valor 4: %d", *apuntI);
    return 0;
}

/* 2.b: apuntI contiene la dirección de memoria que ya se ha asignado con el tamaño en bytes reservado correspondiente al tipo int.
*apuntI contiene lo que está almacenada en la dirección de memoria a la que apunta. Al inicio contiene un dato aleatorio. Luego
guardamos en esa dirección el dato de tipo entero 2*/
