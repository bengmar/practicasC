/* 4. Dado un archivo de texto clientes.txt que contiene, en cada línea, los siguientes datos de clientes de un
banco: número de cuenta, nombre del cliente; realizar un programa que lea este archivo y copie el
contenido en un nuevo archivo de texto clientes_backup.txt. Visualizar al final la cantidad de registros
copiados */

#include<stdio.h>
#include "tad_clientes.h"
#define TITULO "BACKUP DE CLIENTES"


//Programa Principal
int main() {
	printf("\t---%s---", TITULO);
	cargarArchivos();
	procesarArchivos();
	finalizarPrograma();
	return 0;
}


