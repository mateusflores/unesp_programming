#include <stdio.h>
#include <stdbool.h>

int main() {
    int soma=0, dendo, sor, q=0, resto;  // diviDENDO e diviSOR
    bool flag;

    do {
        printf("Digite dois numeros inteiros e positivos: ");
        scanf("%d %d", &dendo, &sor);

        if (dendo == 0 || sor == 0) {
            printf("Dados de entrada invalidos!\n");
            flag = true;
        } else {
            flag = false;
        }
    } while (flag);

    resto = dendo;
    while (resto >= sor) {
        resto = resto - sor;
        q++;
    }

    printf("Q = %d  R = %d\n\n", q, resto);
}