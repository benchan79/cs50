#include <stdio.h>

int main(void)
{
    int x;
    int y;
    printf("What's x? ");
    scanf("%d", &x); 
    printf("What's y? ");
    scanf("%d", &y); 
    if (x < y)
    {
        printf("x=%d is less than y=%d\n", x, y);
    }
    else if (x > y)
    {
        printf("x=%d is not less than y=%d\n", x, y);
    }
    else
    {
        printf("x=%d is equal to y=%d\n", x, y);
    }
}