/**
* @file file_functions.h
* @author Thomas Lextrait
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Create default file containing some prime numbers to get started
 */
void createDefaultFile();

/**
 * Loads previously computed prime numbers from a file
 */
int loadPrimesFromFile(char* filename, unsigned long int* primeArray, unsigned long int* primeCount);

/**
 * Saves a list of prime numbers to file
 */
int savePrimes(char* filename, unsigned long int* primeArray, unsigned long int primeCount);

/**
 * Checks if a number contains only 1s and 9s
 */
int contains19(unsigned long int a);

/* itoa:  convert n to characters in s */
void intToString(int n, char s[]);

/* reverse:  reverse string s in place */
void reverse(char s[]);
