#include <stdio.h>
#include <math.h>

float V(float r){
    return (4.0 / 3.0) * (3.14 * pow(r, 3));
}

int main() {
    float a;
    printf("Enter the radius: ");
    scanf("%f", &a);
    printf("The Volume of a Sphere is %f\n", V(a));
    return 0;
}