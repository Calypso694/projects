#include<stdio.h>

int main(void)
{
    char c;
    printf("Do you Agree?: ");
    scanf(" %c",&c); 

    if( c =='y'|| c =='Y')
    {
        printf("Agreed.\n");
    }
    else if(c == 'n'|| c == 'N')
    {
        printf("Disagreed.\n");
    }

    return 0; 
}