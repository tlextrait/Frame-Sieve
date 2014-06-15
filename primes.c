/** File primes.c
 * @author Thomas Lextrait
 */

#include "file_functions.h"
#include "primes.h"

#define MAX_PRIMES 			10000000	// max number of primes
#define MAX_PRIME			10000000L	// max prime number
#define MAX_FILENAME_LENGTH 1024

/* GLOBAL VARIABLES */
int verbose = -1;
int timeShow = -1;
unsigned long int max_prime = -1;
int specFile = -1;
int max_primes = -1;

int main(int argc, char *argv[])
{
    
    /*
     * Unsigned Long Int (20 digits)
     * 18.5 million trillion
     * 18,446,744,073,709,551,615
     */
    
	/* Primes */
    FILE *file;
	char* fileLoc = (char*)malloc(sizeof(char) * MAX_FILENAME_LENGTH);
	unsigned long int *primeArray = (unsigned long int*)malloc(sizeof(unsigned long int) * MAX_PRIMES);
    unsigned long int primeCount = 0;
    unsigned long int i;

	/* Time computations */
    unsigned long int totalTime;
    struct timeval tv1, tv2;

	/* Command line options */
	int c;
	extern int optind, opterr;
	extern char *optarg;
	
	// Parse command line options
	while((c = getopt (argc, argv, "hvtf:m:q:")) != EOF) {
	    switch(c){
			case 'v': // verbose
				verbose = 0;
				break;
			case 't': // display time
				timeShow = 0;
				break;
			case 'm': // specify max prime
				max_prime = atoi(optarg);
				if(max_prime < 3){max_prime = 3;}
				break;
			case 'f': // specify file
				specFile = 0;
				memset(fileLoc, '\0', MAX_FILENAME_LENGTH);
				strncpy(fileLoc, optarg, MAX_FILENAME_LENGTH);
				break;
			case 'q': // specify how many primes to compute
				max_primes = atoi(optarg);
				if(max_primes < 0){max_primes = 0;}
				break;
			default:
		    case '?': // opt error
		    case 'h': // help
		      	help();
				exit(1);
	    }
  	}

	if(max_prime < 3){
		max_prime = MAX_PRIME;
	}
	
	if(max_primes < 0){
		max_primes = MAX_PRIMES;
	}

	if(specFile == 0){
		// Check the file at given path exists
        if(loadPrimesFromFile(fileLoc, primeArray, &primeCount)!=0){
            printf("Given file couldn't be opened, it might not exist!\n");
            exit(1);
        }
	}else{
		// Try to find a file containing previously computed primes
        if(loadPrimesFromFile("primes.txt", primeArray, &primeCount)!=0){
            // Create new file
            createDefaultFile();
            loadPrimesFromFile("primes.txt", primeArray, &primeCount);
        }
	}
    
    printf("Computing prime numbers...\n");
    
    if(timeShow == 0){gettimeofday(&tv1, NULL);}
    
    for(i=primeArray[primeCount-1]+2; i < max_prime && primeCount < max_primes; i+=2){
        if(isPrime(i, primeArray, primeCount)==0){
            primeArray[primeCount] = i;
            primeCount++;
			if(verbose==0){printf("%li\n", i);}
        }
        if(verbose!=0){updateProgress(i);}
    }

	printf("%li prime numbers found\n", primeCount);
    
    if(timeShow == 0){
		gettimeofday(&tv2, NULL);
	    if(tv1.tv_usec > tv2.tv_usec){
	        tv2.tv_sec--;
	        tv2.tv_usec += 1000000;
	    }
		totalTime = (tv2.tv_sec-tv1.tv_sec)*1000 + (tv2.tv_usec-tv1.tv_usec)/1000;
	    printf("%li milliseconds\n", totalTime);
	}
    
    if(specFile == 0){
        savePrimes(fileLoc, primeArray, primeCount);
    }else{
        savePrimes("primes.txt", primeArray, primeCount);
    }

	if(verbose == 0){printf("Computed primes have been saved.\n");}
}

/**
 * Shows the computation's progress
 */
void updateProgress(unsigned long int a){
    if(a==max_prime/10+1){printf("Progress 10%%\n");}
    else if(a==2*max_prime/10+1){printf("Progress 20%%\n");}
    else if(a==3*max_prime/10+1){printf("Progress 30%%\n");}
    else if(a==4*max_prime/10+1){printf("Progress 40%%\n");}
    else if(a==5*max_prime/10+1){printf("Progress 50%%\n");}
    else if(a==6*max_prime/10+1){printf("Progress 60%%\n");}
    else if(a==7*max_prime/10+1){printf("Progress 70%%\n");}
    else if(a==8*max_prime/10+1){printf("Progress 80%%\n");}
    else if(a==9*max_prime/10+1){printf("Progress 90%%\n");}
}

/**
 * Returns -1 if a/b has no remainder, 0 if there is a remainder
 */
int hasRemainder(unsigned long int a, unsigned long int b)
{
    if(a%b==0){return -1;}else{return 0;}
}

/**
 * Returns 0 if it's a prime, -1 if it's not
 */
int isPrime(unsigned long int a, unsigned long int* primeArray, unsigned long int primeCount)
{
    unsigned long int i;
    unsigned long int root = sqrt(a);
    
    /*
     * We re-use previously computed prime numbers
     * in order to determine if current number is a prime
     */
    
    for(i = 0; i < primeCount && primeArray[i]<=root; i++){
        if(hasRemainder(a, primeArray[i])==-1){return -1;}
    }
    
    return 0;
}

/**
 * Display a help message
 */
void help()
{
    /*
	printf("primes - thomas.lextrait@gmail.com\n");
	printf("usage: primes [-h|-v|-t] [-f<file>] [-m<max prime>] [-q<max primes>]\n");
	printf("\t-f\tSpecify a file containing previously computed primes,\n\t\totherwise will use 'primes.txt'.\n");
	printf("\t-m\tSpecify the upper limit for computing primes,\n\t\totherwise will use %li.\n", MAX_PRIME);
	printf("\t-q\tSpecify how many prime numbers to look for,\n\t\totherwise will use %i.\n", MAX_PRIMES);
	printf("\t-v\tBe verbose, display each prime as it is found.\n");
	printf("\t-t\tDisplay total time elapsed.\n");
	printf("\t-h\tDisplay this help message.\n");
	printf("\n\tFlags -m and -q can be used together, the program will\n\tstop as soon as it reaches either condition.\n");
    */
}

