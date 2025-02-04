#include<stdio.h>

int main(void)
{
    int meow = 3;
    while(meow > 0)
    {
        printf("meow\n");
        meow--;
    }
    int woof = 1;
    while(woof < 4)
    {
        printf("woof\n");
        woof++;
    }

    for(int i = 0; i < 3; i++) //or whatever variable name or char chosen for i.
    {
        printf("meow\n");
    }

}