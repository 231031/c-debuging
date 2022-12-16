#include <stdio.h>
#include <math.h>

void bmiInput(char name[], double* weight, double* height)
{
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your weight: ");
    scanf("%lf", weight);
    printf("Enter your height: ");
    scanf("%lf", height);
    //printf("%.2lf\n", *height);
}


int main()
{
    char name[32];
    double weight = 0;
    double height = 0;
    double bmi = 0;
    bmiInput(name, &weight, &height);
    bmi = weight/(pow(height, 2));
    printf("%s, your BMI is %.2lf", name, bmi);


    return 0;   
}