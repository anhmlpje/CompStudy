#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {

    char *inputCopy = strdup(input);
    
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
    
    free(inputCopy);
                }

    void maxsteps();



int main() {
    FITNESS_DATA StepsTask[100];
    int buffer_size = 250;
    char line[buffer_size];
    int i = 0;//counter

    FILE *input = fopen("FitnessData_2023.csv", "r");
        if(input == NULL){
            printf("Error.\n");
            return 1;
        }

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

    char option;
    char checktname[100];
    char inputname[] = "FitnessData_2023.csv";

    printf("Menu Options: \n");
    printf("Enter choice: ");
    scanf("%c", &option);
    switch (option)
    {
    case 'A':
    printf("Input filename: ");
    scanf("%s", checktname);
    if(strcmp(checktname, inputname)){
        printf("Error: Could not find or open the file.\n");
    }
    else{
        printf("File successfully loaded.\n");
    }
    break;

    case 'B':
    printf("Total records: %d", i);
    break;

    case 'C':
    break;

    case 'D':
    break;

    case 'E':
    break;

    case 'F':
    break;

    case 'Q':
    break;

    default:
        printf("Invalid choice. Try again.\n");
    }

   return 0;
}