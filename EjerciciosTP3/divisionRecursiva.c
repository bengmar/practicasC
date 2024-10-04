/*TP3 Recursividad
4. Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la
división matemática se define como una operación aritmética, que consiste en saber cuántas veces un
número (divisor) está contenido en otra cifra (dividendo).
*/
#include<stdio.h>
int divisionRecursiva(int, int);

int main() {
	int a = 13;
	int b = 2;
	
	printf("\nEl cociente de dividir %d entre %d es %d", a, b, divisionRecursiva(b,a));
	return 0;
}

int divisionRecursiva(int pDivisor, int pDividendo) {
	if(pDivisor > pDividendo) {
		return 0;
	}
	return divisionRecursiva(pDivisor, pDividendo - pDivisor ) + 1;	
}
