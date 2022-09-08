// Mateus Gomes Flores      Programa mais percursos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int i, j, tam, soma = 0, ult_col = 0, aux = 0;
    bool flag = true, flag_positivos = true;  
    int matriz[16][16];
    int media = 0;

    while (flag) {
        printf("Insira o tamanho desejado para a matriz quadrada: ");
        scanf("%d", &tam);

        if (tam<3 || tam>16)
            printf("\nO tamanho da matriz deve estar entre 3 e 16, tente novamente\n\n");
        else
            flag = false;
    }

    printf("\nInsira os elementos da matriz: ");
    for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++) {
            printf("\n%do linha e %do coluna: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz inserida: \n");
    for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++) {
            printf("%2d ", matriz[i][j]);

            if (j>i && j%2 != 0 && matriz[i][j]<0)  // Verificando se existe algum numero negativo nas colunas impares acima da diag principal
                flag_positivos = false;             // Se tiver um negativo, ativa a flag e nao calculamos a media truncada
        }
        printf("\n");
    }

    if (flag_positivos) {
        for (i=0; i<tam; i++) {
            for (j=0; j<tam; j++) {
                if (tam-1-i == j && matriz[i][j]%2 == 0) {     // Verificando os elementos da diag secundaria que sao pares
                    soma = soma + matriz[i][j];
                    aux++;   
                }
            }
        }
        media = (soma-(soma%aux))/aux;      // Obtendo a media truncada
        printf("\nA media truncada dos elementos pares da diagonal secundaria eh: %d \n\n", media);
    } else {
        for (i=0; i<tam; i++) {
            for (j=0; j<tam; j++) {
                if (j == tam-1) 
                    ult_col = ult_col + matriz[i][j];   // Soma dos elementos da ultima coluna
            }
        }
        printf("\nA soma da ultima coluna eh: %d\n\n", ult_col);
    }
}