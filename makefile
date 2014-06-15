all: primes

primes: primes.o file_functions.o
	gcc -g primes.o file_functions.o -o primes

primes.o: primes.c primes.h file_functions.h
	gcc -g -c primes.c

file_functions.o: file_functions.c file_functions.h
	gcc -g -c file_functions.c

clean:
	rm -f *.o primes