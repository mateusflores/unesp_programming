// Mateus Gomes Flores      Multiplicacao de matrizes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // m = linhas  e  n = colunas
    int i, j, m1, m2, n1, n2, matriz1[50][50], matriz2[50][50], mult[50][50];
    bool flag = true;

    // Entrada das dimensoes das duas matrizes e checagem se as matrizes podem ser multiplicadas uma pela outra
    while(flag) {
        printf("Informe as dimensoes da primeira matriz: (linhas e colunas)\n");
        printf("Linhas: ");
        scanf("%d", &m1);
        printf("Colunas: ");
        scanf("%d", &n1);
        printf("\nInforme as dimensoes da segunda matriz: (linhas e colunas)\n");
        printf("Linhas: ");
        scanf("%d", &m2);
        printf("Colunas: ");
        scanf("%d", &n2);

        if (n1 != m2)
            printf("\nErro. O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda matriz!\nTente novamente.\n\n");
        else
            flag = false;
    }

    // Inserindo os elementos das matrizes
    printf("\nInsira os elementos da primeira matriz: \n");
    for (i=0; i<m1; i++) {
        for (j=0; j<n1; j++) {
            printf("%do lin, %do col: ", i+1, j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("\nInsira os elementos da segunda matriz: \n");
    for (i=0; i<m2; i++) {
        for (j=0; j<n2; j++) {
            printf("%do lin, %do col: ", i+1, j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Realizando a multiplicacao das matrizes
    int m3 = 0, n3 = 0, soma_elemento = 0, aux1 = 0, aux2 = 0;
    bool flag_fim = false;

    while (flag_fim == false) {
        for (i=0; i<m2; i++) {
            soma_elemento = soma_elemento + matriz1[aux1][i] * matriz2[i][aux2];
        }

        // Gerenciando as variaveis que percorrem as matrizes durante a multiplicacao
        if (aux2 < n2)
            aux2++;
        else if (aux2 == n2) {
            aux2 = 0;
            aux1 ++;
        }

        // Gerenciando a posicao em que o elemento sera depositado na matriz mult
        if (n3 < n2) {
            mult[m3][n3] = soma_elemento;
            n3++;
        } else if (n3 == n2) {
            n3 = 0;
            m3++;
            mult[m3][n3] = soma_elemento;
        }

        if (m3 == m1 && n3 == n2) {
            flag_fim = true;
        }

        soma_elemento = 0;
    }


    // Exibindo as duas matrizes inseridas e a matriz resultante da multiplicacao entre elas
    printf("\n\nMatriz 1: \n");
    for (i=0; i<m1; i++) {
        for (j=0; j<n1; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\n\nMatriz 2: \n");
    for (i=0; i<m2; i++) {
        for (j=0; j<n2; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\n\nResultado da multiplicacao: \n");
    for (i=0; i<m3; i++) {
        for (j=0; j<n3; j++) {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}