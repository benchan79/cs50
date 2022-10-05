#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[20];
    printf("Before: ");
    scanf("%s", s);
    printf("After:  ");

    // for(int i = 0; i < strlen(s); i++)
    // {
    //     if (s[i] >= 'a' && s[i] <= 'z')
    //     {
    //         printf("%c", s[i] - 32);
    //     }
    //     else
    //     {
    //         printf("%c", s[i]);
    //     }
    // }
    // for(int i = 0; i < strlen(s); i++)
    // {
    //     if (islower(s[i]))
    //     {
    //         printf("%c", toupper(s[i]));
    //     }
    //     else
    //     {
    //         printf("%c", s[i]);
    //     }
    // }
    for(int i = 0; i < strlen(s); i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}