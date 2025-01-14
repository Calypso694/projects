// Practice working with structs
// Practice applying sorting algorithms

//The main function initializes the temps array,
//calls the sort_cities function and prints out the array in sorted order.
//You will use an O(n2) sorting algorithm of your choice
//(possibly bubble sort, selection sort,
//or insertion sort) to sort the array by temperature, in descending order.

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    int n = NUM_CITIES;
    avg_temp temp;

    int i, j;
    for (i = 0; i < n; i++)

        // Last i elements are already in place

        for (j = 0; j < n - i - 1; j++)
        if (temps[j].temp < temps[j + 1].temp)
        {
            temp = temps[j];
            temps[j] = temps[j+1];
            temps[j + 1] = temp;
        }
}
