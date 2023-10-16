#include <stdio.h>

int main() {
    int answer = 10086, a;
    
    while(1)
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        
        if (a < answer){
            printf("too small\n");
        }else if(a > answer) {
            printf("too large\n");
        } else {
            printf("correct\n");
            break;
        }
    }

    return 0;
}