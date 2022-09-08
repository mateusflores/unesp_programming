// Mateus Gomes Flores          programa conjuntos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct conjunto
{
    int n;
    int elementos[1024];
};

bool eh_conjunto(int quant_elementos, int elementos[]){     // Verificando se existem elementos repetidos no array
    int i, j;
    for (i = 0; i < quant_elementos-1; i++) {
        for (j = i+1; j < quant_elementos; j++) {
            if (elementos[i] == elementos[j]) {
                return false;
            }
        }
    }
    return true;
}

bool nao_eh_repetido(int tamanho, int elemento, int conj[]){        // Verificando se o elemento jah esta contido no conjunto uniao
    int i;
    for (i=0; i < tamanho; i++) {
        if (elemento == conj[i]){
            return false;
        }
    }
    return true;
}

int main() {
    struct conjunto c1, c2;
    int i, j;

    printf("Insira o tamanho do conjunto 1: ");
    scanf("%d", &c1.n);

    printf("Digite os elementos do conjunto 1: \n");
    for (i = 0; i < c1.n; i++) {
        printf("%do elemento: ", i+1);
        scanf("%d", &c1.elementos[i]);
    }

    printf("Insira o tamanho o conjunto 2: ");
    scanf("%d", &c2.n);

    printf("Digite os elementos do conjunto 2: \n");
    for (i = 0; i < c2.n; i++) {
        printf("%do elemento: ", i+1);
        scanf("%d", &c2.elementos[i]);
    }

    if (eh_conjunto(c1.n, c1.elementos)) {                      // Verificando se os conjuntos sao validos
        printf("\n\nO primeiro conjunto eh valido!\n");
    } else {
        printf("\n\nO primeiro conjunto eh invalido!\n");
        return 0;
    }

    if (eh_conjunto(c2.n, c2.elementos)) {
        printf("\nO segundo conjunto eh valido!\n");
    } else {
        printf("\nO segundo conjunto eh invalido!\n");
        return 0;
    }

    int inter[1024], uni[1024], m = 0, k = 0;                                       // Se os conjuntos forem validos, vamos obter a intersec e uniao
    if (eh_conjunto(c1.n, c1.elementos) && eh_conjunto(c2.n, c2.elementos)) {
        
        for (i = 0; i < c1.n; i++) {            // Obtendo a intersecao
            for (j = 0; j < c2.n; j++) {
                if (c1.elementos[i] == c2.elementos[j]) {
                    inter[m] = c1.elementos[i];
                    m++;
                }
            }
        }

        for (i=0; i<c1.n; i++) {            // Obtendo a uniao dos conjuntos
            for (j=0; j<c2.n; j++) {
                if (c1.elementos[i] != c2.elementos[j]){
                    if (nao_eh_repetido(k, c1.elementos[i], uni)) {
                        uni[k] = c1.elementos[i];
                        k++;
                    }
                    if (nao_eh_repetido(k, c2.elementos[j], uni)) {
                        uni[k] = c2.elementos[j];
                        k++;
                    }
                } else {
                    if (nao_eh_repetido(k, c1.elementos[i], uni)) {
                        uni[k] = c1.elementos[i];
                        k++;
                    }
                }
            }
        }

        printf("\nIntersecao: ");
        for (i = 0; i<m; i++) {
            printf("%d ", inter[i]);
        }

        printf("\n\nUniao: ");
        for (i = 0; i<k; i++) {
            printf("%d ", uni[i]);
        }
    }
  
    printf("\n\n");
}