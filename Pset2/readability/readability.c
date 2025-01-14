//#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float grade_function(string text);

int main(void)
{

    // TODO
    // ask user for "Text" using string = get_string.
    prinft("Text: ");
    scantf("%s", text);
    float grade = grade_function(text);

    return 0;
} // END OF MAIN

// count letters function
// IF Char is NOT Alphanumeric do not count.
// ELSE IF count char/string.
// other way to do this funtion is with ISALNUM but couldnt figure out how to do it
// used lecture example instead.
int count_letters(string text)
{

    int letters = 0; // intialize int letters to 0

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 1; // words initialize at 1 for if they start at 0, we get 1 less word than expected.
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == ' ')
        {
            words++;
        }
    return words;
}

int count_sentences(string text)
{

    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
        if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!'))
        {
            sentences++;
        }

    return sentences;
}
float grade_function(string text)
{

    float index =
        0.0588 * count_letters(text) * 100 / count_words(text) - 0.296 * count_sentences(text) * 100 / count_words(text) - 15.8;
    int grade = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return index;
}
