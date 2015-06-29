#pragma once
#include <stdio.h>

typedef struct matrix{
public:
	// [a b c]
	// [d e f]
	// [g h i]
	int a,b,c,d,e,f,g,h,i;

	matrix(){}
	matrix(int A, int B, int C, int D, int E, int F, int G, int H, int I):a(A),b(B),c(C),d(D),e(E),f(F),g(G),h(H),i(I){ }

	int determinant();

	//				   [A D G]
	// invA = 1/detA * [B E H]
	// 				   [C F I]
	void invertModulo(int n);

}matrix;

void matrixDetCalc();

int modInt(int a, int n);

void gcdInt( int& d, int& s, int& t, int& a, int& b);

void matrixInvCalc();

void crt();
