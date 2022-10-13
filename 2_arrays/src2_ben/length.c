#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // char name[20];
    // printf("What's your name? ");
    // scanf("%s", name);

    // int n = 0;
    // while (name[n] != '\0')
    // {
    //     n++;
    // }
    // printf("%i\n", n);

    char name[20];
    printf("What's your name? ");
    scanf("%s", name);

    int n = strlen(name);
    printf("%i\n", n);

}