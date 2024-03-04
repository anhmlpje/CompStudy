#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MINIMUM_SIZE 5

// Function to load the maze from a file
void loadMaze(const char *filename, char maze[MAX_SIZE][MAX_SIZE], int *width, int *height) {
    FILE *file = fopen(filename, "r");

    char line[MAX_SIZE];
    *height = 0;

    while (fgets(line, sizeof(line), file)) {
        *width = 0;
        while (line[*width] != '\n' && line[*width] != '\0') {
            maze[*height][*width] = line[*width];
            (*width)++;
        }
        (*height)++;
    }

    fclose(file);
}

// Function to print the maze to the console
void printMaze(char maze[MAX_SIZE][MAX_SIZE], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find the starting point 'S' in the maze
void findStart(char maze[MAX_SIZE][MAX_SIZE], int width, int height, int *startX, int *startY) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 'S') {
                *startX = j;
                *startY = i;
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    const char *filename = "maze.txt";

    char maze[MAX_SIZE][MAX_SIZE];
    int width, height;
    loadMaze(argv[1], maze, &width, &height);

    int startX, startY;
    findStart(maze, width, height, &startX, &startY);

    // TODO: Implement player movement logic

    printMaze(maze, width, height);

    return EXIT_SUCCESS;
}