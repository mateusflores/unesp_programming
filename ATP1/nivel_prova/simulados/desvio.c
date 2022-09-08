#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int i, num, soma = 0;
    float media, soma_d =0, dvp;

    printf("Digite quantos numeros serao digitados: ");
    scanf("%d", &num);
    int quant[num-1];

    for (i=0; i<num; i++) {
        printf("\nDigite o %do numero: ", i+1);
        scanf("%d", &quant[i]);
        soma = soma + quant[i];
    }

    media = soma/num;

    for (i=0; i<num; i++) {
        soma_d = soma_d + pow((quant[i]-media), 2);
    }

    dvp = sqrt((soma_d/(num-1)));

    printf("\nMedia = %f", media);
    printf("\nD.P = %f\n\n", dvp);
}