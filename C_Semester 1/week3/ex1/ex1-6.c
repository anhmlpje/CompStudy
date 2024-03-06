#include <stdio.h>

int main() {
    int n;

    printf("Termination value is -1\n");

    while(1)
    {
        printf("Enter a number: ");
        scanf("%d", &n);

        if(n <= 100 && n >= 0)
        {
            printf("Vaild input\n");
        }else if(n == -1)
        {
            break;
        }else
        {
            printf("Invaild input\n");
        }
    }
    return 0;
}