#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

int i;//recordcounter
FITNESS_DATA st[200];//StepsTask data storage

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

void inputdata() {
    int buffer_size = 250;
    char line[buffer_size];
    i = 0;

    FILE *input = fopen("FitnessData_2023.csv", "r");
        if(input == NULL){
            printf("Error: Could not open the file.\n");
        }

    char date[11];
    char time[6];
    char stepsStr[20];
    int steps;

    while (fgets(line, buffer_size, input))
    {
    tokeniseRecord(line, ",", date, time, stepsStr);

    steps = atoi(stepsStr);

    strcpy(st[i].date, date);
    strcpy(st[i].time, time);
    st[i].steps = steps;
    i++;
    }
    fclose(input);
}

void A_check() {
    char checktname[100];
    char inputname[] = "FitnessData_2023.csv";

    printf("Input filename: ");
    scanf("%s", checktname);
    if(strcmp(checktname, inputname)){
        printf("Error: Could not find or open the file.\n");
    }
    else{
        printf("File successfully loaded.\n");
    }
}

void C_Minimumsteps() {
    inputdata();
    int mini; //Minimum steps
    int n;
    int nnum;
    mini = st[0].steps;
    for(n = 0; n < i; n++){
        if(st[n].steps < mini){
            mini = st[n].steps;
            nnum = n;
        }
    }
    printf("Fewest steps: %s %s\n", st[nnum].date, st[nnum].time);
}

void D_Maximumsteps() {
    inputdata();
    int maxs; //Maximum steps
    int n;
    int nnum;
    maxs = st[0].steps;
    for(n = 0; n < i; n++){
        if(st[n].steps > maxs){
            maxs = st[n].steps;
            nnum = n;
        }
    }
    printf("Largest steps: %s %s\n", st[nnum].date, st[nnum].time);
}

void E_mean() {
    int mean;
    int sum = 0;
    int n;

    inputdata();
    for(n = 0; n < i; n++){
        sum += st[n].steps;
    }

    mean = sum / i;
    printf("Mean step count: %d\n", mean);
}

void F_continuous_period() {
    inputdata();
    int con1 = 0;//continuous period counter
    int con2 = 0;
    int start1;
    int start2;
    int finish = 0;

    for(int n = 0; n < i; n++){
        if(st[n].steps > 500){
            con1++;
            if(con1 == 1){
                start1 = n;
            }
        }else{
            con1 = 0;
            }
        
        if(con1 > con2){
            con2 = con1;
            start2 =start1;
        }
    }

    finish = start2 + con2 - 1;

    printf("Longest period start: %s %s\n", st[start2].date, st[start2].time);
    printf("Longest period end: %s %s\n", st[finish].date, st[finish].time);
}

int main() {
    char option;
    printf("Menu Options:\n"
           "A: Specify the filename to be imported\n"
           "B: Display the total number of records in the file\n"
           "C: Find the date and time of the timeslot with the fewest steps\n"
           "D: Find the date and time of the timeslot with the largest number of steps\n"
           "E: Find the mean step count of all the records in the file\n"
           "F: Find the longest continuous period where the step count is above 500 steps\n"
           "Q: Quit\n");
    printf("Enter choice: ");
    scanf("%c", &option);


    switch (option)
    {
        case 'A':
            A_check();
        break;

        case 'B':
            inputdata();
            printf("Total records: %d\n", i);
        break;

        case 'C':
            C_Minimumsteps();
        break;

        case 'D':
            D_Maximumsteps();
        break;

        case 'E':
            E_mean();
        break;

        case 'F':
            F_continuous_period();
        break;

        case 'Q'://quit
        break;

        default:
        printf("Invalid choice. Try again.\n");
    }

   return 0;
}