#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eh_maiuscula(char ch) {
    if (ch>=65 && ch<=90)
        return true;
    else
        return false;
}

bool eh_minuscula(char ch) {
    if (ch>=97 && ch<=122)
        return true;
    else
        return false;
}

bool eh_letra(char ch) {
    if (ch>=65 && ch<=122)
        return true;
    else
        return false;
}

int main() {
    char carac = 'A';

    if (eh_minuscula(carac)) 
        printf("\nS\n\n");
    else 
        printf("\nN\n\n");
}