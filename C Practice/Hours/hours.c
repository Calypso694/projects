#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
//Practice using Arrays
//Using an Array as a parameter to a function
//Adding value in a loop
//integer division and type casting
//To add up numbers in an array, you might first want to initialize a variable to zero.
//After, you’ll want to use a loop that adds each value in the array to that variable.
//Be sure to pay attention to what happens if you divide two ints when calculating the average!


float calc_hours(int hours[], int weeks, char output);

int main(void)
//The main function prompts the user for the number of weeks a user has been taking CS50,
//then creates an array with as many elements.
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
//To complete calc_hours, first total up the hours saved in the array into a new variable.
//Then, depending on the value of output, return either this sum, or the average number of hours.
//Note the syntax involved when passing an array to a function.
float calc_hours(int hours[], int weeks, char output)
{
  int total_hours = 0;

for (int i = 0; i < weeks; i++)
{
     total_hours += hours[i];
}
/*
if (output == 'T')
{
    return total_hours;
}
else if(output == 'A')
{
    return(float)total_hours / weeks;
}
else
{
    return -1;
}
*/

return (output == 'T') ? total_hours : ((output =='A') ? (float)total_hours/ weeks: -1);


}
