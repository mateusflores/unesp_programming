#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node {
    int numero;
    struct node *prox;
} Node;

typedef struct {
    Node *first;
    Node *last;    
} List;

void iniciaLista(List *list) {
    list->first = NULL;
    list->last = NULL;
}

void inserirNumero(List *list, int numero) {
    Node *aux = malloc(sizeof(Node));

    if (list->first == NULL) {
        list->first = aux;
        list->last = aux;
        aux->numero = numero;
        aux->prox = NULL;
    } else {
        list->last->prox = aux;
        list->last = aux;
        aux->prox = NULL;
        aux->numero = numero;
    }
}

int gerarNumero(int numMax) {
    return rand() % numMax;
}

void gerarListaPares(List *listOriginal, List *listaPares) {
    for (Node *aux = listOriginal->first; aux != NULL; aux = aux->prox) {
        if (aux->numero % 2 == 0)
            inserirNumero(listaPares, aux->numero);
    }
}

void exibirLista(List *list) {
    for (Node *aux = list->first; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->numero);
    }    
    printf("\n");
}


int main() {
    srand(time(NULL));

    List *listaOriginal = malloc(sizeof(List));
    List *listaPar = malloc(sizeof(List));

    iniciaLista(listaOriginal);
    iniciaLista(listaPar);

    for (int i=0; i<10; i++) {
        inserirNumero(listaOriginal, gerarNumero(100));
    }

    gerarListaPares(listaOriginal, listaPar);

    puts("Lista original: ");
    exibirLista(listaOriginal);
    puts("Lista apenas com pares: ");
    exibirLista(listaPar);
}