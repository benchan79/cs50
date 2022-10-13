#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 9

int preferences[MAX][MAX];
int locked[MAX][MAX];

typedef struct
{
    int winner; // 
    int loser;
}
pair;

char* candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
int pair_count;
int candidate_count;

int vote(int rank, char name[], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
int is_cycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        return 1;
    }

    // Determine which test to run
    int setup = atoi(argv[1]);
    int test = atoi(argv[2]);

    // Setup
    printf("Setup: ");
    switch (setup)
    {
        case 0:
            printf("case 0, ");
            candidate_count = 3;
            candidates[0] = "Alice";
            candidates[1] = "Bob";
            candidates[2] = "Charlie";
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    preferences[i][j] = 0;
            break;

        case 1:
            printf("case 1, ");
            candidate_count = 3;
            preferences[0][0] = 0;
            preferences[0][1] = 5;
            preferences[0][2] = 6;
            preferences[1][0] = 4;
            preferences[1][1] = 0;
            preferences[1][2] = 4;
            preferences[2][0] = 3;
            preferences[2][1] = 5;
            preferences[2][2] = 0;
            break;

        case 2:
            printf("case 2, ");
            candidate_count = 3;
            preferences[0][0] = 0;
            preferences[0][1] = 6;
            preferences[0][2] = 8;
            preferences[1][0] = 6;
            preferences[1][1] = 0;
            preferences[1][2] = 3;
            preferences[2][0] = 4;
            preferences[2][1] = 9;
            preferences[2][2] = 0;
            break;

        case 3:
            printf("case 3, ");
            candidate_count = 3;
            pair_count = 3;
            preferences[0][0] = 0;
            preferences[0][1] = 6;
            preferences[0][2] = 7;
            preferences[1][0] = 3;
            preferences[1][1] = 0;
            preferences[1][2] = 4;
            preferences[2][0] = 2;
            preferences[2][1] = 5;
            preferences[2][2] = 0;
            pairs[0].winner = 0;
            pairs[0].loser = 1;
            pairs[1].winner = 0;
            pairs[1].loser = 2;
            pairs[2].winner = 2;
            pairs[2].loser = 1;
            break;

        case 4:
            printf("case 4, ");
            candidate_count = 4;
            candidates[0] = "Alice";
            candidates[1] = "Bob";
            candidates[2] = "Charlie";
            candidates[3] = "David";
            break;

        case 5:
            printf("case 5, ");    
            candidate_count = 5;
            candidates[0] = "Alice";
            candidates[1] = "Bob";
            candidates[2] = "Charlie";
            candidates[3] = "David";
            candidates[4] = "Erin";
            break;

        case 6:
            printf("case 6, ");
            candidate_count = 6;
            candidates[0] = "Alice";
            candidates[1] = "Bob";
            candidates[2] = "Charlie";
            candidates[3] = "David";
            candidates[4] = "Eric";
            candidates[5] = "Frank";
            break;
    }

    // Test
    int ranks3[3];
    int temp;
    printf("Test: ");
    switch(test)
    {
        case 0:
            ranks3[0] = ranks3[1] = ranks3[2] = 0;
            printf("%s", vote(0, "Bob", ranks3) ? "true" : "false");
            break;

        case 1:
            ranks3[0] = ranks3[1] = ranks3[2] = 0;
            printf("%s", vote(0, "David", ranks3) ? "true" : "false");
            break;

        case 2:
            ranks3[0] = ranks3[1] = ranks3[2] = 0;
            vote(0, "Bob", ranks3);
            vote(1, "Charlie", ranks3);
            vote(2, "Alice", ranks3);
            printf("%i %i %i", ranks3[0], ranks3[1], ranks3[2]);
            break;

        case 3:
            ranks3[0] = 1;
            ranks3[1] = 2;
            ranks3[2] = 0;
            record_preferences(ranks3);
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    printf("%i ", preferences[i][j]);
            break;

        case 4:
            preferences[0][0] = 0;
            preferences[0][1] = 2;
            preferences[0][2] = 1;
            preferences[1][0] = 3;
            preferences[1][1] = 0;
            preferences[1][2] = 4;
            preferences[2][0] = 3;
            preferences[2][1] = 5;
            preferences[2][2] = 0;
            ranks3[0] = 1;
            ranks3[1] = 0;
            ranks3[2] = 2;
            record_preferences(ranks3);
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    printf("%i ", preferences[i][j]);
            break;

        case 5:
            add_pairs();
            printf("%i\n", pair_count);
            break;

        case 6:
            add_pairs();
            for (int i = 0; i < 3; i++)
                if (pairs[i].winner == 0 && pairs[i].loser == 1)
                    printf("true ");
                else if (pairs[i].winner == 0 && pairs[i].loser == 2)
                    printf("true ");
                else if (pairs[i].winner == 2 && pairs[i].loser == 1)
                    printf("true ");
            break;

        case 7:
            add_pairs();
            temp = 0;
            for (int i = 0; i < 3; i++)
            {
                if (pairs[i].winner == 1 && pairs[i].loser == 0)
                    temp++;
                else if (pairs[i].winner == 2 && pairs[i].loser == 0)
                    temp++;
                else if (pairs[i].winner == 1 && pairs[i].loser == 2)
                    temp++;
            }
            printf("%i", temp);
            break;

        case 8:
            sort_pairs();
            for (int i = 0; i < 3; i++)
                printf("%i %i ", pairs[i].winner, pairs[i].loser);
            break;

        case 9:
            pair_count = 4;
            pairs[0].winner = 0; pairs[0].loser = 1;
            pairs[1].winner = 1; pairs[1].loser = 2;
            pairs[2].winner = 2; pairs[2].loser = 3;
            pairs[3].winner = 1; pairs[3].loser = 3;
            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    printf("%s ", locked[i][j] ? "true" : "false");
            break;

        case 10:
            pair_count = 4;
            pairs[0].winner = 0; pairs[0].loser = 1;
            pairs[1].winner = 1; pairs[1].loser = 2;
            pairs[2].winner = 2; pairs[2].loser = 3;
            pairs[3].winner = 3; pairs[3].loser = 0;
            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    printf("%s ", locked[i][j] ? "true" : "false");
            break;

        case 11:
            pair_count = 4;
            pairs[0].winner = 0; pairs[0].loser = 1;
            pairs[1].winner = 1; pairs[1].loser = 2;
            pairs[2].winner = 2; pairs[2].loser = 0;
            pairs[3].winner = 2; pairs[3].loser = 3;
            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
                for (int j = 0; j < candidate_count; j++)
                    printf("%s ", locked[i][j] ? "true" : "false");
            break;

        case 12:
            pair_count = 6;
            locked[0][0] = 0;
            locked[0][1] = locked[0][2] = locked[0][3] = 1;
            locked[1][0] = locked[1][1] = 0;
            locked[1][2] = locked[1][3] = 1;
            locked[2][0] = locked[2][1] = locked[2][2] = 0;
            locked[2][3] = 1;
            locked[3][0] = locked[3][1] = locked[3][2] = locked[3][3] = 0;
            print_winner();
            break;

        case 13:
            pair_count = 4;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    locked[i][j] = 0;
            locked[2][0] = 1;
            locked[0][1] = 1;
            locked[0][3] = 1;
            locked[1][3] = 1;
            print_winner();
            break;

        case 14:  //lock final pair test
            printf("case 15 (lock final pair test)\n\n");
            pair_count = 7;
            pairs[0].winner = 0; pairs[0].loser = 1;
            pairs[1].winner = 1; pairs[1].loser = 4;
            pairs[2].winner = 4; pairs[2].loser = 2;
            pairs[3].winner = 4; pairs[3].loser = 3;
            pairs[4].winner = 3; pairs[4].loser = 5;
            pairs[5].winner = 5; pairs[5].loser = 1;
            pairs[6].winner = 2; pairs[6].loser = 1;

            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
            {
                for (int j = 0; j < candidate_count; j++)
                {
                    // printf("%s ", locked[i][j] ? "true" : "false");
                    printf("%i ", locked[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;

        case 15: //lock middle pair test
            printf("case 15 (lock middle pair test)\n\n");
            pair_count = 5;
            pairs[0].winner = 2; pairs[0].loser = 0;
            pairs[1].winner = 4; pairs[1].loser = 1;
            pairs[2].winner = 1; pairs[2].loser = 3;
            pairs[3].winner = 3; pairs[3].loser = 4;
            pairs[4].winner = 4; pairs[4].loser = 2;

            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
            {
                for (int j = 0; j < candidate_count; j++)
                {
                    // printf("%s ", locked[i][j] ? "true" : "false");
                    printf("%i ", locked[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;

        case 16: //lock all pairs if no cycles
            printf("case 16 (lock all pairs if no cycles)\n\n");
            pair_count = 4;
            pairs[0].winner = 4; pairs[0].loser = 2;
            pairs[1].winner = 0; pairs[1].loser = 3;
            pairs[2].winner = 1; pairs[2].loser = 0;
            pairs[3].winner = 3; pairs[3].loser = 4;

            lock_pairs();
            for (int i = 0; i < candidate_count; i++)
            {
                for (int j = 0; j < candidate_count; j++)
                {
                    // printf("%s ", locked[i][j] ? "true" : "false");
                    printf("%i ", locked[i][j]);
                }    
                printf("\n");
            }
            printf("\n");
            break;
    }
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