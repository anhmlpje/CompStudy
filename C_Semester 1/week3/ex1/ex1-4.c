#include <stdio.h>

int main() {
    int a;

    printf("Enter the temperatur: ");
    scanf("%d", &a);
    if (a < -10 || a > 40)
    {
        printf("not in range\n");
    }
    else
    {
        printf("this in range\n");
    }
    return 0;
}