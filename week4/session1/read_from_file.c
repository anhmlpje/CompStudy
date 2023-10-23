#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int line_number = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
        line_number++;
    }

    printf("There are %d lines.\n", line_number);

    fclose(file);
    return 0;
}