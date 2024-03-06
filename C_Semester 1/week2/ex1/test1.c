#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    num % 2 ? printf("Odd!\n") : printf("Even!\n");

    return 0;
}