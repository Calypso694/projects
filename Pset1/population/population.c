#include <stdio.h>

int main(void)
{   // Problem is to calculate the "Population" of Llamas each year. Each year,
    // you lose and gain some more "Poulation". You have a startSize and an endSize.
    // you then have to figure out how many years it takes to go from startSize to endSize.
    // TODO: Prompt for start size
    int startSize;
    do
    {
        printf("Start Size: ");
        //scanf needs address not just the variable
        //char array dont need & INT need &;
        scanf("%i",&startSize);
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        printf("End Size: ");
        scanf("%i",&endSize);
    }
    while (endSize < startSize);



    // TODO: Calculate number of years until we reach threshold
    //n = n + (n/3) - (n/4);
    int years;
    for (years = 0; startSize < endSize; years++)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4);
    }
    // Print the number of years
    printf("Years: %i\n", years);

}
