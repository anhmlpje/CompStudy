#include "cw1.h"

void move(){
    //move when they can do
}

void txt_to_array(){
    //todo
    //If the maze in the txt file are valid, store them in a 2d array
    //find start x y
}

void map(){
    //puts arraymaze when user enter m
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage: %s <maze_file_name>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    if(test(filename) == 1){
        return 1;
    }else{
        printf("Valid maze\n");
        txt_to_array();
    }

    printf("The movement is controlled using 'w' 'a' 's' 'd'.\n"
           "Enter 'm' to open the map and display the current location\n");
    while (1){
        userinput = getch();
        switch (userinput)
        {
            case 'W': case 'w':
            case 'S': case 's':
            case 'A': case 'a':
            case 'D': case 'd':
                int move_test_result = move_test();
                if(move_test_result == 1){
                    break;
                }if(move_test_result ==2){
                    return 0;
                }else{
                    move();
                }
            break;
            
            case 'M':
            case 'm':
                map();
            break;


            case 'q':
                //for test
            return 0;

            default:
                printf("Invalid input\n");
                printf("The movement is controlled using 'w' 'a' 's' 'd'.\n"
                       "Enter 'm' to open the map and display the current location\n");
            break;
        }
    }
    return 0;
}