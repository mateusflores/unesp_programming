// Mateus Gomes Flores
#include <stdio.h>

int main() {
    int tempo, resto;

    printf("\nInforme o valor do cronometro: ");
    scanf("%d", &tempo);

    if (tempo <= 45) {
        resto = 45 - tempo;
        printf("\nFaltam %d minutos para encerrar o 1o tempo.\n\n", resto);
    } else if (tempo > 45) {
        resto = 90 - tempo;
        printf("\nO jogo estah em %d minutos do 2o tempo e faltam %d minutos para se encerrar o jogo.\n\n", tempo-45, resto);
    }
}