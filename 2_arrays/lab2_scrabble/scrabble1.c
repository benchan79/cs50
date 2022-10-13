#include <ctype.h>
//#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    // string word1 = get_string("Player 1: ");
    // string word2 = get_string("Player 2: ");
    char word1[30];
    char word2[30];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i\n", score1);
    printf("%i\n", score2);
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            // printf("lower\n");
            // printf("%i\n", word[i] -97);
            // int l_pos = word[i] - 97;
            // printf("%i\n", POINTS[word[i] - 97]);
            // score += POINTS[word[i] - 97];
            score += POINTS[word[i] - 'a'];
        }
        else if (isupper(word[i]))
        {
            // printf("upper\n");
            // printf("%i\n", word[i] - 65);
            // int u_pos = word[i] - 65;
            // printf("%i\n", POINTS[word[i] - 65]);
            // score += POINTS[word[i] - 65];
            score += POINTS[word[i] - 'A'];
        }
        // else
        // {
        //     score += 0;
        // }
        //printf("%c", toupper(word[i]));
    }
    // printf("\n");
    // printf("%i\n", score);
    return score;
}
