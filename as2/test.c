#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MINIMUM_SIZE 5


char userinput;
int mazew, mazeh;

//The length and width test of the maze
//character test
void test(const char* filename){
    char line[MAX_SIZE];
    int lineLength;
    int height = 0;
    int width = 0;
    bool START = false, END = false;

    // open file
    FILE *file = fopen(filename, "r");
    if(!file){
        printf("Error: Could not find or open the file.\n");
        return;
    }

    // Calculate length and width
    while (fgets(line, MAX_SIZE, file)) {

        lineLength = strlen(line);
        
        if (height == 0) {
            if (line[lineLength - 1] == '\n') {
                lineLength -= 1;
                line[lineLength] = '\0';
            }
            width = lineLength;
        // Check whether the width meets the requirements
        if (width > MAX_SIZE || width < MINIMUM_SIZE) {
            printf("Width must be between 5 and 100.\n");
        }
        } else {
            // Check that the lengths are the same
            if (line[lineLength - 1] == '\n') lineLength -= 1;
            if (lineLength != width) {
                printf("Invalid maze: rows are not the same length.\n");
            }
        }
        height++;

        //test for character
        for (int i = 0; i < lineLength; i++) {
            if (line[i] != '#' && line[i] != ' ' && line[i] != 'S' && line[i] != 'E') {
                printf("File have invalid character\n");
            }
            if(line[i] == 'S'){
                START = true;
            }if(line[i] == 'E'){
                END = true;
            }
        }
    }

    fclose(file);
    // Check whether the height meets the requirements
    if (height > MAX_SIZE || height < MINIMUM_SIZE) {
        printf("Height must be between 5 and 100.\n");
    }

    if (!START || !END) {
    printf("The maze has not Start or Exit\n");
    }

    mazew = width;
    mazeh = height;
    }

//test whether the user moves into the wall
//test have the user reached the exit
int move_test(){
    char arraymaze[MAX_SIZE][MAX_SIZE];
    int user_x = 1, user_y = 1;
    int start_x, start_y;
    if(userinput == 'w' ||userinput == 'W')
    {
        if(arraymaze[user_y - 1][user_x] == '#'){
            printf("Can not move into the wall\n");
            return 1;
        }if(user_y - 1 < 0){
            printf("Can not move outside the maze\n");
            return 1;
        }if(arraymaze[user_y - 1][user_x] == 'E'){
            printf("Exits the maze\n");
            return 2;
        }
    }

    if(userinput == 's' ||userinput == 'S')
    {
        if(arraymaze[user_y + 1][user_x] == '#'){
            printf("Can not move into the wall\n");
            return 1;
        }if(user_y + 1 >= mazeh){
            printf("Can not move outside the maze\n");
            return 1;
        }if(arraymaze[user_y + 1][user_x] == 'E'){
            printf("Exits the maze\n");
            return 2;
        }
    }
    if(userinput == 'a' ||userinput == 'A')
    {	
        if(arraymaze[user_y][user_x - 1] == '#'){
            printf("Can not move into the wall\n");
            return 1;
        }if (user_x - 1 < 0){
            printf("Can not move outside the maze\n");
            return 1;
        }if(arraymaze[user_y][user_x - 1] == 'E'){
            printf("Exits the maze\n");
            return 2;
        }
    }
    if(userinput=='d' ||userinput == 'D')
    {
        if(arraymaze[user_y][user_x+1] == '#'){
            printf("Can not move into the wall\n");
            return 1;
        }if(user_x + 1 >= mazew){
            printf("Can not move outside the maze\n");
            return 1;            
        }if(arraymaze[user_y][user_x+1] == 'E'){
            printf("Exits the maze\n");
            return 2;
        }
    }
}

int main(int argc, char *argv[]){
    const char* filename = argv[1];
    test(filename);
return 0;
}