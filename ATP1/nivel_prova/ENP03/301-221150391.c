// Mateus Gomes Flores      Programa raiz
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i=0, soma=0, num;

    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &num);

    while (soma <= num) {
        soma = soma + 2*i+1;
        
        if (soma != num)
            i++;
    }

    printf("\nA raiz quadrada inteira (aproximada para cima) de %d eh %d\n\n", num, i);
}