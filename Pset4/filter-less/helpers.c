#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            RGBTRIPLE tempvar = image[j][i];

            image[j][i] = image[j][width - 1 - i];

            image[j][width - 1 - i] = tempvar;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];

            int valid_neighbors = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // Initialize variables for calculating average
            for (int row_offset = -1; row_offset <= 1; row_offset++)
            {
                for (int col_offset = -1; col_offset <= 1; col_offset++)
                {
                    if (i + row_offset >= 0 && i + row_offset < height && j + col_offset >= 0 && j + col_offset < width)
                    {
                        // Check if neighbor is valid and if so, add its RGB values to sums
                        valid_neighbors++;
                        sumRed += image[i + row_offset][j + col_offset].rgbtRed;
                        sumGreen += image[i + row_offset][j + col_offset].rgbtGreen;
                        sumBlue += image[i + row_offset][j + col_offset].rgbtBlue;
                    }
                }
            }
            //  Calculate averages and assign them to pixel in original image
            int averageRed = round((float) sumRed / valid_neighbors);
            int averageGreen = round((float) sumGreen / valid_neighbors);
            int averageBlue = round((float) sumBlue / valid_neighbors);

            copy[i][j].rgbtRed = averageRed;
            copy[i][j].rgbtGreen = averageGreen;
            copy[i][j].rgbtBlue = averageBlue;
        }
    }

    //This loop should go through each pixel in the original image and set its RGB values
    // to the corresponding values in the copy. Here's a pseudocode example:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}
