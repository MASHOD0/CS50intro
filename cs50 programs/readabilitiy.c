#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//Prototype isLetter()
bool isLetter(char c);

//Starts main function. If return == 0 then: all OK; else: exit|error
int main(void)
{
    //Get user's text input.
    string text = get_string("Text: ");

    //Define variables
    int letters = 0, words = 0, sentences = 0;

    //loop each char from text. Then calculate letters, words, sentences.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //int actual == i;
        int previous = i - 1;
        //Comparison based on the ASCII table
        if (isLetter(text[i]))
        {
            letters++;
        }
        //words++ if is a "space + letter";   And it cant check the first word, soo we'll add that one later.
        else if (text[i] == 32)
        {
            //if the word is inside a quote or double quote
            if (text[i + 1] == 34 || text[i + 1] == 39)
            {
                if (isLetter(text[i + 2]))
                {
                    words++;
                }
            }
            else
            {
                if (isLetter(text[i + 1]))
                {
                    words++;
                }
            }

        }
        //checks for period, interrogation and exclamation signals.
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
            //Check if there's any signal repeated (like "..." "!!!" "???" "?!?")
            if (text[i - 1] == 33 || text[i - 1] == 46 || text[i - 1] == 63)
            {
                sentences -= 1;
            }
        }

    }
    //adding one word because it cant check the first one. (see inside the for loop)
    words += 1;

    //Doing the Coleman-Liau index calculation
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
       float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    //checks if grade is bigger or equal to 16
    if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i", grade);
    }


    printf("\n");
    return 0;
}

//This simple function checks if the given character is a letter or not.
bool isLetter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}