//65070501066
#include <stdio.h>
double findMean(int array[], int size)
{
    double avg = 0, total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    avg = total / size;
    return avg;
}

int findMinElement(int array[], int size)
{
    int min;
    min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

int findMaxIndex(int array[], int size)
{
    int max,index=0;
    max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            index = i;
        }   
    }
    return index;
}

int displayArray(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("numbers[%d] = %d\n",i,array[i]);
    }
}

void getArrayFromUser(int array[],int *size)
{
    printf("Enter size of array(2-10): ");
    scanf("%d", size);
    printf("\n");
    for (int i = 0; i < *size; i++)
    {
        printf("Enter numbers[%d]: ", i);
        scanf("%d", &array[i]);
    }
}

int getSelectMenu()
{
    printf("Menu\n");
    printf("1 - Find the average value of all the numbers in the array\n");
    printf("2 - Find the minimum value in the array\n");
    printf("3 - Find the index of the maximum value in the array\n");
    printf("4 - Display all numbers\n");
    printf("5 - Edit array\n");
    printf("6 - Exit\n");
    printf("Please select an option (1-6) > ");

    int selectedMenu;
    scanf("%d", &selectedMenu);
    return selectedMenu;
}

int main()
{
    int numbers[10] = {3,9,-2,1,5};
    int size=5;
    int menu = getSelectMenu();
    while (menu != 6)
    {
        if (menu == 1)
        {
            printf("Mean = %.2lf\n\n", findMean(numbers, size));
        }
        else if (menu == 2)
        {
            printf("Min = %d\n\n", findMinElement(numbers, size));
        }
        else if (menu == 3)
        {
            printf("Max Index = %d\n\n", findMaxIndex(numbers, size));
        }
        else if (menu == 4)
        {
            printf("Display array\n");
            displayArray(numbers,size);     
        }
        else if (menu == 5)
        {
            getArrayFromUser(numbers,&size);
        }
        menu = getSelectMenu();
    }

    return 0;
}