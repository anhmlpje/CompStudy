#include <stdio.h>
#include <math.h>

int main() {
    double day, sum;
    printf("Enter how many days you want the light to go: ");
    scanf("%lf", &day);

    sum = day * 2.592 * pow(10, 13);
    
    printf("%E m the light travelled\n", sum);
    return 0;
}