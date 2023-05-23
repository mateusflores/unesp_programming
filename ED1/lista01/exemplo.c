#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    struct node *ant;
    int numero;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} Fila;

Fila* iniciaFila() {
    Fila *fila = malloc(sizeof(Fila));
    fila->fim = NULL;
    fila->inicio = NULL;
}

void inserirNumero(Fila *fila, int num) {
    Node *aux = malloc(sizeof(Node));
    aux->numero = num;

    if (fila->inicio == NULL) {
        fila->inicio = aux;
        fila->fim = aux;
        aux->prox = NULL;
        aux->ant = NULL;
    } else {
        fila->fim->prox = aux;
        aux->ant = fila->fim;
        fila->fim = aux;
        aux->prox = NULL;
    }
}

void removerNumero (Fila *fila) {
    Node *aux = fila->inicio;
    fila->inicio = aux->prox;

    free(aux);
}

void exibeFila(Fila *fila) {
    Node *aux;
    for (aux = fila->inicio; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->numero);
    }
    printf("\n");
}

int main() {
    Fila *fila = iniciaFila();
    inserirNumero(fila, 4);
    inserirNumero(fila, 6);
    inserirNumero(fila, 8);
    exibeFila(fila);
    removerNumero(fila);
    exibeFila(fila);
}

