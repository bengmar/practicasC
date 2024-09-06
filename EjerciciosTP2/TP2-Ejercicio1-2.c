/* 1. Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
del primer nodo almacenado.
2. Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una
lista enlazada:
a) Generar o inicializar la lista.
b) Función para determinar si una lista está vacía.
c) Insertar el primer producto (nodo) de la lista.
d) Insertar un producto al principio de la lista.
e) Eliminar el primer producto de la lista.
f) Insertar un producto en una determinada posición dentro de la lista.
g) Eliminar un producto de una determinada posición de la lista.
h) Visualizar todos los datos de los productos que están en la lista
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* Tipos de datos personalizados */

typedef char tString[21];
typedef struct {
	int codProducto;
	tString descripcion;
	float precioUnitario;
} tProducto;

typedef struct nodo{
	tProducto producto;
	struct nodo * siguiente;
} tListaProductos;

tListaProductos * listaProductos;

/* Prototipos de funciones */
bool listaVacia(tListaProductos *);
void inicializarLista();
tProducto cargarProducto();
void insertarProducto(tProducto);
void insertarPrimero(tProducto);
void insertarAdelante(tProducto);
void insertarK(int, tProducto);
void eliminarPrimero();
void visualizarProductos(tListaProductos *);
void eliminarK(int);
void menu();

/* Funcion principal */
int main() {
	inicializarLista();
	menu();
	return 0;
}

/* Definicion de funciones */
bool listaVacia(tListaProductos * pLista) {
	return (pLista == NULL);
}

void inicializarLista() {
	listaProductos = NULL;
}

tProducto cargarProducto() {
	char control[50];
	tProducto producto;
	printf("\nIngrese el codigo de producto: ");
	scanf("%d", &producto.codProducto);
	printf("\nIngrese la descripcion del producto: ");
	fflush(stdin);
	scanf("%[^\n]s", &control);
	if(strlen(control)>20){
		printf("\nLa descripcion debe tener 20 caracteres como maximo. Reintente.");
		printf("\nIngrese la descripcion del producto: ");
		fflush(stdin);
		scanf("%[^\n]s", &control);
	}
	strcpy(producto.descripcion, control);
	printf("\nIngrese el precio unitario del producto $ ");
	scanf("%f", &producto.precioUnitario);
	return producto;
	
}

void insertarProducto(tProducto pProducto){
	if(listaVacia(listaProductos)) {
		insertarPrimero(pProducto);
	} 
	else {
		insertarAdelante(pProducto);	
	}
}

void insertarPrimero(tProducto pProducto) {
	tListaProductos * nuevoNodo;
	nuevoNodo = (tListaProductos *) malloc(sizeof(tListaProductos));
	nuevoNodo->producto = pProducto;
	nuevoNodo->siguiente = NULL;
	listaProductos = nuevoNodo;
	printf("\nSe ha insertado el primer producto!\n");
}

void insertarAdelante(tProducto pProducto) {
	tListaProductos * nuevoNodo;
	nuevoNodo = (tListaProductos *) malloc(sizeof(tListaProductos));
	nuevoNodo->producto = pProducto;
	nuevoNodo->siguiente = listaProductos;
	listaProductos = nuevoNodo;
	printf("\nSe ha insertado correctamente el producto!");
}

void insertarK(int k, tProducto pProducto) {
	if(k<=0){
		printf("\nValor de posicion no valido.\n");
	}
	if(listaVacia(listaProductos)){
		printf("\nLa lista estaba vacia. Se insertara al inicio.\n");
		insertarPrimero(pProducto);
		return;
	}
	
	
	if(k == 1){
		insertarAdelante(pProducto);
		return;
	}
	int longitud = 0;
	tListaProductos *aux, *nuevoNodo;
	nuevoNodo = malloc(sizeof(tListaProductos));
	nuevoNodo->producto = pProducto;
	
	aux = listaProductos;
	while(aux != NULL) {
		longitud++;
		if(longitud == k-1){
			break;
		}
		aux = aux->siguiente;
	}
	if(longitud < k-1){
		printf("\nNo se puede insertar el producto en la posicion %d. La lista solo tiene %d posiciones actualmente\n", k, longitud);
		free(nuevoNodo);
		return;
	}
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	printf("\nProducto insertado en la posicion %d", k);
}


void eliminarPrimero() {
	tListaProductos * nodoASuprimir;
	nodoASuprimir = listaProductos;
	listaProductos = nodoASuprimir->siguiente; // Tambien listaProductos->siguiente
	free(nodoASuprimir);
	nodoASuprimir = NULL;
	printf("\nUltimo producto ingresado eliminado!\n");
}

void visualizarProductos(tListaProductos * pLista){
	tListaProductos * aux;
	aux = pLista;
	
	if(!listaVacia(pLista)) {
		printf("\n*** Productos Cargados ***\n");
		while(aux != NULL) {
			printf("%5d | %10s | $%4.2f\n",aux->producto.codProducto, aux->producto.descripcion, aux->producto.precioUnitario);
			aux = aux->siguiente;
		}
	} else {
		printf("\n*** No hay productos cargados para mostrar ***\n");
	}
	printf("\n");
}

void eliminarK(int k) {
	tListaProductos * nodoASuprimir, * aux;
	aux = listaProductos;
	int i;
	
	for(i = 1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	nodoASuprimir = aux->siguiente;
	aux->siguiente = nodoASuprimir->siguiente;
	free(nodoASuprimir);
	nodoASuprimir = NULL;
	printf("\nEl producto de la posicion %d ha sido eliminado con exito!\n", k);
}

void menu(){
	printf("\n***Gestion de productos***\n");
	int opcion = 1;
	while(opcion!=0) {
		printf("\n------------------------------\n");
		printf("**Opciones**\n");
		printf("Opcion 1: Cargar un producto\n");
		printf("Opcion 2: Cargar un producto en una posicion determinada.\n");
		printf("Opcion 3: Eliminar el ultimo producto cargado\n");
		printf("Opcion 4: Eliminar un producto determinado\n");
		printf("Opcion 5: Visualizar productos cargados\n");
		printf("Envie 0 por teclado para finalizar\n");
		printf("*Opcion elegida: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
			case 0: {
					printf("\n\t***Ha decidido finalizar el programa***");
					break;
			}	
			case 1: {
					insertarProducto(cargarProducto());
					break;
			}
			case 2: {
					int k;
					printf("\n*Ingrese la posicion del producto a agregar: \n");
					scanf("%d", &k);
					insertarK(k,cargarProducto());
					break;
			}
			case 3: {
					eliminarPrimero();
					break;
			}		
			case 4: {
					int k;
					printf("\n*Ingrese la posicion del producto a eliminar: \n");
					scanf("%d", &k);
					eliminarK(k);
					break;
			}
			case 5: {
					visualizarProductos(listaProductos);
					break;
			}		
			default: printf("\nOpcion no valida =X .Reintente!\n");
		}
	}
}
