//TAD
#include<stdio.h>
#include<stdlib.h>

//Tipos de datos personalizados
typedef char string[50];
typedef struct{
		long long nroCuenta;
		string nombreCliente;
		} tCliente;
		
//Punteros		
FILE * archivoTexto;
FILE * archivoTextoNuevo;

//Interfaz
void cargarArchivos();
void procesarArchivos();
void finalizarPrograma();

//Implementacion de funciones
//Cargar un archivo en modo lectura(r) y cargar otro en modo escritura(w) al que se va a cargar el backup
void cargarArchivos() {
	archivoTexto = fopen("clientes.txt", "r");
	archivoTextoNuevo = fopen("clientes_backup.txt", "w");
	printf("\n---------------------------------\n");
	if(archivoTexto == NULL || archivoTextoNuevo == NULL) {
		printf("\nError al abrir o crear el archivo original/de respaldo!");
		exit( EXIT_FAILURE );
	} else {
		printf("\nArchivos abiertos!\n");
	}
}

void procesarArchivos() {
	tCliente cliente;
	int contador = 0;
	printf("\nProcesando archivos...\n");
	
	/*fscanf(archivoTexto,"%d %[^\n]", &cliente.nroCuenta, cliente.nombreCliente);
	while(!feof(archivoTexto)) {
		fprintf(archivoTextoNuevo,"%d %s\n", cliente.nroCuenta, cliente.nombreCliente);
		fscanf(archivoTexto,"%d %[^\n]", &cliente.nroCuenta, cliente.nombreCliente);
		contador++;
	} */
	
	//la expresion %[^\n] no necesita la s al final. Ya que lee caracteres hasta el salto.
	//fscanf con return == 2 para verificar que los datos se reciban en el formato correcto.
	string titulo1 = "COPIA DE SEGURIDAD DE CLIENTES DEL BANCO";
	string titulo2 = "NUM DE CUENTA";
	string titulo3 = "APELLIDO Y NOMBRE DE CLIENTE\n";
	fprintf(archivoTextoNuevo,"%s \n%s  %s", titulo1,titulo2, titulo3);

	while (fscanf(archivoTexto, "%lld %[^\n]s", &cliente.nroCuenta, cliente.nombreCliente) == 2) {
        // Escribimos en el archivo nuevo
        fprintf(archivoTextoNuevo, "%lld    %s\n", cliente.nroCuenta, cliente.nombreCliente);
        contador++;  // Incrementar el contador
	}
    printf("\nSe han copiado %d registros al backup!\n", contador);
	
}

void finalizarPrograma(){
	fclose(archivoTexto);
	fclose(archivoTextoNuevo);
	printf("\nSe han cerrado los archivos! \n");
}
