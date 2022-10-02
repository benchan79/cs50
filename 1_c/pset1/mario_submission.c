#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    } 
    while (height < 1 || height > 8);
    
    // printf("Stored: %i\n", height);

    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for(int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

    
