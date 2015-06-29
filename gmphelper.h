#include <stdio.h>
#include <gmp.h>		// the GNU Multi Precision Arithmetic Library
#include "mathlib.h"

// mpz_t struct helper:
class mpzNum
{
// member functions
public:
	mpzNum(){ mpz_init(num); }
	mpzNum(signed long int n){ mpz_init_set_si(num, n); }
	mpzNum(const mpzNum& n){ mpz_init_set(num, n.num); }
	~mpzNum(){ mpz_clear(num); }

	mpz_t& operator()(){ return num; }
	bool operator<(mpzNum& other){ return (mpz_cmp(num, other()) < 0); }
	bool operator<(unsigned long int other){ return (mpz_cmp_ui(num, other) < 0); }

	bool operator>(mpzNum& other){ return (mpz_cmp(num, other()) > 0); }
	bool operator>(unsigned long int other){ return (mpz_cmp_ui(num, other) > 0); }

	bool operator==(mpzNum& other){ return (mpz_cmp(num, other()) == 0); }
	bool operator==(unsigned long int other){ return (mpz_cmp_ui(num, other) == 0); }

	bool operator!=(mpzNum& other){ return (mpz_cmp(num, other()) != 0); }
	bool operator!=(unsigned long int other){ return (mpz_cmp_ui(num, other) != 0); }

	mpzNum operator+(mpzNum& other){ mpzNum ret; mpz_add(ret(), num, other()); return ret; }
	void operator+=(mpzNum& other){ mpz_add(num, num, other()); }
	mpzNum operator+(unsigned long int other){ mpzNum ret; mpz_add_ui(ret(), num, other); return ret; }
	void operator+=(unsigned long int other){ mpz_add_ui(num, num, other); }

	mpzNum operator-(mpzNum& other){ mpzNum ret; mpz_sub(ret(), num, other()); return ret; }
	void operator-=(mpzNum& other){ mpz_sub(num, num, other()); }
	mpzNum operator-(unsigned long int other){ mpzNum ret; mpz_sub_ui(ret(), num, other); return ret; }
	void operator-=(unsigned long int other){ mpz_sub_ui(num, num, other); }

	mpzNum operator*(mpzNum& other){ mpzNum ret; mpz_mul(ret(), num, other()); return ret; }
	void operator*=(mpzNum& other){ mpz_mul(num, num, other()); }
	mpzNum operator*(unsigned long int other){ mpzNum ret; mpz_mul_ui(ret(), num, other); return ret; }
	void operator*=(unsigned long int other){ mpz_mul_ui(num, num, other); }

	void operator=(const mpzNum& rhs){ mpz_set(num, rhs.num); }
	void operator=(signed long int other){ mpz_set_si(num, other); }

// member data
public:
	mpz_t num;
};

// common functions: (each func has two forms: input from program/user input.)

// modulo operation.
// calculates a = b mod n
// b has same sign as n. (positive n -> positive modulo.)
void mod(mpzNum& b, mpzNum& a, mpzNum& n);

// calculate: q = a/n, r = a%n (a mod n)
// b has same sign as n. (positive n -> positive modulo.)
void divQR(mpzNum& q, mpzNum& r, mpzNum& a, mpzNum& n);

void divQrCalc();

// Extended Euclidean Algorithm.
// compute the greatest common devisor of two unsigned integers: a, b
// d = gcd(a,b)
// as well as s, t such that as + bt = d.
void gcd( mpzNum& d, mpzNum& s, mpzNum& t, mpzNum& a, mpzNum& b);

void gcdCalc();

// ret = base^exp mod modulo
void exponentialMod(mpzNum& ret, mpzNum& base, mpzNum& exp, mpzNum& modulo);

void exponentialModCalc();

// generate a PRIME number of length >= lengthOfP.
void generatePrime(mpzNum& p, int lengthOfP);

void factorize();

// p is required to be a prime number.
// but I won't test it here.
int legendre(mpzNum& a, mpzNum& p);

void legendre();

// p is required to be an odd number.
// but I won't test it here.
int jacobi(mpzNum& a, mpzNum& p);

void jacobi();
