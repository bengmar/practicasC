#include <stdio.h>
#include <stdlib.h>

// prototipos de funciones
void opcion1();
void opcion2();

//variables globales
char *eso;

//funcion main
int main(void) {
    
    //opcion1();
    opcion2();
    return 0;
}

//definicion de funciones
void opcion1() {
    *eso = malloc(sizeof(int));
    printf("Lo que contiene donde apunta eso es: %c \n", *eso);
    printf("La direccion donde apunta eso es: %p \n", eso);
}

void opcion2() {
    eso = malloc(sizeof(int));
    printf("Lo que contiene donde apunta eso es: %c \n", *eso);
    printf("La direccion donde apunta eso es: %p \n", eso);
}

/*En la opción 1 lo que ocurre es que se produce un error ya que se está intentando resolver una dirección
 de memoria que no está asignada (ya que el puntero no se inicializó) e intentando guardar allí la dirección 
 del espacio que se intenta reservar.
 En la opcion 2 lo que se hace es guardar en la variable eso de tipo puntero la dirección de memoria que tendrá 
 un espacio del tamaño de un tipo int.
 */
