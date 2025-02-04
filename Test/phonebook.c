#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[10];
    char number[16];
}
person;

int main(void)
{
    char input[10]; 
 person people[2];
 strcpy(people[0].name, "Bob");
 strcpy(people[0].number, "+1-234-786-1000");

 strcpy(people[1].name, "Dot");
 strcpy(people[1].number, "+1-456-789-1011"); 
 printf("Enter Name, is case sensitive. Use Capitals. Only the first name: "); 
 scanf("%s",input);
 printf("Name: %s\n",input);

 for(int i = 0; i < 2; i++)
 {
    if (strcmp(people[i].name,input) == 0)
    {
        printf("Found %s\n",people[i].number);
    }
        printf("Not Found\n");
 }
 return 0; 
}





