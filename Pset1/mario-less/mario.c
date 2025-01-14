#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    printf("Input Number 1 through 8 \n");
    int height;
    scanf("%i", &height);
    print_grid(height);
}
// ask user for height input no less than 8
// our int Height asks for User Input.
// Height is less that 1 or less than 8, will return with Height of User Input.

int get_size(void)
{
    int height;
    do
    {
       printf("Height: ");
       scanf("%i", &height);
    }
    while (height < 1 || height > 8);
    return height;
}

// print out # for row and column and space
// grid height,space,row,end
//  the code takes takes the input from the user HEIGHT
// Space equals the size of Height, checks to see if space is 8 or less subtracts 1 for dots
// for Row we start and zero then check if height is more than, +1 to get the extra hash.
// new line end.
// code checks size for Height that is User Input.
void print_grid(int size)
{
    for (int height = 0; height < size; height++)
    {
        for (int space = height; space < size - 1; space++)
        {
            printf(" ");
        }

        for (int row = 0; row < height + 1; row++)
        {
            printf("#");
        }
        printf("\n");
    }
}
