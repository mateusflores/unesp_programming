// Mateus Gomes Flores
#include <stdio.h>
#include <stdbool.h>

struct pares
{
    int m;
    int n;
};


int main() {
    int numero_pares, i;
    bool flag_sucessor = true;

    printf("\nInforme quantos pares ha na relacao: ");
    scanf("%d", &numero_pares);

    struct pares par[numero_pares];   // Criei um array do tamanho informado pelo usuário

    for (i = 0; i < numero_pares; i++) {        
        printf("Informe o 1o componente do par: ");
        scanf("%d", &par[i].m);
        printf("Informe o 2o componente do par: ");
        scanf("%d", &par[i].n);

        if (par[i].n != par[i].m+1) {   // Caso o par inserido não atenda o critério, a flag assume o valor 'false'
            flag_sucessor = false;
        }
    }

    if (flag_sucessor) {                // Verificando se os pares seguem o critério
        printf("\nA relacao atende ao criterio de que todos os elementos sao da forma (n, n+1)\n");
    } else {
        printf("\nA relacao nao atende ao criterio de que todos os elementos sao da forma (n, n+1)\n");
    }

}