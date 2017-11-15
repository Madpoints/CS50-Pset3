/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n-1;

    while (max >= min)
    {
       int mid = ((min + max) / 2);

        if (values[mid] < value)
        {
            min = mid + 1;
        }
        else if (values[mid] > value)
        {
            max = mid - 1;
        }
        else
        {
            return true;
        }
    }
        return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // using loops compare the two adjacent values of the array and if necessary swap them
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        int minimumValue = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[minimumValue] > values[j])
            {
                minimumValue = j;
            }
        }

            temp = values[minimumValue];
            values[minimumValue] = values[i];
            values[i] = temp;
    }
}
