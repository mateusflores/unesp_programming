#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eh_algarismo(char ch) {
    if (ch>=48 && ch<=57)
        return true;
    else
        return false;
}

int main() {
    char carac = 'T';

    if (eh_algarismo(carac)) 
        printf("\nS\n\n");
    else 
        printf("\nN\n\n");
}