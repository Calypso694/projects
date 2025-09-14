#include<cs50.h>
#include<stdio.h>

int factorial(int number);

int main(void)
{
     //prompt user for number
    int n = get_int("Type a number: ");
    //print factorial 
    printf("%i\n",factorial(n));

}




int factorial(int number)
{
    //start with base case
    if(number == 1)
    {
        return 1;
    }
    //if not 1
    return number * factorial(number - 1);

}
