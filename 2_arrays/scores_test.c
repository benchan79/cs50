#include <stdio.h>

const int N = 3;

int * get_scores(int n);
float average(int length, int array[]);

int main(void)
{
    // printf("Average2: %f\n", average(N, get_scores(N)));
}

int * get_scores(int n)
{
    int scores_array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Scores: ");
        scanf("%i", &scores_array[i]);
    }
    return scores_array;
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