/* TP3 
Escribir un programa que permita ingresar un n�mero entero positivo y luego, mediante una funci�n
recursiva, muestre el n�mero de forma invertida. Ej.: 123 - 321
*/
#include<stdio.h>
void mostrarInverso(int);

int main() {
	mostrarInverso(123);
	return 0;
}

void mostrarInverso(int pNum) {
	if(pNum<10) {
		printf("%d",pNum);
		return;
	}
	int num = pNum % 10;
	printf("%d", num);
	return mostrarInverso(pNum/10);
}
