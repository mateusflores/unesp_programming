// Mateus Gomes Flores
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool flag_ascendente = true;
    int i, tamanho_seq;

    printf("\nInforme o tamanho da sequencia: ");
    scanf("%d", &tamanho_seq);

    int seq[tamanho_seq];       // Criamos um array com o tamanho desejado pelo usuário

    for (i = 0; i < tamanho_seq; i++) {     // Guardando os valores da sequência
        printf("Informe o %do elemento: ", i+1);
        scanf("%d", &seq[i]);
    }
    
    for (i = 1; i < tamanho_seq; i++) {     // Verificando se os valores são ascendentes com o auxílio de uma flag
        if (seq[i] <= seq[i-1]) {
            flag_ascendente = false;
        }
    }

    if (flag_ascendente) {
        printf("\nA sequencia eh ascendente.\n");
    } else {
        printf("\nA sequencia nao eh ascendente.\n");
    }

}