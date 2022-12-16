#include <stdio.h>
void getInput(char name[][15], double score[][5])
{
    char re[10];
    char re2[10];
    char *name2;
    for (int i = 0; i < 5; i++)
    {
        printf("Student #%d Name > ", i + 1);
        fgets(&name[i][0], 15, stdin);

        printf("Student #%d Math Score > ", i + 1);
        fgets(re, 10, stdin);
        sscanf(re, "%lf", &score[0][i]);

        printf("Student #%d English Score > ", i + 1);
        fgets(re2, 10, stdin);
        sscanf(re2, "%lf", &score[1][i]);
        // change \n is \0
        name2 = name[i];
        // printf("name2(p) %p\n",name2);
        // printf("name[i] (p) %p\n",name[i]);
        while (*name2 != '\0')
        {
            if (*name2 == '\n')
            {
                *name2 = '\0';
            }
            name2++;
        }
    }
}

void checkMath(char name[][15], double score[][5])
{
    double max = score[0][0],min = score[0][0];
    int inMax = -1,inMin = -1;
    for(int i = 0; i<5; i++)
    {
        if (score[0][i] > max)
        {
            max = score[0][i];
        }
        if (score[0][i] < min)
        {
            min = score[0][i];
        }
    }

    for (int i=0;i<5;i++)
    {
        if (score[0][i] == max && inMax == -1)
        {
            inMax = i;
        }
        if (score[0][i] == min && inMin == -1)
        {
            inMin = i;
        }
    }

    printf("Math (Max) Name = %s Score = %.2f\n",name[inMax],max);
    printf("Math (Min) Name = %s Score = %.2f\n",name[inMin],min);
}

void checkEng(char name[][15], double score[][5])
{
    double max = score[1][0],min = score[1][0];
    int inMax = -1,inMin = -1;
    for(int i = 0; i<5; i++)
    {
        if (score[1][i] > max)
        {
            max = score[1][i];
        }
        if (score[1][i] < min)
        {
            min = score[1][i];
        }
    }

    for (int i=0;i<5;i++)
    {
        if (score[1][i] == max && inMax == -1)
        {
            inMax = i;
        }
        if (score[1][i] == min && inMin == -1)
        {
            inMin = i;
        }
    }

    printf("English (Max) Name = %s Score = %.2f\n",name[inMax],max);
    printf("English (Min) Name = %s Score = %.2f\n",name[inMin],min);
}

int main()
{
    char name[5][15];
    double score[2][5]; // index 0 is Math and index 1 is Eng
    getInput(name, score);
    checkMath(name,score);
    checkEng(name,score);
    /*
    for (int i = 0; i < 5; i++)
    {
        printf("name1 is %s\n", name[i]);
        printf("Math1 %d\n", score[0][i]);
        printf("Eng1 %d\n", score[1][i]);
    }
    */
    return 0;
}