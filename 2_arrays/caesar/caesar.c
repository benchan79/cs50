#include <cs50.h>
#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int only_digits(char s[]);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Checks for missing argument or more than 1 argument
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

    // Converts argument type from string to integer
    int key = atoi(argv[1]);

    // Gets plaintext from user
    string plain_text = get_string("plaintext:  ");

    // Returns ciphertext to user
    printf("ciphertext: ");
    // Iterates over every char in the user’s plaintext,
    // calling rotate on each, and printing the return value thereof.
    for (int i = 0; i < strlen(plain_text); i++)
    {
        printf("%c", rotate(plain_text[i], key));
    }
    printf("\n");
    return 0;
}

// Function to check if key is numeric
int only_digits(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Function to rotates that char c by that n positions
char rotate(char c, int n)
{
    if (islower(c))
    {
        c = (int) c - 'a';
        return (char)(((c + n) % 26) + 'a');
    }
    else if (isupper(c))
    {
        c = (int) c - 'A';
        return (char)(((c + n) % 26) + 'A');
    }
    else
    {
        return c;
    }
}