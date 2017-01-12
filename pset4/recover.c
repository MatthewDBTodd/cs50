/*
 * Problem Set 4 - recover.
 * Recover 50 JPEGS from a memory card.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK 512

typedef uint8_t tinyInt;

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf (stderr, "Usage: ./recover [file]\n");
        return 1;
    }
    FILE* input = fopen (argv[1], "r");
    if (input == NULL) 
    {
        fprintf (stderr, "Failed to open file.\n");
        return 2;
    }
    FILE* output = NULL;
    
    tinyInt fileCounter = 0;
    char fileName[8];
    sprintf (fileName, "%.3i.jpg", fileCounter);
    bool isFileOpen = false;
    
    tinyInt* buffer = malloc(BLOCK);
    
    int blockSize = BLOCK;
    
    while (blockSize == BLOCK)
    {
        blockSize = fread (buffer, 1, BLOCK, input);
        if (*buffer == 0xff && *(buffer + 1) == 0xd8 && *(buffer + 2) == 0xff && (*(buffer + 3) & 0xf0) == 0xe0) // start of a jpeg file.
        {
            if (isFileOpen == true)
            {
                fclose (output);
                fileCounter++;
                sprintf (fileName, "%.3i.jpg", fileCounter);
                output = fopen (fileName, "w");
            }
            else
            {
                isFileOpen = true;
                output = fopen (fileName, "w");
            }
        }
        if (isFileOpen == false)
            continue;
        else
        {
            fwrite (buffer, 1, (blockSize < BLOCK ? blockSize : BLOCK), output);
        }
    }
    fclose (output);
    fclose (input);
    free (buffer);
    return 0;
}
