#include "gmphelper.h"
#include <time.h>		// for time - random number generation.

void mod(mpzNum& b, mpzNum& a, mpzNum& n)
{
	mpz_fdiv_r(b(), a(), n());
}

void divQR(mpzNum& q, mpzNum& r, mpzNum& a, mpzNum& n)
{
	mpz_fdiv_qr(q(), r(), a(), n());
}

void divQrCalc()
{
	mpzNum a, n, q,r;
	int aa, nn;

	printf("input a, n: ");
	scanf("%d %d", &aa, &nn);
	a = aa;
	n = nn;

	divQR(q, r, a, n);

	gmp_printf("a mod n = : %Zd\n", r());
	gmp_printf("a / n = : %Zd\n", q());
}

void gcd( mpzNum& d, mpzNum& s, mpzNum& t, mpzNum& a, mpzNum& b)
{
	// initialize variables
	mpzNum r0, r1;
	mpzNum s0(0), s1(1), t0(1), t1(0);
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

	mpzNum q, temp;
	while(r0 != 0)	// while r0 != 0
	{
		temp = r0;
		divQR(q, r0, r1, r0);	// q = r1/r0, r0 = r1%r0
		r1 = temp;

		mpz_submul(s1(), q(), s0());		// s1 = s1 - q*s0
		mpz_swap(s0(), s1());				// swap s0, s1 -> s0 = s1 - q*s0, s1 = s0

		mpz_submul(t1(), q(), t0());
		mpz_swap(t0(), t1());
	}

	if(needSwap)
	{
		mpz_swap(s1(), t1());
	}

	d = r1;
	s = s1;
	t = t1;
}

void gcdCalc()
{
	mpzNum a, b, d, s, t;
	int aa, bb;
	printf("input a, b: ");
	scanf("%d %d", &aa, &bb);
	a = aa;
	b = bb;

	gcd(d, s, t, a, b);

	gmp_printf("gcd d = : %Zd\n", d());

	mpzNum temp;
	temp = a*s;
	gmp_printf("(multiplicative inverse of a modulo :)\ns = %Zd, a*s = %Zd\n", s(), temp());
	temp = b*t;
	gmp_printf("t = %Zd, b*t = %Zd\n", t(), temp());
}

void generatePrime(mpzNum& p, int lengthOfP)
{
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL); 
	gmp_randseed_ui(state, seed);

	mpzNum pTmp;
	mpzNum pLowerBound;

	mpz_ui_pow_ui(pLowerBound(), 2, lengthOfP - 1);

	do
	{
		mpz_urandomb(pTmp(), state, lengthOfP);
	}while(pTmp < pLowerBound);

	mpz_nextprime(p(), pTmp());

	gmp_randclear(state);
}

void exponentialMod(mpzNum& ret, mpzNum& base, mpzNum& exp, mpzNum& modulo)
{
	mpz_powm(ret(), base(), exp(), modulo());
}

void exponentialModCalc()
{
	mpzNum base, expo, modulo, ret;
	int b, e, n;
	printf("input base, exponential, modulo: ");
	scanf("%d %d %d", &b, &e, &n);
	base = b;
	expo = e;
	modulo = n;

	exponentialMod(ret, base, expo, modulo);

	gmp_printf("b^e mod m = %Zd\n", ret());
}

int legendre (mpzNum& a, mpzNum& p)
{
	return mpz_legendre (a(), p());
}

void legendre()
{
	mpzNum a, p;
	int aa, pp;
	printf("input a, p: ");
	scanf("%d %d", &aa, &pp);
	a = aa;
	p = pp;
	int ret = legendre(a,p);
	printf("(a/p) = %d\n", ret);
}

int jacobi (mpzNum& a, mpzNum& p)
{
	return mpz_jacobi (a(), p());
}

void jacobi()
{
	mpzNum a, p;
	int aa, pp;
	printf("input a, n: ");
	scanf("%d %d", &aa, &pp);
	a = aa;
	p = pp;
	int ret = jacobi(a,p);
	printf("(a/n) = %d\n", ret);
}
