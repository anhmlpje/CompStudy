#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    FitnessData StepsTask[100];
    int buffer_size = 250;
    char line[buffer_size];
    int i = 0;//counter

    FILE *input = fopen("FitnessData_2023.csv", "r");

    char date[11];
    char time[6];
    int steps;

    while (fgets(line, buffer_size, input))
    {
    tokeniseRecord(line, ",", date, time, steps);

    strcpy(StepsTask[i].date, date);
    strcpy(StepsTask[i].time, time);
    StepsTask[i].steps = steps;
    i++;
    }
    fclose(input);
    
    printf("Number of records in file: %d\n", i);

    for(int n = 0; n < 3; n++){
        printf("%s/%s/%d\n", StepsTask[n].date, StepsTask[n].time, StepsTask[n].steps);
    }

    return 0;

}