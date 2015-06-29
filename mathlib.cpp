#include <stdio.h>
#include "mathlib.h"
#include <iostream>

using namespace std;

int matrix::determinant()
{
	return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
}

void matrixDetCalc()
{
	int a,b,c,d,e,f,g,h,i;
	printf("input matrix: \n");
	scanf("%d %d %d %d %d %d %d %d %d",
			&a, &b, &c, &d, &e, &f, &g, &h, &i);
	matrix A(a,b,c,d,e,f,g,h,i);
	printf("determinant = %d\n", A.determinant());
}

int modInt(int a, int n)
{
	int b = a%n;
	if(b<0)
	{
		b += n;
	}
	return b;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void gcdInt( int& d, int& s, int& t, int& a, int& b)
{
	// initialize variables
	int r0, r1;
	int s0(0), s1(1), t0(1), t1(0);
	int needSwap = 0;

	if(a > b)		// if a > b
	{
		r0 = b;			// set r0 to smaller value
		r1 = a;			// and r1 to bigger value
	}
	else
	{
		r0 = a;
		r1 = b;
		needSwap = 1;
	}

	int q, temp;
	while(r0 != 0)	// while r0 != 0
	{
		temp = r0;
		r0 = r1%r0; // q = r1/r0, r0 = r1%r0
		q = r1/temp;
		r1 = temp;

		s1 -= q*s0;		// s1 = s1 - q*s0				
		swap(s0, s1);	// swap s0, s1 -> s0 = s1 - q*s0, s1 = s0

		t1 -= q*t0;
		swap(t0, t1);
	}

	if(needSwap)
	{
		swap(s1, t1);
	}

	d = r1;
	s = s1;
	t = t1;
}

void matrix::invertModulo(int n)
{
	int detA = determinant();
	int gcd, s, t;
	gcdInt(gcd, s, t, detA, n);	// now s is multiplicative inverse of detA.
	int aa,bb,cc,dd,ee,ff,gg,hh,ii;
	aa = modInt((e*i - f*h)*s, n);
	bb = modInt((f*g - d*i)*s, n);
	cc = modInt((d*h - e*g)*s, n);
	dd = modInt((c*h - b*i)*s, n);
	ee = modInt((a*i - c*g)*s, n);
	ff = modInt((b*g - a*h)*s, n);
	gg = modInt((b*f - c*e)*s, n);
	hh = modInt((c*d - a*f)*s, n);
	ii = modInt((a*e - b*d)*s, n);

	matrix B(aa,dd,gg,bb,ee,hh,cc,ff,ii);
	*this = B;
}

void matrixInvCalc()
{
	int a,b,c,d,e,f,g,h,i;
	printf("input matrix: \n");
	scanf("%d %d %d %d %d %d %d %d %d",
			&a, &b, &c, &d, &e, &f, &g, &h, &i);
	int n;
	printf("input modulo: \n");
	scanf("%d", &n);

	matrix A(a,b,c,d,e,f,g,h,i);

	printf("determinant of A: %d\n", A.determinant());

	A.invertModulo(n);

	printf("inverse of A modulo n: \n");
	printf("%d	%d	%d\n%d	%d	%d\n%d	%d	%d\n", A.a, A.b, A.c, A.d, A.e, A.f, A.g, A.h, A.i);

}

void crt()
{
	int a,b,c,p,q,t;
	printf("Input 'a b c p q t', seperated by space:\n");
	printf("x = a mod p\nx = b mod q\nx = c mod t\n");
	cin >> a >> b >> c >> p >> q >> t;

	int n=p*q*t;
	int x[3]={0, 0, 0};
	int y[3]={0, 0, 0};
	int temp = q*t;
	int temp1 = 1;
	gcdInt(temp1, x[0], y[0], p, temp); // d s t a b
	temp = p*t;
	gcdInt(temp1, x[1], y[1], q, temp); // d s t a b
	temp = p*q;
	gcdInt(temp1, x[2], y[2], t, temp); // d s t a b

	int result = q*t*y[0]*a + p*t*y[1]*b + p*q*y[2]*c;
	result = modInt(result, n);

	cout << "result is " << result << '\n';
}