/*
* Problem set 2 - Parlez-vous français?
* Program to encrypt a given message using a given key as a command line argument. Uses Vigenère’s cipher.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    bool isValid (int numArgs, string arguments[]);
    string encrypt (string msg, string key);
    
    if (!isValid(argc, argv))                                   // calls function which tests whether the arguments are valid, if not prints an error message and exits the program with return 1;
    {
        printf ("Invalid paramaters.\n");
        return 1;
    }
    
    string key = argv[1];
    
    string msg = GetString();
    
    printf ("%s\n", encrypt (msg, key));
    
    return 0;
}

bool isValid (int numArgs, string arguments[])                  // function which tests the validity of the command line arguments.
{
    if (numArgs != 2)                                           // if there's the incorrect number of command line arguments. Either too few or too many.
        return false;
    
    for (int i = 0; i < strlen (arguments[1]); ++i)             // Tests that the key entered is purely alphabetical. loops through each character and tests with isalpha.
    {
        if (!isalpha (arguments[1][i]))
            return false;
    }
    return true;
}

string encrypt (string msg, string key)                         // function which encrypts the msg.
{
    int i, k;
    for (i = 0, k = 0; i < strlen (msg); ++i)                   // i is the index variable to loop through each successive character of the msg, and k is the index variable to loop through each character of the key.
    {
        if (isalpha (msg[i]))                                   // only encrypts if the character is alphabetical.
        {
            int keyDiff = (isupper(key[k])) ? 65 : 97;          //both of these assign the amount to take off the characters value to make it between 0-26 depending whether it's upper or lower case.
            int msgDiff = (isupper(msg[i])) ? 65 : 97;
            
            int keyVal = key[k] - keyDiff;                      // the value to encrypt with.
            
            int msgVal = msg[i] - msgDiff;
            
            int newMsgVal = (msgVal + keyVal) % 26;             // encrypts the character using the keyVal.
            
            msg[i] = newMsgVal + msgDiff;                       //turns it back in to its ascii value.
            
            if (k == (strlen(key) - 1))                         // tests k value. Loops it back to the beginning if it has reached the last character of the key.
                k = 0;
            else
                ++k;
            
        }
    }
    return msg;
}
            
            
        
    
    
