#include<stdio.h>
#include<string.h>

int main(void)
{
    int x;
    printf("Enter number:");
    scanf("%i",&x);
    printf("get number: %i\n", x);
    
    //way 1
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n",c1,c2,c3);
    printf("%c %c %c\n",c1,c2,c3);

    //way 2
    char s[5] = "Hi!";   
    scanf("%s",s); 
    printf("%s\n", s);

    //way 3
    printf("%c%c%c\n",s[0],s[1],s[2]);//%i for int, s[3] =NUL \0

    char bye[4] = "bye";
    printf("%s\n", bye);
    printf("%c%c%c\n",bye[0],bye[1],bye[2]);

    char *words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n",words[0]);
    printf("%s\n",words[1]);
    printf("%c%c%c\n",words[0][0],words[0][1],words[0][2]);
    printf("%c%c%c%c\n",words[1][0],words[1][1],words[1][2],words[1][3]);

    char *list[3];
    list[0] = "Grocery list";
    list[1] = "Carrot";
    list[2] = "Cake";

    printf(" %s\n %s\n %s\n", list[0], list[1], list[2]);

}