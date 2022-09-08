// Mateus Gomes Flores      Programa Binario
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num, n, i=0, array_bin[1024];

    printf("Informe um numero inteiro positivo a ser convertido em binario: ");
    scanf("%d", &num);
    n = num;

    while (n>0) {
        array_bin[i] = n % 2;
        n = n/2;
        if (n>0)
            i++;
    }

    printf("\n%d em binario eh representado assim: ", num);

    while (i >= 0) {
        printf("%d", array_bin[i]);
        i--;
    }

    printf("\n");
}