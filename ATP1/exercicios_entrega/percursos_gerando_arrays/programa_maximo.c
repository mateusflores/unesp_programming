#include <stdio.h>
#include <stdbool.h>

int main() {
    int array[10], i, j, maior = -1000;   
    bool bandeira = true;

    printf("Digite os valores: ");

    for (i=0; i<10; i++) {
        scanf("%d", &array[i]);
    }

    for (i=0; i<10; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }

    if (maior % 2 == 0) {
        bandeira = false;
    }
    

    if (bandeira) {
        printf("\n\nMaior: %d\n\n", maior);
    } else {
        printf("\n\nMaior: %d\n\n", maior+1);
    }
        

    
}