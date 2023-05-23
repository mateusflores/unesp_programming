#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int numero;
    struct node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} List;

List* iniciaLista() {
    List *lista = malloc(sizeof(List));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

void inserirNumero(List *lista, int numero) {
    Node *aux = malloc(sizeof(Node));
    aux->numero = numero;
    if (lista->inicio == NULL) {
        lista->inicio = aux;
        lista->fim = aux;
        aux->prox = NULL;
    } else {
        lista->fim->prox = aux;
        lista->fim = aux;
        aux->prox = NULL;
    }
}

void geraLista(List *lista) {
    for (int i=1; i<10; i++)
        inserirNumero(lista, i);
}

void exibeLista(List *lista) {
    for (Node *aux = lista->inicio; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->numero);
    }
    printf("\n");
}

bool checkCrescente(Node *atual, Node *prox) {
    if (atual->numero < atual->prox->numero)
        return true;
    else 
        return false;
}

bool checaNaoDecrescente(List *lista) {
    Node *aux = lista->inicio;
    if (lista->fim != NULL)
        return checkCrescente(aux, aux->prox);
}

int main() {
    List *lista = iniciaLista(lista);
    geraLista(lista);
    exibeLista(lista);

}