#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
    char c = getwchar("Do you Agree?: ");

    if( c =='y'|| c =='Y')
    {
        printf("Agreed.\n");
    }
    else if(c == 'n'|| c == 'N')
    {
        printf("Disagreed.\n");
    }

}