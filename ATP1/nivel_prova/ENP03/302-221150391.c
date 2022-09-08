// Mateus Gomes Flores      Programa MDC
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int dendo, sor, resto, q;
    bool flag = false;

    do {
        printf("Informe dois numeros inteiros e positivos: ");
        scanf("%d %d", &dendo, &sor);

        if (dendo==0 || sor==0) {
            printf("Informe valores validos\n");
            flag = true;
        } else {
            flag = false;
        }
    } while (flag);

    int a = dendo, b = sor;
    while (a%b != 0) {
        resto = a%b;
        a = b;
        b = resto;
    }

    printf("O M.D.C de %d e %d eh %d\n\n", dendo, sor, b);

}