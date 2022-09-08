#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ESP_ALG_0 1
#define ESP_PONTO_HIFEN 2
#define CHECK_TAMANHO 3
#define STOP 0

int tamanho_string(char frase[]) {
    int i = 0;
    while (frase[i] != 0) {
        i++;
    }
    return i;
}

int main() {
    char tel[] = "123.4567";
    int n = tamanho_string(tel), tam = n-1;
    int algarismos = 0, estado = ESP_ALG_0;

    while (estado != 0) {
        switch (estado) {
            case ESP_ALG_0:
                if (tel[tam]>=48 && tel[tam]<=57 && tel[tam]!=0) {
                    tam--;
                    algarismos++;
                    estado = ESP_ALG_0;
                } else if (tam == -1) {
                    estado = CHECK_TAMANHO;
                } else {
                    estado = ESP_PONTO_HIFEN;
                }
            break;

            case ESP_PONTO_HIFEN:
                if ((tel[tam]==46 || tel[tam]==45) && tam == n-5) {
                    tam--;
                    estado = ESP_ALG_0;
                } else {
                    estado = STOP;
                    printf("\nNumero de telefone invalido\n\n");
                }
            break;

            case CHECK_TAMANHO:
                if (algarismos==8 || algarismos==9) {
                    printf("\nNumero de telefone valido\n\n");
                    estado = STOP;
                } else {
                    printf("\nNumero de telefone invalido\n\n");
                    estado = STOP;
                }
            break;
        }
    }
}