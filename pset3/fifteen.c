/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// blank tile coordinates structure.
struct coords
{
    int x;
    int y;
} blank;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
struct coords search (int a);
void swap (int board[DIM_MAX][DIM_MAX], struct coords a);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int counter = (d * d) - 1;
    for (int i = 0; i < d; ++i) // row loop
    {
        for (int j = 0; j < d; ++j, --counter) // nested column loop
            board[i][j] = counter;
    }
    if (d % 2 == 0) // tests the board size - if the dimensions are even, there's an odd number of tiles.  The last 2 tiles (2 and 1) need to be reversed.
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
    board[d - 1][d - 1] = 0; // blank tile.
    blank.x = d - 1; // global blank tile coordinate struct to keep track of tile location.
    blank.y = d - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for (int i = 0; i < d; ++i) // again uses nested loops for each row and column.
    {
        for (int j = 0; j < d; ++j)
        {
            printf ("%2d\t", board[i][j]);
            if (j == (d - 1)) // if the right most tile in the row starts a new row.
                printf ("\n\n");
        }
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
struct coords search (int a) // searches for the location of the tile entered by the player to move.
{
    struct coords result;
    for (int i = 0; i < d; ++i) // loops through each row and column again and tests whether the value matches a
    {
        for (int j = 0; j < d; ++j)
        {
            if (board[i][j] == a)
            {
                result.x = i;
                result.y = j;
            }
        }
    }
    return result;
}

void swap (int board[DIM_MAX][DIM_MAX], struct coords a) // swaps the 2 tile values in the array.
{
    int temp = board[a.x][a.y];
    board[a.x][a.y] = board[blank.x][blank.y];
    board[blank.x][blank.y] = temp;
    blank.x = a.x;
    blank.y = a.y;
}
    
    
    
bool move(int tile)
{
    if (tile > ((d * d) - 1)) // above the range of tiles on the board.
        return false;
    else
    {
        struct coords result = search(tile); // uses search function to find the location of the tile.
        
        if (result.x == blank.x) // if tile entered has the same x value as blank tile (same ROW)
        {
            if (result.y == (blank.y - 1) || result.y == (blank.y + 1)) //checks whether the tile is in the COLUMN directly to the left or right of the blank tile.
            {
                swap(board, result); // swaps the 2 tiles if it is and returns true.
                return true;
            }
            else
                return false; 
        }
        else if (result.y == blank.y) // if tile entered has the same y value as blank tile (same COLUMN)
        {
            if (result.x == (blank.x - 1) || result.x == (blank.x + 1)) //checks whether the tile is in the ROW directly above or below the blank tile.
            {
                swap(board, result); //swaps the 2 tiles if it is and returns true.
                return true;
            }
            else
                return false; 
        }
        else
            return false; // or if neither the x or y values match then it is an illegal move and returns false.
    }
}
    // TODO
    
    



/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int num = 1; // num variable which will be checked on each loop.
    if (board[d - 1][d - 1] == 0) // checks whether blank tile is in the bottom right of the board.
    {
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < d; ++j)
            {
                if (num == ((d * d) - 1)) // loop has reached the final value on the board and passed through all the values without returning false so the board must be right - returns true.
                    return true;
                else if (board[i][j] != num) // num doesn't match i x j location so returns false.
                    return false;
                else
                    ++num; // number matches so increments num variable for the next loop check.
            }
        }    
    }
    else
        return false; // blank space not in the right position.
    return true;
}
            
        
