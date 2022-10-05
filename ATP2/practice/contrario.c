#include <stdio.h>

int main() {
    char s[100] = "O rato roeu a roupa do rei de roma.";
    char *ptr = &s[0];

    while (*ptr != '\0') {
        putchar(*ptr);
        ptr++;
    }

    printf("\nAgora ao contrário:\n");

    ptr--;  // Pois o ultimo eh o \0 e não queremos comecar com ele
    while (ptr >= s) {
        putchar(*ptr);
        ptr--;
    }
    printf("\n");
}