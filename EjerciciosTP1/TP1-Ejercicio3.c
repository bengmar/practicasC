#include<stdio.h>
#include<stdlib.h>

char *eso;

int main(){
	
	eso = malloc(sizeof(int));
	printf("\neso: %d ", eso);
	return 0;
}
