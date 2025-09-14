#include<cs50.h>
#include<stdio.h>

typedef struct // similar to a Class from C++ or OOP language.
//non linear. Order doesnt matter.
{
int vote;
string name;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
/*
candidate president = get_candidate("Enter Candidate\n");
printf("%s\n",president.name);
printf("%i\n",president.vote);
*/
candidate candidate_array[3];
for(int i = 0; i < 3; i++)
{
    candidate_array[i] = get_candidate("Enter Candidate\n");
}


}

candidate get_candidate(string prompt)
{
    printf("%s\n",prompt);
    candidate can;
    can.name = get_string("enter a name: ");
    can.vote = get_int("enter votes: ");

    return can; //dont forget to return the function def.

}
