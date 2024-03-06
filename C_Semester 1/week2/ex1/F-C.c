#include <stdio.h>
int main() {
    double Fahrenheit, Celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &Fahrenheit);

    Celsius = (Fahrenheit -32) / 1.8;

    printf("%lf Fahrenheit is %lf Celsius\n", Fahrenheit, Celsius);
    return 0;
}