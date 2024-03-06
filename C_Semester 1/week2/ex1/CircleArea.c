#include <stdio.h>
#include <math.h>

int main() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    area = 3.142 * pow(radius, 2);

    printf("The area of the circle is %.2lf\n", area);

    return 0;
}