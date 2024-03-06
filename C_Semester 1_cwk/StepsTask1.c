#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main() {
    FITNESS_DATA StepsTask[100];
    int buffer_size = 250;
    char line[buffer_size];
    int i = 0;//counter

    FILE *input = fopen("FitnessData_2023.csv", "r");

    char date[11];
    char time[6];
    char stepsStr[20];
    int steps;

    while (fgets(line, buffer_size, input))
    {
    tokeniseRecord(line, ",", date, time, stepsStr);

    steps = atoi(stepsStr);

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