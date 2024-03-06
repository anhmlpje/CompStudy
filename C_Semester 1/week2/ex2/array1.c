#include <stdio.h>

int main() {
    int arr[5], sum = 0, i;

    for (i = 0; i < 5; i++)
    {
        printf("Enter a number:");
        scanf("%d", &arr[i]);
    }

    for (i=0; i<5;i++)
    {
        sum += arr[i];
    }

    printf("sum: %d\n", sum);

    return 0;
}