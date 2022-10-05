#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text from user.
    string input_text = get_string("Text: ");

    // Call the various functions to count the letters, words and sentences in the text.
    int letter_count = count_letters(input_text);
    int word_count = count_words(input_text);
    int sentence_count = count_sentences(input_text);

    // Calulate L and S
    float L = letter_count / (float) word_count * 100;
    float S = sentence_count / (float) word_count * 100;

    // Calculate Coleman-Liau index using L and S, rounding to nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Check and print Grade level of text
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

// Function to count letters in text
int count_letters(string text)
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

// Function to count words in text
int count_words(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}

// Function to counts sentences in text
int count_sentences(string text)
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