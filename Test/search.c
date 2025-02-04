#include<stdio.h>
#include<string.h> 

int main(void)
{
    char *strings[] = {"battleship","canon","top hat","house","iron"};

    char s[15];
    printf("player piece: ");
    scanf("%s",s); 

    for(int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i],s) == 0)
        {
            printf("Found\n");
            return 0;
        }
        else
        {
            printf("Not Found\n"); 
            return 1;
        }

    }
}
