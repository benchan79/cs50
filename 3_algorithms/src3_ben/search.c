#include <stdio.h>
#include <string.h>

int main(void)
{
    // int numbers [7];
    // numbers[0] = 20;
    // numbers[1] = 500;
    // int numbers [] = {20, 500, 10, 5, 100, 1, 50};
    // int n;
    // printf("Number: ");
    // scanf("%i", &n);
    // // linear search
    // for (int i = 0; i < 7; i++)
    // {
    //     if (numbers[i] == n)
    //     {
    //         printf("Found\n");
    //         return 0;
    //     }
    // }
    // printf("Not found\n");
    // return 1;

    char* strings [] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    char s[30];
    printf("String: ");
    scanf("%s", s);
    // linear search
    for (int i = 0; i < 6; i++)
    {
        // if (strings[i] == s)  <---- this cannot work in C. Need to use strcmp() like below
        // returns 0 if every letter in both strings are the same
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    // Run command "echo $?" to see what main returned
    return 1;
}