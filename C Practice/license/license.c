#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //index
    int idx = 0;

    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers strings
    // char plates[8][7];

   char **plates = malloc(8 * sizeof(char *));

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

while (fread(buffer, 1, 6, infile) == 6)
{
    // Allocate memory for plates[idx]
    plates[idx] = malloc(7 * sizeof(char));

    // Check if allocation was successful
    if (plates[idx] == NULL)
    {
        // Handle error here
        return 1;
    }

    // Save plate number in array
    for (int i = 0; i < 6; i++)
    {
        plates[idx][i] = buffer[i];
    }

    // Add null terminator
    plates[idx][6] = '\0';

    // Increment idx
    idx++;
}

    for (int i = 0; i < 8; i++)
    {
        printf("%s", plates[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }
    free(plates);
}
