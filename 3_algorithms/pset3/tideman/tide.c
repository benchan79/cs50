#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// A 2-d array called locked, represents the candidate 
// graph. locked is a boolean array, so locked[i][j] 
// being true represents the existence of an edge 
// pointing from candidate i to candidate j; 
// false means there is no edge.
// locked[i][j] means i is locked in over j
int locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    // Integers representing candidates' indices in
    // the 'candidates[]' array
    int winner; // 
    int loser;
}
pair;

// Array of candidates
char* candidates[MAX];

// Array of pairs
// Below formula = Total number of possible pairs
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
int vote(int rank, char name[], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
int is_cycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char *argv[]) 
{
//===============================================
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }
//===============================================
    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }
//===============================================
    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = 0;
        }
    }
//===============================================
    // Print "candidates" and "locked" arrays for checking
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     printf("candidate: %s\n", candidates[i]);
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("pair[%i][%i] locked status: %i\n", i,j,locked[i][j]);
    //     }
    // }
//===============================================
    // Initialize pair_count to 0
    pair_count = 0;
    // Get and store no. of participating voters
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);
//===============================================
    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Declare an array called 'ranks' that collects
        // the voters preferences via call to 'vote'
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[30];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
//===============================================
    // for (int i = 0; i < voter_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("Voter[%i], Rank[%i]: Candidate[%i]\n", i, j,ranks[j]);
    //     }
    // }
//===============================================
        record_preferences(ranks);
//===============================================
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
//===============================================
        printf("\n");
    }
    // End of 'for loop' that queries each voter
//===============================================
    add_pairs();
//===============================================
    for (int i = 0; i < pair_count; i++)
    {
        printf("pairs[%i]: winner %i, loser %i\n", i, pairs[i].winner, pairs[i].loser);
    }
    printf("\n");
//===============================================
    sort_pairs();
//===============================================
    for (int i = 0; i < pair_count; i++)
    {
        printf("pairs[%i]: %i :winner %i, loser %i\n", i, preferences[pairs[i].winner][pairs[i].loser], pairs[i].winner, pairs[i].loser);
    }
    printf("\n");
//===============================================
    lock_pairs();
//===============================================
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            printf("[%i] ", locked[i][j]);
        }
        printf("\n");
    }
    printf("\n");
//===============================================
    print_winner();
//===============================================
    printf("\n");
    return 0;
}

//===============================================
//===============================================
//===============================================

// Update ranks given a new vote
int vote(int rank, char name[], int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // Assign candidate's index, 'i' to 
            // 'ranks' array at index 'rank'
            // (which is 'j' from main)
            ranks[rank] = i;
            return 1;
        }
    }
    return 0;
}
//===============================================

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}
//===============================================

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    // printf("%i %i\n", pairs[0].winner, pairs[0].loser);
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("Current i: %i\n", i);
        // printf("%i %i\n", pairs[0].winner, pairs[0].loser);
        for (int j = 0; j < candidate_count; j++)
        {
            // printf("Current i and j: [%i][%i]\n", i, j);
            // printf("%i %i\n", pairs[0].winner, pairs[0].loser);
            if (i != j && preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // printf("preferences[%i][%i]: %i, preferences[%i][%i]:%i\n", i, j, preferences[i][j], j, i, preferences[j][i]);
                // printf("pairs[%i].winner: %i, pairs[%i].loser: %i\n", pair_count, pairs[pair_count].winner, pair_count, pairs[pair_count].loser);
                pair_count++;
            }
        }
    }
    return;
}
//===============================================

// Sort pairs in decreasing order by strength of victory
// Using Selection Sort
void sort_pairs(void)
{
    for (int i = 0; i < pair_count -1; i++)
    {
        int max_pos = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max_pos].winner][pairs[max_pos].loser])
            {
                max_pos = j;
            }
        }

        if (max_pos != i)
        {
            pair temp = pairs[i];
            pairs[i] = pairs[max_pos];
            pairs[max_pos] = temp;
        }
    }
    // printf("%i\n", preferences[pairs[0].winner][pairs[0].loser]);
    return;
}
//===============================================
// Helper boolean function to check for cycles using recursion
int is_cycle(int winner, int loser)
{
    // Check if cycle formed. Return true if cycle formed.
    if (loser == winner)
    {
        return 1;
    }
    // Check if 'loser' has won against any candidate 'i' for every pair that's been locked
    // If there is, pass the candidate 'i' as the new 'loser' back into 'is_cycle'
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == 1)
        {
            if (is_cycle(winner, i) == 1)
            {
                // When loser finally finds itself, cycle is complete and return true
                // back into the lock_pairs function that invokeded it
                return 1;
            }
        }
    }
    return 0;
}

//===============================================
//===============================================
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // locks the pair if no cycle formed
        // if cycle formed, pair is not locked, and loop continues checking sorted pairs
        if (is_cycle(pairs[i].winner, pairs[i].loser) == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = 1;
        }
    }
    return;
}
//===============================================

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int counter = 0;
        
        for (int j = 0; j < pair_count; j++)
        {
            counter += locked[j][i];
        }
        
        if (counter == 0)
        {
            printf("%s", candidates[i]);
            break;
        }
    }
    return;
}
//===============================================