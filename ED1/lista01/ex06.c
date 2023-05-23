#include <stdio.h>
#include <stdlib.h>

typedef struct intGrande {
    struct intGrande *prox;
    int unidade;
    int potencia;
} IntGrande;


// Representação de matriz esparsa (elemento)
typedef struct elementoMatrizEsparsa {
    int linha;
    int coluna;
    int valor;
    struct elementoMatrizEsparsa *prox;
} ElementoMatrizEsparsa;

// Lista da matriz esparsa, que contém apenas os elementos diferentes de 0 e o tamanho da matriz
typedef struct {
    ElementoMatrizEsparsa *primeiro;
    int numLinhas;
    int numColunas;
} MatrizEsparsa;

typedef struct pilha {

} Pilha;

int main() {

}