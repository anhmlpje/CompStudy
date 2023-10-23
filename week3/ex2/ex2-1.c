#include <stdio.h>
#include <math.h>

float area(float r){
    return 3.14 * pow(r, 2);
}

int main() {
    float a;
    printf("Enter the radius: ");
    scanf("%f", &a);
    printf("The area of the circle is %f\n", area(a));
    return 0;
}