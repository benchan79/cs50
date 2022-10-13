// https://sandbox.cs50.io/ae94d86f-10e4-455f-a8f5-49f35c6f06b4
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# define MAX 1000

int only_digits(char s[]);
char rotate(char c, int n);

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == 0)
    {    
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    char plain_text[MAX];
    printf("plaintext:  ");
    fgets(plain_text, MAX, stdin);

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        printf("%c", rotate(plain_text[i], key));
    }

    return 0;
}

int only_digits(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

char rotate(char c, int n)
{
        if (islower(c))
        {
            c = (int) c - 'a';
            return (char) (((c + n) % 26) + 'a');
        }
        else if (isupper(c))
        {
            c = (int) c - 'A';
            return (char) (((c + n) % 26) + 'A');
        }
        else
        {
            return c;
        }
}