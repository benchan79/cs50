#include <stdio.h>

int main(void)
{
    char c;
    printf("Do you agree? ");
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        printf("You entered %c. Agreed.\n", c);
    }
    else if (c == 'n' || c == 'N')
    {
        printf("You entered %c. Not agreed.\n", c);
    }
}