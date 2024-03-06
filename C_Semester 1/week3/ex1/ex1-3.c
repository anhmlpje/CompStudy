#include <stdio.h>

int main() {
    int a;

    while(a)
    {
        printf("Enter the mark: ");
        scanf("%d", &a);
        if (a < 0 || a > 100)
        {
            printf("Invalid mark\n");
        }
        else
        {
            break;
        }
    }

    if (a >= 50 && a < 70)
    {
        printf("The mark of %d is a pass\n", a);
    }
    else if (a >= 70)
    {
        printf("The mark of %d is a distinction\n", a);
    }
    else
    {
        printf("The mark of %d is a failed\n", a);
    }
    return 0;
}