/*2 Escribir en lenguaje c, la declaración del tipo de dato tArbolTipoProductos
que corresponde al nodo dado, teniendo en cuenta que el árbol se balancea
según el campo codigo. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* declaración de tipos personalizados */
typedef char tString [25];

typedef struct {
	int codigo;
	tString descripcion;
}tDatos;

typedef struct nodo {
	tDatos datos;
	struct nodo * hijoIzquierdo, *hijoDerecho;
}tArbolTipoProductos;

tArbolTipoProductos * arbolProductos;

/* 3. Dado el siguiente nodo correspondiente a un árbol de búsqueda
binaria:
Escribir en lenguaje c, la declaración del tipo de dato tArbolTipoParientes
que corresponde al nodo dado, teniendo en cuenta que el árbol se balancea
según el campo código.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* declaración de tipos personalizados */
typedef char tString [25];

typedef struct {
	int codigo;
	tString parentesco;
}tDatosParentesco;

typedef struct nodo {
	tDatosParentesco datos;
	struct nodo * hijoIzquierdo, *hijoDerecho;
}tArbolTiposParientes;

tArbolTiposParientes * arbolParientes;
