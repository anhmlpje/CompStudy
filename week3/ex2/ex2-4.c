#include <stdio.h>

int f(int a){
    for(int i = 2; i < a; i++){
        if(a%i){
            printf("no\n");
            return 1;
            break;
        }
        printf("yes\n");
        return 0;   
    }
}


int main() {
    int b;
    printf("Enter a number: ");
    scanf("%d", &b);
    printf("%d", f(b));
    return 0;
}
