#include <stdio.h>

int main() {
    int arr[5];
    int sum = 0;

    printf("Enter five integer:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%d:", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("The summation is: %d\n", sum);

    return 0;
}