#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// first three bytes of JPEGs 0xff 0xd8 0xff
// JPEGs stored back to back in memory.
// loop through memory to find JPEG header.
// The files you generate should each be named ###.jpg,
// where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
// data: pointer to where to store date you are reading
// size: size of each element to read
// number: number of elements to read
// inptr: FILE * to read from
// fread(*data, size, number, inptr);
// buffer[0] == 0xff
// buffer[1] == 0xdb;
// buffer[2] == 0xff; etc.
// bool buffer  == x ||buffer 3 == y || buffer 3 == x etc.

// write new JPEG - sprintf(filename,"%03i.JPG",2);
// FILE *img = fopen(filesname, "w");

// Your program, if it uses malloc, must not leak any memory.

int main(int argc, char *argv[])
{
    // If your program is not executed with exactly one command-line argument,
    // it should remind the user of correct usage, return 1
    if (argc != 2)
    {
        printf("Usage needs 1 cmd arg: exmp ./recover card.raw");
        return 1;
    }

    // Remember filename
    char *infile = argv[1];

    // open memory card
    // If the forensic image cannot be opened for reading,
    // your program should inform the user as much, and main should return 1.
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // buffer
    uint8_t buffer[512];
    bool isFileOpen = false;
    bool isFileClosed = true;
    char filename_card[8];
    int file_number = 0;
    FILE *img = NULL;

    // Read 512 bytes into Buffer
    // repeat until end of card:
    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
                isFileOpen = false;
            }

            sprintf(filename_card, "%03i.jpg", file_number++);
            img = fopen(filename_card, "w");
            isFileOpen = true;
        }
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // close output file and input file
    fclose(img);
    fclose(inptr);
}
