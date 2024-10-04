#include<stdio.h>
typedef int tArray[6];
tArray nums = {2,6,5,9,24,12};
int multiploDeTres(tArray, int);

int main(){
	
	printf("Multiplos de 3 totales: %d", multiploDeTres(nums, 6));
	return 0;
}

int multiploDeTres(tArray pNums, int pDimension) {
	if(pDimension == 0) {
		return 0;
	}
	else {
		if(pNums[pDimension-1]%3 == 0){
			return multiploDeTres(pNums, pDimension - 1) + 1;
		}
		else {
			return multiploDeTres(pNums,pDimension - 1);
		}
	}
}
