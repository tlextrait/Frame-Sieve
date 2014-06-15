###########################################################################
# Thomas Lextrait
#
# thomas.lextrait@gmail.com		
# www.tlextrait.com			 
###########################################################################

HOW TO COMPILE AND RUN
---------------------------------------------------------------------------
How to compile the program?
Open Terminal, navigate to the folder containing the program and run type:
make
This will compile the program. In order to run it, type:
./primes

usage: primes [-h|-v|-t] [-f<file>] [-m<max prime>] [-q<max primes>]
	-f	Specify a file containing previously computed primes,
		otherwise will use 'primes.txt'.
	-m	Specify the upper limit for computing primes,
		otherwise will use 10000000.
	-q	Specify how many prime numbers to look for,
		otherwise will use 10000000.
	-v	Be verbose, display each prime as it is found.
	-t	Display total time elapsed.
	-h	Display this help message.

	Flags -m and -q can be used together, the program will
	stop as soon as it reaches either condition.

WHAT DOES THE PROGRAM DO?
---------------------------------------------------------------------------
The program will compute all the prime numbers up to 1 billion and
save them to a file called primes.txt, unless you specify a file of your own
using option -f.

If you interrupted the computation, the program will automatically resume
computing starting at the last prime number found.

RUNNING AS A BACKGROUND TASK
---------------------------------------------------------------------------
You can run the program as a background task in Terminal by appending
the ampersand '&' symbol at the end of the command. Examples:
./primes &
./primes -t -f Desktop/myprimes.txt &

HOW THE PROGRAM FINDS PRIME NUMBERS
---------------------------------------------------------------------------
This program loops over all odd numbers using a for loop. For each odd
number, it uses previously found prime numbers and tries to see if any
prime number that is less or equal to the square root of the odd number
is able to divide it, using the modulus function.
In order for this to work, we need prime numbers to work with. This is
why the program assumes that 2 and 3 are the primary prime numbers, unless
you provide it with a text file containing prime numbers.

STATISTICS
---------------------------------------------------------------------------
Here are stats when running this program on a Macbook Pro running OS X Lion
with a 2.53Ghz Intel dual core CPU, 4GB RAM and an SSD.

Here the average wall times:
Primes up to 1,000		0 milliseconds
Primes up to 10,000		0 milliseconds
Primes up to 100,000		15 milliseconds
Primes up to 1,000,000		240 milliseconds
Primes up to 10,000,000		4.9 seconds
Primes up to 100,000,000	1.5 minute
Primes up to 1,000,000,000	45 minutes

For more stats, see stats.xls

You might wonder if displaying computation progress affects those wall times,
it actually doesn't. Progress is checked every time we find a prime number.
What takes the most time is actually telling whether a number is a prime.

TROUBLESHOOTING
---------------------------------------------------------------------------
- 'make' doesn't work
	You might need to install Xcode if you are using Mac. Xcode is free
	in the Mac App store.
