#include <stdio.h>

const int N = 3;

// Create a function that takes an array of integers as the argument
// and return a float
float average(int length, int array[]);

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;
    // printf("Average1: %f\n", (score1 + score2 + score3) / 3.0);
    // printf("Average1: %f\n", (score1 + score2 + score3) / (float) 3);
    
    // int scores[3];
    // scores[0] = 72;
    // scores[1] = 73;
    // scores[2] = 33;

    // printf("Average2: %f\n", (scores[0] + scores[1] + scores[2]) / (float) 3);

    // int get_scores[3];
    // printf("Scores: ");
    // scanf("%i", &get_scores[0]);
    // printf("Scores: ");
    // scanf("%i", &get_scores[1]);
    // printf("Scores: ");
    // scanf("%i", &get_scores[2]);

    // printf("Average2: %f\n", (get_scores[0] + get_scores[1] + get_scores[2]) / (float) 3);

    // Declare an array to 
    // reserve 12 bytes of contiguous (back-to-back) memory for "get_scores"
    
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        printf("Scores: ");
        scanf("%i", &scores[i]);
    }

    printf("Average2: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}