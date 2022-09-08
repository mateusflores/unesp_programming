#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // Incluindo biblioteca de booleanos para usar uma flag

//Thiago Frota Clemente Ferreira de Assis

int main() {

    int i = 0, quantidade = 0, componente = 1, tamanho_vetor;
    bool flag_sequencia = true;

    printf("Informe quantos pares: ");      // Informando o tamanho do vetor (Primeiro, vc precisa pedir para o usuário definir o tamanho da variável que vc vai usar como tamanho do vetor)
    scanf("%d", &tamanho_vetor);            // Antes, vc estava usando a variável i como tamanho do vetor, ou seja, o i variava no laço, então o tamanho do vetor ia mudando a cada loop

    tamanho_vetor = tamanho_vetor * 2;
    int pares[tamanho_vetor];


    for(i = 0; i < tamanho_vetor; i ++){

        if(componente >= 3){

            componente = 1;

        }

        printf("Informe o %dº componente do par: ", componente);
        scanf("%d", &pares[i]);
        printf("\n");

        componente ++;

    }

    printf("Pois bem, os pares informados sao os seguintes: \n");

    for (i=0; i<tamanho_vetor; i++) {                   // Fiz esse for só pra exibir os pares
        printf("(%d, %d)\n", pares[i], pares[i+1]);
        i = i + 1;                                      // Como o laço for já faz i + 1 automaticamente, se quisermos pular duas posições de i, basta fazer i + 1 novamente no final do laço
    }

    for(i = 0; i < tamanho_vetor; i++){        // Fazendo a checagem

        if(pares[i+1] != pares[i] + 1){         // Aqui, vc precisa comparar se o elemento na primeira posição antecede o da próxima posição
            flag_sequencia = false;             // Se o elemento de pares[i+1] for diferente de pares[i]+1, então a flag assume o valor falso
        }     

        i++;

    }

    if(flag_sequencia){     // Como a flag é um booleano, se ela estiver com o valor verdadeiro, já cai na primeira posição

        printf("A relacao atende ao criterio de que todos elementos sao da forma (n, n + 1) \n");

    } else{         // Se ela estiver com o valor falso, cai na segunda

        printf("A relacao nao atende ao criterio de que todos elementos sao da forma (n, n + 1) \n");

    }

}