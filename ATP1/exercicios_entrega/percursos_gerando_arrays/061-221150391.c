// Mateus Gomes Flores      Programa maximos locais
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int entrada[1024], saida[1024], i, tam, aux=0;
    bool flag = true;

    while (flag) {
        printf("Insira o tamanho do vetor a ser digitado (maximo de 1024 valores): ");
        scanf("%d", &tam);

        if (tam>1024) {
            printf("Tamanho invalido, tente novamente.\n");
        } else {
            flag = false;
        }
    }

    // Entrada de dados
    for (i=0; i<tam; i++) {
        printf("Insira o %do valor: ", i+1);
        scanf("%d", &entrada[i]);
    }

    // Criando o array de saida com os maximos locais
    for (i=0; i<tam; i++) {
        if (entrada[i]>entrada[i+1] && i==0) {
            saida[aux] = entrada[0];
            aux++;
        } else if (entrada[i]>entrada[i+1] && entrada[i]>entrada[i-1]) {
            saida[aux] = entrada[i];
            aux++;
        } else if (entrada[i] > entrada[i-1] && i==tam-1) {
            saida[aux] = entrada[i];
            aux++;
        }
    }

    // Exibindo os dois arrays
    printf("\nVetor de entrada: \n[");
    for (i=0; i<tam; i++) {
        if (i < tam-1)
            printf("%d, ", entrada[i]);
        else
            printf("%d]", entrada[i]);
    }

    printf("\nVetor de saida: \n[");
    for (i=0; i<aux; i++) {
        if (i < aux-1)
            printf("%d, ", saida[i]);
        else
            printf("%d]\n\n", saida[i]);
    }
}