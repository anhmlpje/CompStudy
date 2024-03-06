#include <stdio.h>

int main() {
    int arr[10], sum;
    double mean;
    printf("Enter 10 numbers");
    for(int i = 0; i <10; i++){
        scanf("%d", arr[i]);
        sum += arr[i];
    }

    mean = sum / 10;

    printf("the average is %lf\n", mean);
    printf("%d\n", arr);
    
    return 0;
}