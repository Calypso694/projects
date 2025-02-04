#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char before[50];
    char after[50]; 
    printf("Before: ");
    scanf("%s",before); 
    printf("After: ");

    for(int i = 0, n = strlen(before); i < n;  i++)
    {
        //if(islower(before[i]))

            printf("%c",toupper(before[i]));
    }
    printf("\n");
}