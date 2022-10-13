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
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < strlen(s); j++)
        {
            if ( (s[i] == s[j]) && (i != j) )
            {
                return 0;
            }
        }
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

// :) encrypts "A" as "Z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
// :) encrypts "a" as "z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
// :) encrypts "ABC" as "NJQ" using NJQSUYBRXMOPFTHZVAWCGILKED as key
// :) encrypts "XyZ" as "KeD" using NJQSUYBRXMOPFTHZVAWCGILKED as key
// :) encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZTEOGXHCIPJSQD as key
// :) encrypts "This is CS50" as "Cbah ah KH50" using yukfrnlbavmwzteogxhcipjsqd as key
// :) encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZteogxhcipjsqd as key
// :) encrypts all alphabetic characters using DWUSXNPQKEGCZFJBTLYROHIAVM as key
// sending input The quick brown fox jumps over the lazy dog...
// checking for output "ciphertext: Rqx tokug wljif nja eozby jhxl rqx cdmv sjp\n"...
// :) does not encrypt non-alphabetical characters using DWUSXNPQKEGCZFJBTLYROHIAVM as key
// sending input Shh... Don't tell!...
// checking for output "ciphertext: Yqq... Sjf'r rxcc!\n"...
// :) handles lack of key "./substitution"
// :) handles too many arguments "./substitution abcdefghijklmnopqrstuvwxyz abc"
// :) handles invalid key length "./substitution QTXDGMKIPV"
// :) handles invalid characters in key ./substitution ZWGKPMJ^YISHFEXQON[DLUACVT"
// :) handles duplicate characters in uppercase key "./substitution FAZRDTMGQEJPWAXUSKVIYCLONH"
// :) handles duplicate characters in lowercase key "./substitution fazrdtmgqejpwaxuskviyclonh"
// :) handles multiple duplicate characters in key "./substitution MMCcEFGHIJKLMNOPqRqTUVWXeZ"