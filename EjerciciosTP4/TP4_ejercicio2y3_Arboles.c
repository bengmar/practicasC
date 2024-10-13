/*2 Escribir en lenguaje c, la declaraci�n del tipo de dato tArbolTipoProductos
que corresponde al nodo dado, teniendo en cuenta que el �rbol se balancea
seg�n el campo codigo. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* declaraci�n de tipos personalizados */
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

/* 3. Dado el siguiente nodo correspondiente a un �rbol de b�squeda
binaria:
Escribir en lenguaje c, la declaraci�n del tipo de dato tArbolTipoParientes
que corresponde al nodo dado, teniendo en cuenta que el �rbol se balancea
seg�n el campo c�digo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* declaraci�n de tipos personalizados */
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
