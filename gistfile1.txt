/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

int wordCount = 0;
node* hashtable[HASHTABLE_SIZE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{    
    char wordCopy[(strlen (word)) + 1];
    strcpy (wordCopy, word);
    
    for(int i = 0, j = strlen (wordCopy); i < j; i++)
    {
        if (isupper (wordCopy[i]))
            wordCopy[i] = tolower (wordCopy[i]);
    }
    wordCopy[strlen (wordCopy)] = '\0';
    
    int hashVal = hash (wordCopy);
    if (hashtable[hashVal] == NULL)
        return false;
    else
    {
        node* temp = hashtable[hashVal];
        while (true)
        {
            if (strcmp (wordCopy, temp -> WORD) == 0)
                return true;
            else
            {
                if (temp -> next != NULL)
                    temp = temp -> next;
                else
                    return false;
            }
        }
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE* dict = fopen (dictionary, "r");
    if (dict == NULL) 
    {
        fprintf (stderr, "Unable to open dictionary file.\n");
        return false;
    }
   
    char word[LENGTH + 1];
   
    while (fscanf (dict, "%s", word) != EOF)
    {
        int hashVal = hash (word);
        int wordLength = strlen (word);
        
        if (hashtable[hashVal] == NULL)
        {
            node* newNode = calloc (1, sizeof (node));
            newNode -> WORD = malloc (wordLength + 1);
            hashtable[hashVal] = newNode;
            strcpy (newNode -> WORD, word);
            newNode -> next = NULL;
        }
        else
        {
            node* newNode = calloc (1, sizeof (node));
            newNode -> WORD = malloc (wordLength + 1);
            strcpy (newNode -> WORD, word);
            newNode -> next = hashtable[hashVal];
            hashtable[hashVal] = newNode;
        }
        ++wordCount;
    }
    fclose (dict);
    return true;
}
            

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordCount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; ++i)
    {
        node* top = hashtable[i];
            
        while (top != NULL)
        {
            node* temp = top;
            top = top -> next;
            free (temp -> WORD);
            free (temp);
        }
    }
    return true;
}

unsigned int hash (char* word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % HASHTABLE_SIZE;
}