#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("Method 1\n");
    int i = 3;
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
    
    printf("Method 2\n");
    int j = 1;
    while (j <= 3)
    {
        printf("meow\n");
        j++;
    }
    
    printf("Method 3\n");
    int k = 0;
    while (k < 3)
    {
        printf("meow\n");
        k++;
    }

    printf("Method 3\n");
    for(int x = 0; x < 3; x++)
    {
        printf("meow\n");
    }

    while (true)
    {
        int n;
        printf("Number: ");
        scanf("%i", &n);
        if (n > 1)
        {
            printf("Method 4\n");
            for(int y = 0; y < n; y++)
            {
                printf("meow\n");
            }
            break;
        }
    }
}