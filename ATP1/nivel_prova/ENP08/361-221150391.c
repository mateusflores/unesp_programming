// Mateus Gomes Flores      Programa esmagamento
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int matriz[50][50], esmag[25][25], n, i, j, auxi = 0, auxj = 0, determinante;
    bool flag_par = false;

    while (flag_par == false) {
        printf("\nInsira a dimensao da matriz quadrada: ");
        scanf("%d", &n);

        if (n%2 == 0)
            flag_par = true;
        else 
            printf("\nA matriz quadrada deve um numero de linhas e colunas par.\nTente novamente.\n\n");
    }

    printf("Insira os elementos: ");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%do linha e %do coluna: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Gerando a matriz esmagada
    for (i=0; i<n;) {
        for (j=0; j<n;) {
            determinante = (matriz[i][j]*matriz[i+1][j+1]) - (matriz[i][j+1]*matriz[i+1][j]);
            esmag[auxi][auxj] = determinante;

            j += 2;

            if (j > n-1 ) {
                j = 0;
                i += 2;
                auxj = 0;
                auxi += 1;
            } else {
                auxj += 1;
            }
            
            // Terminando o loop
            if (i > n-1)
                break;
        }
    }

    // Printando a matriz original e a matriz esmagada
    printf("\nMatriz original: \n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz esmagada: \n");
    for (i=0; i<n/2; i++) {
        for (j=0; j<n/2; j++) {
            printf("%2d ", esmag[i][j]);
        }
        printf("\n");
    }
}