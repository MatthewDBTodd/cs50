/*
Problem set 2 - Hail, Caesar!
Encrypts a given message using the Caesar cipher using the command line argument of an integer as the key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    string encryptMsg (int k, string msg); 
    
    if (argc != 2)                                                  // too many arguments passed
    {
        printf ("Incorrect number of arguments passed.\n");
        return 1;
    }
    else
    {
        string msg = GetString();
    
        int k = atoi(argv[1]);                                      //atoi function changes the string argument to an integer.
    
        string newMsg = encryptMsg(k, msg);
    
        printf ("%s\n", newMsg);
    }
           
    return 0;
}

string encryptMsg (int k, string msg)
{
    if (k == 0 || (k % 26 == 0))                                    // if the key is 0 then simply returns the same msg.
    {
        return msg;
    }
    else
    {
        for (int i = 0; i < strlen(msg); ++i)                       // loops through each character.
        {
            if (isalpha(msg[i]))                                    // isalpha checks whether character is a letter, as only letters are changed.
            {
                int diff = isupper(msg[i]) ? 64 : 96;               // changes the amount to take off the ascii value depending on whether it's in uppercase or lowercase. 
            
                int alphaNum = msg[i] - diff;                       // takes off the right amount to make the letter numbers correspond to their place in the alphabet. eg a = 1, b = 2 etc.
                
                int newAlphaNum = ((alphaNum + k) % 26);            // formula to change the value using the integer provided as an argument.
                
                msg[i] = newAlphaNum + diff;                        // changes the array value to character value of the integer.
            }
        }
    }
    return msg;
}
    
