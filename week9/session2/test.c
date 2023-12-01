#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("An int is size: %ld\n", sizeof(int));

    printf("An double is size: %ld\n", sizeof(double));

    printf("An char is size: %ld\n", sizeof(char));

    char* name = "asdfghjkkkkkkjhgfdsa";
    printf("The word %s is size %ld\n", name, sizeof(name));
}