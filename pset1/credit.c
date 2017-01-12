/* 
CS50 problem set 1 - hacker edition - Bad credit.
Program to test whether a credit card (cc) number entered is valid, and then output what type of card it is.
Uses the checksum: 

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.

Add the sum to the sum of the digits that weren’t multiplied by 2.

If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    long long int ccNum;
    int counter; 
    int ccCheckSum = 0;
    int ccDigits[17]; // The array each digit of the CC will be stored in. Uses 17 places, and will ignore [0] so each CC digit will have the same index as their position for simplicities sake.
    
    do // Asks the user to repeat if a negative number is entered.
    {
        printf ("Please enter your credit card number: ");
        ccNum = GetLongLong();
    }
    while (ccNum <= 0);
    
    counter = 1;
    while (ccNum > 0) // loop to remove each last digit one at a time by using x % 10.
    {
        ccDigits[counter] = ccNum % 10;
        ccNum /= 10;
        ++counter;
    }
    
    // Next multiply every other digit by 2, starting with the number's second-to-last digit. Use the counter variable in a for loop for this.
    
    for (int secondDigit = 1; secondDigit < counter; ++secondDigit) // loops through every 2nd digit of the cc digits array.
    {
        if (secondDigit % 2 == 0) // As the digits are in reverse order, we can test whether it's every second digit by the mod of 2.
        {
            int digitDoubled = ccDigits[secondDigit] * 2;
        
            while (digitDoubled > 0)
            {
                ccCheckSum += digitDoubled % 10;
                digitDoubled /= 10;
            }
        }
        else // One of the other numbers, that we simply add on to the total.
        {
            ccCheckSum += ccDigits[secondDigit];
        }
    }
    
    if (ccCheckSum % 10 == 0) // Is the checksum a pass?
    {
        if (ccDigits[counter - 1] == 3 && (ccDigits[counter - 2] == 4 || ccDigits[counter - 2] == 7)) // First 2 digits are 34 or 37 = AMEX
        {
            printf ("AMEX\n");
        }
        else if (ccDigits[counter - 1] == 5 && ccDigits[counter - 2] >= 1 && ccDigits[counter -2] <= 5) // First 2 digits are between 51 and 55 = MASTERCARD
        {
            printf ("MASTERCARD\n");
        }
        else if (ccDigits[counter - 1] == 4) // First digit is 4 = VISA
        {
            printf ("VISA\n");
        }
        else 
        {
            printf ("INVALID\n"); // First digits don't match up to any of the 3 profiles = INVALID
        }
    }
    else
    {
        printf ("INVALID\n"); // Fails the checksum.
    }
    return 0;
}
    
   
    
    
        
    
