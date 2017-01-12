/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

int findMid (int min, int max)                                          // function to find the mid point in range of numbers for use in the binary search function.
{
    return (min + ((max - min) / 2));
}

bool binarySearch (int value, int values[], int lower, int upper)       // binary search function. Uses recursion.
{
    int findMid (int min, int max); 
    int mid = findMid(lower, upper);                                    // first finds the mid point of the array elements.
    
    if (values[mid] == value)                                           // value has been found.
        return true;
    else if (upper < lower)                                             // no value has been found in the array.
        return false;
    else if (values[mid] > value)                                       // recursively calls the same function with updated smaller range.
        return binarySearch (value, values, lower, (mid - 1));
    else //(values[mid] < value)
        return binarySearch (value, values, (mid + 1), upper);
}
        
    
    
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    bool binarySearch (int value, int values[], int lower, int upper); 
    bool result = binarySearch (value, values, 0, (n - 1));
    return result;
}

/**
 * Sorts array of n values. Uses bubblesort O(n^2)
 */
void sort(int values[], int n)
{
    bool swaps; 
    int maxUnsorted = n - 1;
    do                                      // uses a do while loop so it checks the array at least once.
    {
        swaps = false;                      // the variable which is checked on every loop. If false then no numbers have been swapped and the array is sorted.
        int i;
        for (i = 0; i < maxUnsorted; ++i)  
        {
            if (values[i] > values[i+1])    // swaps the values if the left number is bigger then the right value.
            {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swaps = true; 
            }
        }
        --maxUnsorted;                      // reduces the range of numbers to check by one each time as the largest numbers will be sorted.
        
        
        
    }
    while (swaps == true);
    return;
}
