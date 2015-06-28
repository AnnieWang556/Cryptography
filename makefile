make: gmphelper.cpp mathlib.cpp calc.cpp isprime.c factorize.c
	g++ -Wall -o calc calc.cpp gmphelper.cpp mathlib.cpp -lgmp
	gcc -Wall -o isprime isprime.c -lgmp
	gcc -Wall -o factorize factorize.c -lgmp
