#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    num % 2 ? "Odd!" : "Even!";

    return 0;
}