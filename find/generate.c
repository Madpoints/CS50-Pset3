/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
     // Returns an error message and exits the program if not given between 2 and 3 command-line arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Declare a variable "n" as an integer, and set it to the integer value of the string at argv[1] (the number of lines of random numbers)
    int n = atoi(argv[1]);

    // If given a third argument run the intialization fuction srand48 which will use it as a seed value to generate random numbers.
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    // Else run srand48 with no seed to generate a set of random numbers
    else
    {
        srand48((long) time(NULL));
    }

    // For as long as the integer value of "n" print out the random numbers generated
    // The function drand48 was intialized by the function srand48 and is type cast to an integer
    // Because drand48 returns a floating point value between 0.0 & 1.0 it is multiplied by "LIMIT" which is a predefined constant
    // "LIMIT" also represents the maximum value that can be generated
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
