#include<stdio.h>
#include <stdbool.h>


bool prime(int number);

int main(void)
{
int min;
int result;
    do
    {
    printf("Minimum: ");
    result = scanf("%d", &min);
    // clear the buffer if the input was not successful
    if (result != 1)
    {
        while ((getchar()) != '\n' && getchar() != EOF); //EOF End Of File
    }
    }
    while (result != 1 || min < 1);

int max;
    do
    {
        printf("Maximum: ");
        max = scanf("%d",&max);
        //clear the buffer if the input was not successful
        if(max != 1)
        {
             while((getchar()) != '\n' && getchar() != EOF);
        }
    }
    while ( max <= min);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{

    if (number <= 1)
    {
        return false;
    }
    else if (number == 2 || number == 3)
    {
        return true;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
