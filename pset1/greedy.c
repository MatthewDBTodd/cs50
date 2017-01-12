/* 
CS50 Problem set 1 - Time for change.
Program to output the minimum number of coins needed to give an inputted amount of change using the greedy algorithm. Using 25, 10, 5 and 1 cent coins.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h> // needed for the round function.

int main (void)
{
    float change;
    int   cents;
    int   coinsGiven = 0;
    do
    {
        printf ("How much change are you owed: ");
        change = GetFloat();
    }
    while (change <= 0); // Repeats until a float greater than 0 is entered.
    
    cents = roundf (change * 100); // converts to cents. Due to floating point inaccuracy the roundf function is used.
  
    while (cents > 0) // keeps on looping round until you have zero change left to give.
    {
        if (cents >= 25) //checks the range of money left deciding what the biggest coin you can give is, then takes that away from the total and increments the coinsGiven counter.
        {
            cents -= 25;
            ++coinsGiven;
        }
        else if (cents >= 10 && cents < 25)
        {
            cents -= 10;
            ++coinsGiven;
        }
        else if (cents >= 5 &&  cents < 10)
        {
            cents -= 5;
            ++coinsGiven;
        }
        else
        {
            cents -= 1;
            ++coinsGiven;
        }
    }
    
    printf ("%i\n", coinsGiven);
    
    return 0;
}
        
        
