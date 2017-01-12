/*
* Problem set 2 - Initializing
* Program to take an input of names, then output the initials in uppercase.
*/

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    int wordCount (string name, int charCount);         // word count function declaration.
    
    string name = GetString();                          // prompts user for name.
    int charCount = strlen(name);                       // need to use the length of the entire string a few times, so rather than use strlen each time, set it to a variable.
    
    int nameCount = wordCount(name, charCount);         //calls the word count function. This is so we know how large the initials array has to be, as we don't know how many names the user will be entering.
    char initials[nameCount];
    
    initials[0] = toupper(name[0]);
    
    int index = 1;
    for (int i = 0; i < charCount; ++i)                 // loops through each character and inserts the uppercase letter after a space is found.
    {
        if (name[i] == ' ')
        {
            initials[index] = toupper(name[i+1]);
            ++index;
        }
    }
    
    for (int i = 0; i < nameCount; ++i)                 //loop to print out the initials.
        printf ("%c", initials[i]);
    printf ("\n");
          
    return 0;
}

int wordCount (string name, int charCount)              //word count function. Simple function which loops through the characters and increments the wordcount variable each time a space is encountered.
{
    int wordCount = 0;

    for (int i = 0; i < charCount; ++i)
    {
        if (name[i] == ' ')
            ++wordCount;
    }
    return wordCount+1;
}
