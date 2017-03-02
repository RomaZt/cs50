/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
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
     int max = n - 1;
    // TODO: implement a searching algorithm
    while(min <= max)
    {
       int middle = (min + max) / 2;
       if (value == values[middle])
       {
           return true;
       }
       else if (value > values[middle])
       {
           min = middle + 1;
       }
       else if (value < values[middle])
       {
           max = middle - 1 ;
       }
   }
   return false;
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
   for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(values[j] < values[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int swap = values[min];
            values[min] = values[i];
            values[i] = swap;
        }
    }
}
