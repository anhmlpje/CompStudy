#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");

    int arr1[200];
    char line[100];
    int i = 0;

    while(fgets(line, 100, input)){
        arr1[i] = atoi(line);
        printf("%d\n", arr1[i]);
        i++;
    }
    fclose(input);

    for(int i = 0; i < 200; i++){
        
    }

    return 0;
}