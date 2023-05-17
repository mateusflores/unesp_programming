#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int numero;
    struct node *prox;
} Node;

typedef struct {
    Node *first;
    Node *last;
} Lista;

// Inicia a lista com um node apontando para NULL
void iniciaLista(Lista *lista) {
    lista->first = NULL;
    lista->last = NULL;
}

void insereElemento (Lista *lista, int numero) {
    Node *node = malloc(sizeof(Node));
    node->numero = numero;
    node->prox = NULL;

    lista->last->prox = node;
    lista->last = node;
}

// Gera uma lista de números até n
void geraLista (Lista* lista, int n) {
    for (int i=0; i<n; i++) {
        insereElemento(lista, i+1);
    }
}

void printaLista (Lista* lista) {
    Node *aux = lista->first;
    for (aux; aux = aux->prox; aux->prox == NULL) {
        printf("\n %d", &aux->numero);
    }
}
 
int main() {
    Lista *lista;
    iniciaLista(lista);
    geraLista(lista, 30);
    //printaLista(lista);
}