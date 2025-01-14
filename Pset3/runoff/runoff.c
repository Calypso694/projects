#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // 0 index ALICE = 0; - 1
    //         BOB = 1 ; - 2
    //         CHARLIE = 2; - 3

    // TODO
    // look for candidate called 'name'
    // if candiate found
    // update preferences so that they are the voters rank, pref, and return true.
    // if no cand found - dont update any pref and return false.

    int number_of_candidates = candidate_count;
    // TODO
    //  Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate's name matches given name
        // If yes, increment candidate's votes and return true
        if (strcmp(candidates[i].name, name) == 0)
        { // i    //j
            preferences[voter][rank] = i;
            return true;
        }
    }
    // no match return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    // TODO
    // Update vote counts for all non-elementinated candidates.
    for (int i = 0; i < voter_count; i++) // This loop is for each voter, where i is the voter's index.
    {
        for (int j = 0; j < candidate_count; j++) // This loop is for each rank, where j is the rank's index.
        {
            // Recall that each voter, votes for their highest preference candidate who has not yet been eliminated.
            //  loop through each candidate and update the votes for the cands who have not been elimited.
            if (!candidates[preferences[i][j]]
                     .eliminated) // This checks if the candidate at index preferences[i][j] is not eliminated. preferences[i][j]
                                  // gives us the candidate's index that is the jth choice for the ith voter.
            {
                candidates[preferences[i][j]]
                    .votes++; // If the candidate is not eliminated, we increment that candidate's vote count.
                break; // This exits the inner loop as soon as we find a candidate who is not eliminated and for whom we can count
                       // the vote.
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // if any cand has more the half the vote
    // print out their name and
    // TODO find the maximum number of votes
    // Print the winner (or winners) of the election
    int max_votes = 0;
    int number_of_candiates = candidate_count;
    int total_votes = 0;
    for (int i = 0; i < number_of_candiates; i++)
    {
        total_votes += candidates[i].votes;

        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    // loop though canddiates again
    // if a candidate's vote is more than half of the total votes
    // print their name return true
    bool winner_found = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > total_votes / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;

    return winner_found;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = INT_MAX;
    int number_of_candiates = candidate_count;
    // TODO
    // return min number of vote of anyone still in election
    for (int i = 0; i < number_of_candiates; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < min_votes)
            {
                min_votes = candidates[i].votes;
            }
        }
    }

    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    //  accepts the min number of vote - min as input
    //  if election is tied between all remaining cands
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
            return false;
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // min will be input - use that func
    // update cand func from False to True if min vote is found
    // when run 2nd time, eliminate next cands with 2 or less vote
    // eliminate anyone who has min vote
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
            candidates[i].eliminated = true;
    }
}
