/*
Problem set 1 - hacker edition. Mario.c
Program to output 2 half pyramids of a height given by the user up to 23. EDIT - lost the hacker edition of the file, this is the normal version.
*/

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height, rowCounter, spaceCounter, hashCounter;
    
    do // prompts user for pyramid height, checks for valid input.
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    for (rowCounter = 1; rowCounter <= height; ++rowCounter) // row loop
    {
        for (spaceCounter = 0; spaceCounter < height - rowCounter; ++spaceCounter) // loop for left most spaces.
        {
            printf (" ");
        }
        
        for (hashCounter = rowCounter ; hashCounter >= 0; --hashCounter) // loop for blocks of half pyramid.    
        {
            printf ("#");
        }
     
        printf("\n"); 
    }
    return 0;
}
        
    
    
