#include <stdio.h>
#include <string.h>

// Let’s take a look at runoff.c. We’re defining two constants: 
// MAX_CANDIDATES for the maximum number of candidates in the election, 
// and MAX_VOTERS for the maximum number of voters in the election.
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Next up is a two-dimensional array preferences. The array preferences[i] will represent 
// all of the preferences for voter number i, 
// and the integer preferences[i][j] here will store the index of the candidate 
// who is the jth preference for voter i.
// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Next up is a struct called candidate. Every candidate has a string field for their name, 
// and int representing the number of votes they currently have, and a bool value called eliminated 
// that indicates whether the candidate has been eliminated from the election. 
// The array candidates will keep track of all of the candidates in the election.
// Candidates have name, vote count, eliminated status
typedef struct
{
    char* name;
    int votes;
    int eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// The program also has two global variables: 
// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
int vote(int voter, int rank, char name[]);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[]) 
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
        candidates[i].eliminated = 0;
    }

    printf("Number of voters: ");
    scanf("%i", &voter_count);
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
            char name[30];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);
            
            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        // printf("%i %i %i\n", preferences[0][0],preferences[0][1],preferences[0][2]);
        // printf("%i %i %i\n", preferences[1][0],preferences[1][1],preferences[1][2]);
        // printf("%i %i %i\n", preferences[2][0],preferences[2][1],preferences[2][2]);
        printf("\n");
    }

    while (1)
    {
        // candidates[1].eliminated = 1;

        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        int won = print_winner();
        if (won)
        {
            break;
            // printf("Winner found\n");
        }
        // else
        // {
        //     printf("Still no winner\n");
        // }

        // Eliminate last-place candidates
        int min = find_min();
        // printf("find_min: %i\n", min);

        int tie = is_tie(min);
        // printf("is_tie: %i\n", tie);

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
        // for (int i = 0; i < candidate_count; i++)
        // {
        //     printf("Candidate %i eliminated status: %i\n", i, candidates[i].eliminated);
        // }

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }    
    }
    return 0;
}

// Record preference if vote is valid
int vote(int voter, int rank, char name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i; // assign candidate's index to voter's current [rank]
            return 1;
        }
    }
    return 0;
}

// look at all of the voters’ preferences and 
// compute the current vote totals, by looking at each voter’s 
// top choice candidate who hasn’t yet been eliminated. 
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == 0)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     printf("Candidate %i has %i top votes\n", i, candidates[i].votes);
    // }
    return;
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {       
        if (candidates[i].votes > voter_count / 2.0)
        {
            printf("%s\n", candidates[i].name);
            printf("No. of votes: %i\n", candidates[i].votes);
            return 1;
        }
    }
    return 0;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int lowest = MAX_VOTERS;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < lowest && candidates[i].eliminated == 0)
        {
            lowest = candidates[i].votes;
        }
    }
    return lowest;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && candidates[i].eliminated == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == 0)
        {
            candidates[i].eliminated = 1;
            // printf("Candidate %i eliminated status: %i\n", i, candidates[i].eliminated);
        }
    }
    return;
}

// :) vote returns true when given name of candidate
// :) vote returns false when given name of invalid candidate
// :) vote correctly sets first preference for first voter
// :) vote correctly sets third preference for second voter
// :) vote correctly sets all preferences for voter
// :) tabulate counts votes when all candidates remain in election
// :) tabulate counts votes when one candidate is eliminated
// :) tabulate counts votes when multiple candidates are eliminated
// :) tabulate handles multiple rounds of preferences
// :) print_winner prints name when someone has a majority
// :) print_winner returns true when someone has a majority
// :) print_winner returns false when nobody has a majority
// :) print_winner returns false when leader has exactly 50% of vote
// :) find_min returns minimum number of votes for candidate
// :) find_min returns minimum when all candidates are tied
// :) find_min ignores eliminated candidates
// :) is_tie returns true when election is tied
// :) is_tie returns false when election is not tied
// :) is_tie returns false when only some of the candidates are tied
// :) is_tie detects tie after some candidates have been eliminated
// :) eliminate eliminates candidate in last place
// :) eliminate eliminates multiple candidates in tie for last
// :) eliminate eliminates candidates after some already eliminated