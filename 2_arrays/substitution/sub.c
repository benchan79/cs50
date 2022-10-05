# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# define MAX 1000

int only_alpha(char s[]);
int key_length(char s[]);
int duplicates(char s[]);
char map(char c, char s[]);

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (key_length(argv[1]) == 0)
    {    
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (only_alpha(argv[1]) == 0)
    {    
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (duplicates(argv[1]) == 0)
    {    
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // char* key = argv[1];
    char plain_text[MAX];
    printf("plaintext:  ");
    fgets(plain_text, MAX, stdin);

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        printf("%c", map(plain_text[i], argv[1]));
    }

    printf("\n");

    return 0;
}

int only_alpha(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int key_length(char s[])
{       
    if (strlen(s) != 26)
        {
            return 0;
        }
    return 1;
}

int duplicates(char s[])
{       
    int count = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        count += toupper(s[i]);
    }

    if (count != 2015)
        {
            return 0;
        }
    return 1;
}

char map(char c, char s[])
{
        if (islower(c))
        {
            c = (int) c - 'a';
            
            return tolower(s[c]);
        }
        else if (isupper(c))
        {
            c = (int) c - 'A';
            return toupper(s[c]);
        }
        else
        {
            return c;
        }
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// abcdefghijklmnopqrstuvwxyz
// VcHpRzGjNtLsKfBdQwAxEuYmOi