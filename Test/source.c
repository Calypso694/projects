#include <stdio.h>
#include <string.h> 

typedef struct
{
    char name[20]; 
    int votes;
} candidate;

int main(void)
{
    const int num_candidates = 3;
    candidate candidates[num_candidates];

    strcpy(candidates[0].name, "Carter");
    candidates[0].votes = 10;

    strcpy(candidates[1].name, "Yuliia");
    candidates[1].votes = 12;

    strcpy(candidates[2].name, "Inno");
    candidates[2].votes = 7;

    // Find highest number of votes
    int highest_votes = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes > highest_votes)
        {
            highest_votes = candidates[i].votes;
        }
    }

    // Print name of candidate with highest number of votes
    for (int i = 0; i < num_candidates; i++)
    {
        if(candidates[i].votes == highest_votes)
        {
            printf("%i\n",candidates[i].votes);
            printf("%s\n",candidates[i].name);
        }
    }
}
