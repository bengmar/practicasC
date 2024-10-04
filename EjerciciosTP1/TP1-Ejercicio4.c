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

/*En la opci�n 1 lo que ocurre es que se produce un error ya que se est� intentando resolver una direcci�n
 de memoria que no est� asignada (ya que el puntero no se inicializ�) e intentando guardar all� la direcci�n 
 del espacio que se intenta reservar.
 En la opcion 2 lo que se hace es guardar en la variable eso de tipo puntero la direcci�n de memoria que tendr� 
 un espacio del tama�o de un tipo int.
 */
