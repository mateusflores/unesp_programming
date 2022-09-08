#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int array1[100], array2[100], conv[200], n, i, j=0;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &n);

    printf("\nInsira os elementos do primeiro array: ");
    for (i=0; i<n; i++) {
        scanf("%d", &array1[i]);
    }
    printf("\nInsira os elementos do segundo array: ");
    for (i=n-1; i>=0; i--) {
        scanf("%d", &array2[i]);
    }

    // Gerando o array convolucao
    for (i=0; i<(2*n)-1; i++) {
        
    }


    printf("\nArray 1:\n");
    for (i=0; i<n; i++) {
        printf ("%d ", array1[i]);
    }
    
    printf("\nArray 2 invertido: \n");
    for (i=0; i<n; i++){
        printf("%d ", array2[i]);
    }


}