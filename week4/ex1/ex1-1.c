#include <stdio.h>

int main() {
    char* filename = "squares.dat";
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        printf("Error\n");
        return 1;
    }
    
    int n;
    int num;
    int sum;

    printf("Enter a number: ");
    sacnf("%d\n", &num);

    for(int i = 1; i < num; i++){
        sum = i * i;
        fprintf("%d\n", sum);
    }

    return 0;
}