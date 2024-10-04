/*TP3 Recursividad
4. Escribir una funci�n que calcule la divisi�n entera entre 2 n�meros de manera recursiva. Recordar que la
divisi�n matem�tica se define como una operaci�n aritm�tica, que consiste en saber cu�ntas veces un
n�mero (divisor) est� contenido en otra cifra (dividendo).
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
