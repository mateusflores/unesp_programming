#include <stdio.h>
#include <stdbool.h>

int main() {
    int array[5] = {32, 23, 100, 2, 7};
    bool trocou = true;
    int i, j, aux, m;

    for (i=0; trocou; i++) {
        trocou = true;
        for (j=0; j<4; j++) {
            if (array[j] > array[j+1]) {
                trocou = false;
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }

    }

    puts(" ");
    puts("Depois da ordenacao: ");
    for (m=0; m<5; m++) {
        printf("%d ", array[m]);
    }

    puts(" ");
}