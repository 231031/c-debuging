#include <stdio.h>
#include <ctype.h>
#include <string.h>
int check_numbers(char telephone[])
{
    int count=0;
    char *telephone2 = telephone; 
    while(*telephone2 != '\0') // check amount of telephone number
    {
        count++; 
        telephone2++;
    }
    if(count-1 > 15) // delete count enter
    {
        return 0;
    }
    for (int i = 0; i < 15; i++) // if false return 0 and if true return 1
    {
        if (i == 0 || i == 3 || i == 6 || i == 10)
        {
            if (i == 0 && telephone[i] != '+')
            {
                return 0;
            }
            if ((i == 3 || i == 6 || i == 10) && telephone[i] != '-')
            {
                return 0;
            }
        }
        else
        {
            if (telephone[i] <= 47 || telephone[i] >= 58)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main(void)
{
    int check = 1;
    char telephone[20];
    fgets(telephone, 20, stdin);
    check = check_numbers(telephone);

    if (check == 0)
    {
        printf("INCORRECT");
    }
    else
    {
        printf("CORRECT");
    }

    return 0;
}