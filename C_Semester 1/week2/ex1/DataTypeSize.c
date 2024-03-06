#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    printf("%lu\n", sizeof(int));
    printf("int Maximum: %d\n", INT_MAX );
    printf("int Minimum: %d\n", INT_MIN );
    printf("%lu\n", sizeof(float));
    printf("float Maximum: %E\n", FLT_MAX );
    printf("float Minimum: %E\n", FLT_MIN );
    printf("%lu\n", sizeof(double));
    printf("double Maximum: %E\n", DBL_MAX );
    printf("double Minimum: %E\n", DBL_MIN );
    printf("%lu\n", sizeof(char));
    printf("char Maximum: %d\n", CHAR_MAX );
    printf("char Minimum: %d\n", CHAR_MIN );

    return 0;
}