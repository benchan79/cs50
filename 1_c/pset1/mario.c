#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    // for(int x = 0; x < 4; x++)
    // {
    //     printf("?");
    // }
    // printf("\n");

    // for(int y = 0; y < 3; y++)
    // {
    //     printf("#\n");
    // }

    // const int n = 5;

    //Get size of grid
    // int n;
    // do
    // {
    //     printf("Size: ");
    //     scanf("%d", &n);
    // } 
    // while (n < 1);
         
    // Print grid of bricks
    // for (int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    //Get size of grid
    int n = get_size();

    // Print grid of bricks
    print_grid(n);

}

int get_size(void)
{
    int n;
    do
    {
        printf("Size: ");
        scanf("%d", &n);
    } 
    while (n < 1);
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
