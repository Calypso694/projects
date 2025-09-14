#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // if the pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // pizel will change to cyan color blue/green.
                image[i][j].rgbtRed = 0;
                image[i][j].rgbtGreen = 71;
                image[i][j].rgbtBlue = 83;
            }
        }
    }
}
