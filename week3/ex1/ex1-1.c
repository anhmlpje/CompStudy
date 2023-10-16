#include <stdio.h>

int main() {
    double num;
    printf("Enter a number:");
    scanf("%lf", &num);

    if (num == 0)
    {
        printf("This number is zero\n");
    }
    else if (num > 0)
    {
        printf("%lf is positive\n", num);
    }
    else
    {
        printf("%lf is negative\n", num);
    }
    return 0;
}