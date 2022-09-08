#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct par {
    int x, y;
};

int main() {
    int i, j, num, guardaj;
    
    printf("Insira a quantidade de pares a ser inserida: ");
    scanf("%d", &num);
    struct par pares[num-1];

    for (i=0; i<num; i++) {
        printf("\nDigite o %do par: ", i+1);
        scanf("%d", &pares[i].x);
        scanf("%d", &pares[i].y);
    }

    bool flag = false;

    for (i=0; i<num; i++) {
        for (j=i+1; j<num; j++) {
            if (pares[i].x == pares[j].x)
                guardaj = j;
        }
    }

    if (flag)
        printf("\nA relacao eh transitiva\n\n");
    else
        printf("\nA relacao nao eh transitiva\n\n");

}