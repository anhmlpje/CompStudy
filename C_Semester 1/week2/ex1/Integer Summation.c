#include <stdio.h>

int main() {
    int first, second, sum;
    printf("Enter the first integer: ");
    scanf("%d", &first);
    printf("Enter the second integer: ");
    scanf("%d", &second);

    sum = first + second;

    printf("The sum is: %d\n", sum);

    return 0;
}