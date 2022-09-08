#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ESP_C_0 1
#define ESP_I 2
#define ESP_A 3
#define STOP 0

int main() {
    char frase[] = "A CIA denuncia que a Mafia abastecia o trafico de armas na Bacia do Rio do Prata";
    int cont = 0, i = 0, estado = ESP_C_0;

    while (frase[i] != STOP) {
        switch (estado) {
            case ESP_C_0:  
                if (frase[i] == 67 || frase[i] == 99)
                    estado = ESP_I;
                else if (frase[i] == STOP) 
                    estado = STOP;
            break;

            case ESP_I:
                if (frase[i] == 73 || frase[i] == 105)
                    estado = ESP_A;
                else 
                    estado = ESP_C_0;
            break;

            case ESP_A:
                if (frase[i] == 65 || frase[i] == 97) {
                    estado = ESP_C_0;
                    cont++;
                } else 
                    estado = ESP_C_0;
            break;
        } 
        i++;  
    }

    printf("\n%d\n\n", cont);

}