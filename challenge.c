#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countCapital(char word[])
{
    int count = 0;
    int check = 0;
    char* word2 = word;
    char* done = "DONE";
    while (*word2 != '\0')
    {
        // DONE check
        if (word[0] == 'D' && check == 0)
        {
            while (*done != '\0')
            {
                if (*done != *word)
                {
                    check++;
                    break;
                }
                done++;
                word++;   
            }
            
            // HAVE DONE
            if (*done == '\0')
            {
                printf("GOODBYE !\n");
                return 0;
            }
        }

        // check Capital letter after check DONE
        if (isupper(*word2) == 1)
        {
            count++;
        }
        word2++;
    }

    return count;
    
}

int main()
{
    char word[32];
    int i;
    fgets(word, 30, stdin);
    /*
    for (i = 0; i < 15; i++)
    {
        printf("%c",word[i]);
    }
    */
    

    int count = countCapital(word);

    if (count != 0)
    {
        printf("Capital letter found : %d\n", count);
    }
    
}