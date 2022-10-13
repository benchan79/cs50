// #include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool is_cycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // Assign candidate's index, 'i' to
            // 'ranks' array at index 'rank'
            // (which is 'j' from main)
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

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

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
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

// Helper boolean function to check for cycles using recursion
bool is_cycle(int winner, int loser)
{
    // Check if cycle formed. Return true if cycle formed.
    if (loser == winner)
    {
        return true;
    }
    // Check if 'loser' has won against any candidate 'i' for every pair that's been locked
    // If there is, pass the candidate 'i' as the new 'loser' back into 'is_cycle'
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true)
        {
            if (is_cycle(winner, i) == true)
            {
                // When loser finally finds itself, cycle is complete and return true
                // back into the lock_pairs function that invokeded it
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // locks the pair if no cycle formed
        // if cycle formed, pair is not locked, and loop continues checking sorted pairs
        if (is_cycle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

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
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}

// :) vote returns true when given name of candidate
// :) vote returns false when given name of invalid candidate
// :) vote correctly sets rank for first preference
// :) vote correctly sets rank for all preferences
// :) record_preferences correctly sets preferences for first voter
// :) record_preferences correctly sets preferences for all voters
// :) add_pairs generates correct pair count when no ties
// :) add_pairs generates correct pair count when ties exist
// :) add_pairs fills pairs array with winning pairs
// :) add_pairs does not fill pairs array with losing pairs
// :) sort_pairs sorts pairs of candidates by margin of victory
// :) lock_pairs locks all pairs when no cycles
// :) lock_pairs skips final pair if it creates cycle
// :) lock_pairs skips middle pair if it creates a cycle
// :) print_winner prints winner of election when one candidate wins over all others
// :) print_winner prints winner of election when some pairs are tied