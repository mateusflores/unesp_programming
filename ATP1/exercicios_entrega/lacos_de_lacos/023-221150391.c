// Mateus Gomes Flores      Programa CPF
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numeros[1024], i;

    for (i=0; i<11; i++){               // Obtendo os digitos do CPF separadamente
        scanf("%d", &numeros[i]);
    }


    int soma = 0, mult = 10, resto, digito1, digito2;    // Passo 1 do algoritmo (multiplicando os 9 primeiros digitos e somando)
    for (i=0; i<9; i++) {
        soma = soma + numeros[i]*mult;
        mult = mult - 1;
    }

    resto = soma % 11;      // Passo 2 (obtendo o primeiro digito de verificacao)
    if (resto < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - resto;
    }

    numeros[9] = digito1; // Adicionando o primeiro digito de verificacao no array 
    mult = 11, soma = 0;

    for (i=0; i<10; i++) {              // Passo 3 do algoritmo (multiplicando os 10 primeiros digitos e somando)
        soma = soma + numeros[i]*mult;
        mult = mult - 1;
    }

    resto = soma % 11;      // Passo 4 (obtendo o DV2)
    if (resto < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - resto;
    }

    if (numeros[9]==digito1 && numeros[10]==digito2) {      // Verificando se o CPF eh valido
        printf("\ns\n\n");
    } else {
        printf("\nn\n\n");
    }

}