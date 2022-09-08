// Mateus Gomes Flores      Programa resumo
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int i, j, matriz[50][50], m, n, resumo[50][3], maior = -100, coluna;

    printf("Insira o numero de linhas e de colunas da matriz");
    printf("\nLinhas: ");
    scanf("%d", &m);
    printf("Colunas: ");
    scanf("%d", &n);

    printf("\nAgora insira os elementos da matriz: \n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%do linha, %do coluna: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Identificando os maiores valores e guardando na matriz resumo
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                coluna = j;
            }
        }

        resumo[i][0] = maior;
        if (coluna+2 < n) {
            resumo[i][1] = matriz[i][coluna+1];
            resumo[i][2] = matriz[i][coluna+2];
        } else if (coluna+1 < n) {
            resumo[i][1] = matriz[i][coluna+1];
            resumo[i][2] = 0;
        } else {
            resumo[i][1] = 0;
            resumo[i][2] = 0;
        }

        maior = -1000;
    }

    printf("\n\nMatriz digitada: \n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Seta para baixo
    printf("\n  | |\n  | |\n  \\ /\n   V \n");

    printf("\nMatriz resumo\n");
    for (i=0; i<m; i++) {
        for (j=0; j<3; j++) {
            printf("%2d ", resumo[i][j]);
        }
        printf("\n");
    }
}