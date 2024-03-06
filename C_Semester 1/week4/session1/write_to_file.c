#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    int num_lines;
    int sum = 0;
    double mean;

    printf("How many numbers you want to enter: ");
    scanf("%d", &num_lines);
    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        sum += number;
        fprintf(file, "%d\n", number);
    }

    mean = sum / num_lines;

    fprintf(file, "%lf\n", mean);

    fclose(file);
    return 0;
}