#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("arqTeste.bin", "wb");
    if (fp == NULL) {
        puts("Erro ao abrir o arquivo");
        exit(4);
    }

    char frase[20];
    fgets(frase, sizeof(frase), stdin);
    fwrite(&frase, sizeof(frase), 1, fp);
    fclose(fp);
}