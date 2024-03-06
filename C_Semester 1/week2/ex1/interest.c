#include <stdio.h>

int main() {
    float principal, rate, sum;
    int time;

    printf("Enter the principal: ");
    scanf("%f", &principal);
    printf("Enter the rate:%%"); 
    scanf("%f", &rate);
    printf("Enter how many years do you want save for: ");
    scanf("%d", &time);

    sum = principal * time * rate * 0.01;

    printf("%.2f is the simple interest after %d years\n", sum, time);

    return 0;
}