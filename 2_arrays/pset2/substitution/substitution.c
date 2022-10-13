// # include <cs50.h>
// # include <stdio.h>
// # include <string.h>
// # include <ctype.h>
// # include <stdlib.h>

// int key_length(char s[]);
// int only_alpha(char s[]);
// int duplicates(char s[]);
// char map(char c, char s[]);

// int main(int argc, string argv[])
// {
//     // Checks if user entered 0 command-line argument or more than 1 command-line argument
//     if (argc != 2)
//     {
//         printf("Usage: ./substitution key\n");
//         return 1;
//     }
//     // Checks if user entered a key containing 26 characters
//     else if (key_length(argv[1]) == 0)
//     {
//         printf("Key must contain 26 characters.\n");
//         return 1;
//     }
//     // Checks if user entered a key containing any character that is not an alphabetic character
//     else if (only_alpha(argv[1]) == 0)
//     {
//         printf("Key must only contain alphabetic characters.\n");
//         return 1;
//     }
//     // Checks if user entered a key that is not containing each letter exactly once
//     else if (duplicates(argv[1]) == 0)
//     {
//         printf("Key must not contain repeated characters.\n");
//         return 1;
//     }

//     // Get plaintext from user (key is valid from the above conditions)
//     string plain_text = get_string("plaintext:  ");

//     // Return plaintext’s corresponding ciphertext based on key
//     printf("ciphertext: ");
//     for (int i = 0; i < strlen(plain_text); i++)
//     {
//         printf("%c", map(plain_text[i], argv[1]));
//     }

//     printf("\n");

//     return 0;
// }

// // Checks if user entered a key containing 26 characters
// int key_length(char s[])
// {
//     if (strlen(s) != 26)
//     {
//         return 0;
//     }
//     return 1;
// }

// // Checks if user entered a key containing any character that is not an alphabetic character
// int only_alpha(char s[])
// {
//     for (int i = 0; i < strlen(s); i++)
//     {
//         if (isalpha(s[i]) == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// // Checks if user entered a key that is not containing each letter exactly once
// int duplicates(char s[])
// {
//     for (int i = 0; i < strlen(s); i++)
//     {
//         for (int j = 0; j < strlen(s); j++)
//         {
//             if ((s[i] == s[j]) && (i != j))
//             {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

// // Substitute and return alphabetical character in plaintext
// // with corresponding character in ciphertext
// char map(char c, char s[])
// {
//     if (islower(c))
//     {
//         int i = (int) c - 'a';
//         return tolower(s[i]);
//     }
//     else if (isupper(c))
//     {
//         int i = (int) c - 'A';
//         return toupper(s[i]);
//     }
//     else
//     {
//         return c;
//     }
// }