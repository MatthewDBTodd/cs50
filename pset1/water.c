#include <stdio.h>
#include <cs50.h>

int bottlesUsed(int minutes) // Function to work out how many bottles of water is used.
    {
        return minutes * 192 / 16;
    }
    
int getShowerLength(void) // Get the users shower length in minutes. Checking it's a positive value.
{
    int showerLength;
    do
    {
        printf("Please enter the length of your shower in minutes: ");
        showerLength = GetInt();
    }
    while (showerLength < 1);
    return showerLength;
}

int main(void)
{
    int bottles = bottlesUsed(getShowerLength()); // passes the return value of getShowerLength function to bottlesUsed function.
    printf("Bottles Used: %d\n", bottles);
}
