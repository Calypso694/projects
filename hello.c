#include<stdio.h>

int main(void)
{
    char name[50];
    printf("Hello World\n");
    printf("What's your name? \n");
    printf("input name: %s", name);
    scanf("%s",name);
    printf("hello, %s nice to meet you.\n", name);


}
