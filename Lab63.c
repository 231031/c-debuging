#include <stdio.h>
#include <string.h>
#include <ctype.h>

int size_email(char *email)
{
    char *email2 = email;
    int count = 0;
    while (*email2 != '\0')
    {
        count++;
        email2++;
    }
    return count-1; // delete enter 
}

// check space in email
int check_space(char *email, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (email[i] == ' ')
        {
            return 0;
        }
    }
    return 1;
}

// find index of @
int postionad(char *email)
{
    char *email2 = email;
    int count = 0, index = 0, count2 = 0;

    // check amount of @
    while (*email2 != '\0')
    {
        if (*email2 == '@')
        {
            index = count;
            count2++;
        }
        email2++;
        count++;
    }

    if (count2 != 1)
    {
        return 0;
    }
    else
    {
        //printf("Index is %d\n", index);
        return index;
    }
}

int check_email(char *email, int index)
{
    for (int i = 0; i < index; i++)
    {
        if ((email[i] < 48 || email[i] > 57) && (email[i] < 65 || email[i] > 90) && (email[i] < 97 || email[i] > 122) && email[i] != '-')
        {
            return 0;
        }
    }
    return 1;
}

int check_domain(char *email, int index)
{
    int i = 0, point = 0, k = 0;
    char *email2 = email;
    char *email3 = email;

    // check .
    while (i <= index)
    {
        i++;
        email3++;
    }
    while (*email3 != '\0')
    {
        if (*email3 == '.')
        {
            point = 1;
        }
        email3++;
    }
    if (point == 0)
    {
        return 0;
    }
  
    // check character numbers -
    while (k <= index)
    {
        k++;
        email2++;
    }
    while (*email2 != '\0')
    {
        if ((*email2 < 48 || *email2 > 57) && (*email < 65 || *email2 > 90) && (*email2 < 97 || *email2 > 122) && *email2 != '-' && *email2 != '.')
        {
            return 0;
        }
        email2++;
    }
    return 1;
}

int main()
{
    char email[30];
    int index = 0, size = 0;
    fgets(email, 30, stdin);
    printf("%s\n", email);
    index = postionad(email);
    size = size_email(email);
    if (index == 0 || check_space(email, size) == 0)
    {
        printf("INCORRECT");
    }
    else
    {
        if (check_email(email, index) == 0)
        {
            printf("INCORRECT");
        }
        else
        {
            if (check_domain(email, index) == 0)
            {
                printf("INCORRECT");
            }
            else
            {
                printf("CORRECT");
            }
        }
    }

    return 0;
}