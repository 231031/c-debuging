#include <stdio.h>
#include <math.h>

double findHypotenuse(int adjacent, int opposite)
{
    return sqrt(pow(adjacent, 2) + pow(opposite, 2));
}

int main()
{
    int adjacent, opposite;
    double answer = 0;
    scanf("%d %d", &adjacent, &opposite);
    answer = findHypotenuse(adjacent, opposite);
    printf("%.2lf", answer);
    return 0;
}