#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eh_bissexto(int ano) {                 // Determina se o ano eh ou nao bissexto
    if (ano%4 == 0) {
        if (ano%100 == 0 && ano%400 != 0)
            return false;
        else
            return true;
    } else {
        return false;
    }
}

int main() {
    int d1, d2, m1, m2, a1, a2, num_bis = 0;
    printf("Informe o primeiro dia: ");
    scanf("%d", &d1);
    printf("Informe o primeiro mes: ");
    scanf("%d", &m1);
    printf("Informe o primeiro ano: ");
    scanf("%d", &a1);

    printf("Informe o ultimo dia: ");
    scanf("%d", &d2);
    printf("Informe o ultimo mes: ");
    scanf("%d", &m2);
    printf("Informe o ultimo ano: ");
    scanf("%d", &a2);

    
}