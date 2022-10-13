#include <ctype.h>
//#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000

// Compile using this command: cc read.c -o read -lm
// Or this command: "gcc read.c -o read -lm"
// Need to link with the math library
// The math library functions are not part of standard C library 
// which is linked by default. So you need to link it yourself.
// https://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void) 
{
    char input_text[MAX];
    printf("Text:");
    fgets(input_text, MAX, stdin);
    int letter_count = count_letters(input_text);
    int word_count = count_words(input_text);
    int sentence_count = count_sentences(input_text);
    // printf("%i\n", letter_count);
    // printf("%i\n", word_count);
    // printf("%i\n", sentence_count);
    
    float L = letter_count / (float) word_count * 100;
    float S = sentence_count / (float) word_count * 100;
    // printf("%f\n", L);
    // printf("%f\n", S);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    printf("%i\n", index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(char text[])
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char text[])
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}