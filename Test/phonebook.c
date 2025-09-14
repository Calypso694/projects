#include<cs50.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
 person people[2];
 people[0].name = "Greg";
 people[0].number = "+1-234-786-1000";

 people[1].name = "Nick";
 people[1].number = "+1-917-951-7000";

 string name = get_string("Name: ");

 for(int i = 0; i < 2; i++)
 {
    if (strcmp(people[i].name, name) == 0)
    {
        printf("Found %s\n",people[i].number);
        return 0;
    }
        printf("Not Found\n");
        return 1;

 }

    /*
     string names[5];
     names[0] = "Homer";
     names[1] = "Lisa";
     names[2] = "Bart";
     names[3] = "Marge";
     names[4] = "Maggie";
    printf("\n %s\n %s\n %s\n %s\n %s\n ", names[0],names[1],names[2],names[3],names[4]);
    */
}





