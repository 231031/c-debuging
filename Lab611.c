#include <stdio.h>
#include <string.h>

size_t mystrlen(char *s)
{
    char *s2 = s;
    int count = 0;
    while (*s2 != '\0')
    {
        count++;
        s2++;
    }
    return count;
}

char *mystrcat(char *dest, char *src)
{
}

char *mystrstr(char *haystack, const char *needle)
{
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

    return 0;
}