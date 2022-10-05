#include <stdio.h>  

int const N = 3;
float average(int length, int array[]);
int *get_scores(int *scores_array);

int main()  
{  
    int *scores;  
    int scores_array[N];  
    scores = get_scores(scores_array);  
    printf("\nElements of array are :");  
    for(int i = 0; i < N; i++)  
        {  
            printf("%d", scores[i]);  
        }
    printf("\n");
    printf("Average: %f\n", average(N, scores));
    return 0;  
}

int *get_scores(int *scores_array)  
{  
    printf("Enter score : ");  
    for(int i = 0; i < N; i++)  
    {  
        scanf("%d", &scores_array[i]);  
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