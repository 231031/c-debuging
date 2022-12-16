#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LENGTH 16
#define MAX_RETRY_COUNT 10

void initGuess(char str[], int length)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        str[i] = '_';
    }
    str[i] = '\0';
}

void printGuess(char str[])
{
    while (*str != '\0')
    {
        printf("%c ", *str);
        str++;
    }
    printf("\n");
}

int getNumber(char prompt[], int min, int max)
{
    int n;
    char buffer[16];
    do
    {
        printf("%s (%d-%d) > ", prompt, min, max);
        fgets(buffer, 16, stdin);
        sscanf(buffer, "%d", &n);
    } while (n < min || n > max);
    return n;
}

int getUppercaseChar(char prompt[])
{
    char c;
    char buffer[16];
    do
    {
        printf("%s > ", prompt);
        fgets(buffer, 16, stdin);
        sscanf(buffer, "%c", &c);
    } while (c < 'A' || c > 'Z');
    return c;
}

int main()
{
    srand(time(NULL));
    char wordList[][MAX_WORD_LENGTH] = {"ANT", "RAT", "AMOGUS", "RACCOON", "FISH", "LIZARD"};
    char guess[MAX_WORD_LENGTH];
    char replay;

    do
    {
        int r = rand() % 5;
        initGuess(guess, strlen(wordList[r]));

        int numWrongGuess = 0;
        while (strcmp(guess, wordList[r]) != 0 &&
               numWrongGuess < MAX_RETRY_COUNT)
        {
            printGuess(guess);

            int guessIndex = getNumber("Which character do you want to guess?", 1,
                                       strlen(wordList[r]));
            int guessValue = getUppercaseChar("Your guess is");

            if (guessValue == wordList[r][guessIndex - 1])
            {
                guess[guessIndex - 1] = guessValue;
            }
            else
            {
                numWrongGuess++;
            }
        }
        if (numWrongGuess < MAX_RETRY_COUNT)
        {
            printf("You win!!!\n");
        }
        else
        {
            printf("You lose!!!\n");
        }

        printGuess(guess);
        replay = getUppercaseChar("Do you want to play again?");
    } while (replay == 'Y');

    return 0;
}
