#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char* name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

int vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[]) 
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    // printf("Number of candidates: %i\n", candidate_count);

    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);
    // int voter_count = get_int("Number of voters: ");
 
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[30];
        printf("Vote: ");
        scanf("%s", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    
    printf("Votes %i %i %i\n", candidates[0].votes, candidates[1].votes, candidates[2].votes);
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(char name[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winner_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner_votes)
        {
            winner_votes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

// :) vote returns true when given name of first candidate
// :) vote returns true when given name of middle candidate
// :) vote returns true when given name of last candidate
// :) vote returns false when given name of invalid candidate
// :) vote produces correct counts when all votes are zero
// :) vote produces correct counts after some have already voted
// :) vote leaves vote counts unchanged when voting for invalid candidate
// :) print_winner identifies Alice as winner of election
// :) print_winner identifies Bob as winner of election
// :) print_winner identifies Charlie as winner of election
// :) print_winner prints multiple winners in case of tie
// :) print_winner prints all names when all candidates are tied