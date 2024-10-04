#include <stdio.h>
#include <windows.h>
 
int multiplicar(int , int);

int main() {
    int num1,num2;
    
  	printf("Ingresa el primer número entero positivo: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo número entero positivo: ");
    scanf("%d", &num2);
	   
    // Mostrar el resultado
    printf("las potencia de %d ** %d es: %d\n", num1, num2,  potencia(num1, num2));
    return 0;
}



int potencia(int pNum1, int pNum2) {
    if (pNum2 == 0) {	
        return 1;
    }
    else {
        return pNum1 * potencia(pNum1, pNum2 - 1);
    }
}

