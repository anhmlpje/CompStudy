#include <stdio.h>

int main() {
    int answer = 10, a;
    printf("Enter a number: ");
    scanf("%d", &a);
    while(a != answer)
    {
        if (a < answer){
            printf("too small\n");
        }else {
            printf("too large\n");
        }
        printf("Enter a number: ");
        scanf("%d", &a);
    }
    printf("good\n");

    return 0;
}