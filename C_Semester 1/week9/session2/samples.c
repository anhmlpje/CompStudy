#include <stdio.h>
#include <stdlib.h>

int main() {
//    char address[200];
//    int data[70];

//    int size;
//    printf("Enter the size of the array of doubles (samples): ");
//    scanf("%d", &size);

//  double samples[size];

    char* address = malloc(200*sizeof(char));

    int* data = malloc(70*sizeof(int));

    int count;
    printf("Enter the number of values: ");
    scanf("%d", &count);

    double* samples =malloc(count*sizeof(double));



    return 0;
}
}