#include <stdio.h>
#include <stdlib.h>

typedef struct elementoPilha {
    char frase[50];
    struct elementoPilha *prox;
} ElementoPilha;

typedef struct {
    ElementoPilha *topo;
} Pilha;

int main() {

}