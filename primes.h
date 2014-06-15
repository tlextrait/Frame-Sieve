/**
* @file primes.h
* @author Thomas Lextrait
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

/**
 * Shows the computation's progress
 */
void updateProgress(unsigned long int a);

/**
 * Returns -1 if a/b has no remainder, 0 if there is a remainder
 */
int hasRemainder(unsigned long int a, unsigned long int b);

/**
 * Returns 0 if it's a prime, -1 if it's not
 */
int isPrime(unsigned long int a, unsigned long int* primeArray, unsigned long int primeCount);

/**
 * Display a help message
 */
void help();
