#include <stdio.h>
#include <string.h>

size_t mystrlen(char *s)
{
    int count = 0;
    char *s2 = s;
    while (*s2 != '\0')
    {
        count++;
        s2++;
    }
    return count;
}

char *mystrcat(char *dest, char *src)
{
    int next = mystrlen(dest);
    int size_src = mystrlen(src);
    char *dest2 = dest;
    for (int i = 0; i < mystrlen(src) + 1; i++)
    {
        dest2[next] = src[i];
        next++;
    }
    return dest2;
}

char *mystrstr(char *haystack, const char *needle)
{
    char *equal;
    char *haystack2 = haystack;

    // check
    while (*haystack2 != '\0')
    {
        if (*haystack2 == needle[0])
        {
            equal = haystack2;
            while (*needle != '\0')
            {
                if (*haystack2 != *needle)
                {
                    break;
                }
                needle++;
                haystack2++;
            }
        }
        haystack2++;
    }
    if (*needle == '\0')
    {
        return equal;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    char buffer[64];
    fgets(buffer, 32, stdin);
    if (buffer[mystrlen(buffer) - 1] == '\n')
    {
        buffer[mystrlen(buffer) - 1] = '\0';
    }

    // Test mystrlen function
    printf("Length = %lu\n", mystrlen(buffer));

    // Test mystrcat function
    mystrcat(buffer, "KMUTT");
    printf("After concat = %s\n", buffer);
    printf("Length = %lu\n", mystrlen(buffer));

    // Test strstr
    char *result = mystrstr(buffer, "KMUTT");
    if (result != NULL)
    {
        printf("Position of KMUTT = %ld\n", result - buffer);
    }
    else
    {
        printf("Not found\n");
    }

    result = mystrstr(buffer, "love");
    if (result != NULL)
    {
        printf("Position of love = %ld\n", result - buffer);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}