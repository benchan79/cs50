#include <stdio.h>

int main(void)
{
    // Get pyramid height from user
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    } 
    while (height < 1 || height > 8);

    // Build pyramid
    for (int i = 0; i < height; i++)
    {
        // Build space left of pyramid
        for(int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Build left side of pyramid
        for(int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Insert 2-space gap in the middle
        printf("  ");
        // Build right side of pyramid
        for(int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}