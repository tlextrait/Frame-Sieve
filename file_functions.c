/** File file_functions.c
 * @author Thomas Lextrait
 */

#include "file_functions.h"

/**
 * Create default file containing some prime numbers to get started
 */
void createDefaultFile()
{
    FILE *file;
    
    if((file=fopen("primes.txt", "wb"))==NULL) {
        printf("Could not create prime number file!\n");
        exit(1);
    }
    
    fprintf(file, "2\n3"); // Default primes 2 and 3
    fclose(file);
}

/**
 * Loads previously computed prime numbers from a file
 */
int loadPrimesFromFile(char* filename, unsigned long int* primeArray, unsigned long int* primeCount)
{
    FILE *file;
    int i = 0, len = 0;
    char line[50];
    
    if(file = fopen(filename, "r")){
        
        while(fgets(line, sizeof(line), file) != NULL)
        {
            // strip trailing '\n' if it exists
            len = strlen(line)-1;
            if(line[len] == '\n'){line[len] = 0;}
            // copy number
            primeArray[i] = atoi(line);
            i++;
        }
        
        (*primeCount) = i;
        
        fclose(file);
        return 0;
    }else{
        return -1;
    }
}

/**
 * Saves a list of prime numbers to file
 */
int savePrimes(char* filename, unsigned long int* primeArray, unsigned long int primeCount)
{
    FILE *file;
    unsigned long int i;
    
    if((file=fopen(filename, "w"))==NULL) {
        printf("Could not create prime number file!\n");
        exit(1);
    }
    
    for(i=0; i<primeCount; i++){
        fprintf(file, "%li\n", primeArray[i]);
    }
    
    fclose(file);
}

/**
 * Checks if a number contains only 1s and 9s
 */
int contains19(unsigned long int a){
    char number[20];
    int i;
    intToString(a, number);
    for(i=0; i<strlen(number); i++){
        if(number[i]!='1' && number[i]!='9'){return -1;}
    }
    return 0;
}

/* itoa:  convert n to characters in s */
void intToString(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

