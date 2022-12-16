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
    int max;
    max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int getSelectMenu() {
    printf("Menu\n");
    printf("1 - Find the average value of all the numbers in the array\n");
    printf("2 - Find the minimum value in the array\n");
    printf("3 - Find the index of the maximum value in the array\n");
    printf("4 - Exit\n");
    printf("Please select an option (1-4) > ");

    int selectedMenu;
    scanf("%d", &selectedMenu);
    return selectedMenu;
}

int main(){
    int numbers[5] = {3, 9, -2, 7, 1}; 

    int menu = getSelectMenu();
    while (menu != 4) {
        if (menu == 1) {
            printf("Mean = %2lf\n\n", findMean(numbers, 5));
        } else if (menu == 2) {
            printf("Min = %d\n\n", findMinElement(numbers, 5));
        } else if (menu == 3) {
            printf("Max Index = %d\n\n", findMaxIndex(numbers, 5));
        }
        menu = getSelectMenu();
    }

    return 0;
}