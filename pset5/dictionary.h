/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#define LENGTH 45

typedef struct _node
{
    char* WORD;
    struct _node* next;
} node;

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)


#define HASHTABLE_SIZE 190313

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

int hashFunction(char* word);

unsigned int hash (char* word);

#endif // DICTIONARY_H


