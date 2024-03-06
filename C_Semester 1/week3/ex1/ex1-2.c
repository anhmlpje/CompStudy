#include <stdio.h>

int main() {
    int a;

    printf("Enter a number: ");
    scanf("%d", &a);

    if (a%4 == 0 && a%5 == 0)
    {
        printf("This number is divisible by both 4 and 5\n");
    }
    else
    {
        printf("Thie number is not divisible by both 4 and 5\n");
    }
    return 0;
}