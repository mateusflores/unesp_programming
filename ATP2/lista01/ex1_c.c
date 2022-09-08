#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eh_letra(char ch) {
    if (ch>=65 && ch<=122)
        return true;
    else
        return false;
}

bool eh_maiuscula(char ch) {
    if (ch>=65 && ch<=90)
        return true;
    else
        return false;
}

char minuscula(char ch) {
    return ch + 32;
}

int main() {
    char carac = 'A';

    if (eh_letra(carac)) 
        if (eh_maiuscula(carac))
            printf("%c\n", minuscula(carac));
        else
            printf("%c\n", carac);
    else 
        printf("\nNao eh letra!\n\n");
}