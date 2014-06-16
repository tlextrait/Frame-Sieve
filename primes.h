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
 * Returns the largest prime found so far
 */
unsigned long int getLargestPrime();

/**
 * Display a help message
 */
void help();
