// Mateus Gomes Flores      Programa SAT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eh_satisfazivel(bool valor) {      // Testa se o valor eh verdadeiro
    if (valor) {
        return true;
    } else {
        return false;
    }
}

int main() {
    bool matriz_valores[1024][1024], flag = false;
    int i, j, aux=0, i_aux=0;

    for (i=0; i<8; i++) {
        for (j=0; j<4; j++) {
            if (i<4 && j==0) {                      // Atribuindo valor de A 
                matriz_valores[i][0] = true;
            } else if (i>=4 && j==0) {
                matriz_valores[i][0] = false;
            }

            if (aux==0 && j==1 && i_aux<8) {        // Atribuindo valor de B
                matriz_valores[i_aux][1] = true;
                matriz_valores[i_aux+1][1] = true;
                aux = 1;
                i_aux = i_aux + 2;

            } else if (aux==1 && j==1 && i_aux<8) {
                matriz_valores[i_aux][1] = false;
                matriz_valores[i_aux+1][1] = false;
                aux = 0;
                i_aux = i_aux + 2;
            }

            if ((i%2 == 0) && j==2) {               // Atribuindo valor de C
                matriz_valores[i][2] = true;
            } else if ((i%2 != 0) && j==2) {
                matriz_valores[i][2] = false;
            }
        }
    }

    for (i=0; i<8; i++) {
        matriz_valores[i][3] = matriz_valores[i][0] && (matriz_valores[i][1] && matriz_valores[i][2]);    // Insira a expressao aqui (OBS: coluna 0 = A ; coluna 1 = B ; coluna 2 = C)
    }
    
    for (i=0; i<8; i++){                                    
        flag = eh_satisfazivel(matriz_valores[i][3]);   // Testando se existe ao menos uma combinacao verdadeira
        if (flag) {
            break;
        }
    }

    if (flag) {
        printf("\nA formula embutida eh satisfazivel!\n\n");
    } else {
        printf("\nA formula embutida nao eh satisfazivel!\n\n");
    }
}