#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    string before = get_string("Before: ");
    printf("After: ");

    for(int i = 0, n = strlen(before); i < n;  i++)
    {
        //if(islower(before[i]))

            printf("%c",toupper(before[i]));


    }
    printf("\n");
}