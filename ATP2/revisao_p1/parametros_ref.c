#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void troca (int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int n = 2;
    int m = 5;

    printf("*--------------*\nAntes da troca:\nn = %d     m = %d\n", n, m);
    troca(&n, &m);
    printf(" -------------\nDepois da troca: \nn = %d     m = %d\n", n, m);
    printf("*--------------*\n");
}