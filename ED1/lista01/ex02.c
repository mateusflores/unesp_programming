#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *ant;
    struct node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} List;

List* iniciarLista(List *list) {
    if (list != NULL) {
        list = NULL;
        list->inicio = NULL;
        list->fim = NULL;
    }
    return list;
}

void inserirNumero(List *list, int numero) {
    Node *aux = malloc(sizeof(Node));
    aux->number = numero;

    if (list->inicio == NULL) {
        list->inicio = aux;
        list->fim = aux;
        aux->ant = NULL;
        aux->prox = NULL;
    } else {
        aux->ant = list->fim;
        list->fim->prox = aux;
        list->fim = aux;
        aux->prox = NULL;
    }
}

void inserirNumeroOrdenado (List *list, int numero) {
    Node *aux;
    Node *meio = malloc(sizeof(Node));
    meio->number = numero;
    for (aux = list->inicio; aux != NULL; aux = aux->prox) {
        if ((aux->number < numero) && (aux->prox != NULL) && (aux->prox->number > numero)) {
            meio->prox = aux->prox;
            aux->prox->ant = meio;
            meio->ant = aux;
            aux->prox = meio;
        } else if (aux->prox == NULL && aux->number < meio->number) {
            aux->prox = meio;
            meio->prox = NULL;
            meio->ant = aux;
            list->fim = meio;
        } else if (aux->ant == NULL && aux->number > numero) {
            aux->ant = meio;
            meio->ant = NULL;
            meio->prox = aux;
            list->inicio = meio;
        }
    }
}

void gerarNumerosLista(List *list) {
    for (int i=0; i<=24; i++) {
        if (i%3 == 0) {
            inserirNumero(list, i);
        }
    }
}

void exibirList(List *list) {
    Node *aux;
    for (aux = list->inicio; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->number);
    }
    printf("\n");
}

int main() {
    List *list = malloc(sizeof(List));
    gerarNumerosLista(list);
    exibirList(list);
    inserirNumeroOrdenado(list, -2);
    printf("\nNova lista:\n");
    exibirList(list);
}