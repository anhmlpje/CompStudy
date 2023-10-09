#include <stdio.h>

int main() {
    double value1, value2, temp;
    printf("Enter the value1: ");
    scanf("%lf", &value1);
    printf("Enter the value2: ");
    scanf("%lf", &value2);

    temp = value1;
    value1 = value2;
    value2 = temp;

    printf("Now, the value1 is %lf\n", value1);
    printf("the value2 is %lf\n", value2);

    return 0;
}