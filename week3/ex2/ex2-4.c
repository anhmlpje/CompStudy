#include <stdio.h>

int f(int a){
    for(int i = 2; i < a; i++){
        if(a%i){
            printf("no\n");
            break;
        }
        printf("yes\n");   
    }
}


int main() {
    int b;
    printf("Enter a number: ");
    scanf("%d", &b);
    f(b);
    return 0;
}
