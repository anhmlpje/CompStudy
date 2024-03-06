#include <stdio.h>

int number_checker(int num){
    if (num > 1000 || num < 0)
    {
        printf("Bad value\n");
        return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter: ");
    scanf("%d", &n);
    printf("%d\n",number_checker(n));
    return 0;
}