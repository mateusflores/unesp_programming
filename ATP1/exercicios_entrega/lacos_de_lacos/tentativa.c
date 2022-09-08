#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int range_aleatorio(int max) {      // Gera um numero aleatorio dentro do range definido (ou seja, o tamanho do campo)
    int i, num;
    num = (rand()%(max-2))+1;
    return num;
}

struct posicao_bomba {
    int lin;
    int col;
};

int main(int argc, char* argv[]) {
    int tam = atoi(argv[1]);
    int num_bombas = atoi(argv[2]);

    bool flag = true, flag_cercado=false;
    int campo[1024][1024];
    int i, j, cont = 0;
    srand(time(NULL));

    struct posicao_bomba bombas[num_bombas];
    do {
        for (i=0; i<tam; i++) {                 // Definindo todas as posicoes como '0'
            for (j=0; j<tam; j++) {
                campo[i][j] = 0;
            }
        }

        while (cont < num_bombas) {
            bombas[cont].lin = range_aleatorio(tam);    // Definindo as posicoes das bombas
            bombas[cont].col = range_aleatorio(tam);

            if (cont >= 1) {        // Verificando para garantir que todas as bombas aparecam em lugares diferentes
                for (i=0; i<cont; i++) {
                    if ((bombas[cont].lin == bombas[i].lin) && (bombas[cont].col == bombas[i].col)) {
                        flag = false;
                        break;
                    } else {
                        flag = true;
                    }
                }
            }

            if (flag) {
                cont++;
            }
        }

        for (i=0; i<cont; i++) {                  // Colocando as bombas nas posicoes
            for (j=0; j<cont; j++) {
                campo[bombas[i].lin][bombas[i].col] = -1; 
            }
        }

        for (i=0; i<tam; i++) {                 // Contando quantas bombas existem nas redondezas de cada celula
            for (j=0; j<tam; j++) {
                if (campo[i][j] != -1) {
                    if (campo[i-1][j-1] == -1)
                        campo[i][j]++;
                    if (campo[i][j-1] == -1)
                        campo[i][j]++;
                    if (campo[i+1][j-1] == -1)
                        campo[i][j]++;
                    if (campo[i-1][j] == -1)
                        campo[i][j]++;
                    if (campo[i+1][j] == -1)
                        campo[i][j]++;
                    if (campo[i-1][j+1] == -1)
                        campo[i][j]++;
                    if (campo[i][j+1] == -1)
                        campo[i][j]++;
                    if (campo[i+1][j+1] == -1)
                        campo[i][j]++;
                }
            }
        }

        for (i=0; i<tam; i++) {
            for (j=0; j<tam; j++) {
                if (campo[i][j] == 8) {
                    flag_cercado = true;
                    cont = 0;
                    break;
                }
            }
        }
    }while (flag_cercado);

    for (i=0; i<tam; i++) {             // Printando o campo minado na tela
        for (j=0; j<tam; j++) {
            if (campo[i][j] < 0) {
                printf("B ");
            } else if (campo[i][j] == 0) {
                printf(". "); 
            } else {
                printf("%d ", campo[i][j]);
            }            
        }
        printf("\n");
    }

    printf("\n%d bombas\n", cont);
    
}

// Falta satisfazer a condicao de que um número não pode ser cercado por 8 bombas