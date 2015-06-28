#include <stdlib.h>	// atoi
#include "gmphelper.h"
#include "mathlib.h"

int main(int argc, char **argv){
	int selectedFunc = 0;

	if(argc == 1){
		printf("function list: \n1: mod\n2: gcd\n3: exponentialMod\n4: matrixDet\n5: matrixInv\n\
			6: legendre\n7: jacobi\n");
		printf("select a function: ");
		scanf("%d", &selectedFunc);
	}
	else{
		selectedFunc = atoi(argv[1]);
	}
	

	switch(selectedFunc){
		case 1: divQrCalc(); break;
		case 2: gcdCalc(); break;
		case 3: exponentialModCalc(); break;
		case 4: matrixDetCalc(); break;
		case 5: matrixInvCalc(); break;
		case 6: legendre(); break;
		case 7: jacobi(); break;
		default: break;
	}

	return 0;
}