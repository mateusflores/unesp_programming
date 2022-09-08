#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define START 0
#define STOP 0

int main() {
    char frase[] = "Ola, USUARIO, atualize a senha e o nome do seu usuario";
    char nome[] = "Patricia";
    int i = START, aux = START;

    while (i < 100) {
        if (i<5) {
            printf("%c", frase[i]);
        } else if (i==5) {
            while (aux < 8) {
                printf("%c", nome[aux]);
                aux++;
            }
            i += aux;
        } else {
            printf("%c", frase[i]);
        }

        i++;
    }

    
}