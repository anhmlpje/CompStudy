#include <stdio.h>

int main() {
    int m;

    printf("Option menu:1,2,3,4,5\n");
    printf("Select one option: ");
    scanf("%d", &m);

       switch (m)
    {
    
        case 1:     printf ("Option 1 has been selected\n");
        break;

        case 2:     printf ("Option 2 has been selected\n");
        break;

        case 3:     printf ("Option 3 has been selected\n");
        break;

        case 4:     printf ("Option 4 has been selected\n");
        break;

        case 5:     printf ("Option 5 has been selected\n");

        default:    printf ("invalid choices\n");
    }
    return 0;
}