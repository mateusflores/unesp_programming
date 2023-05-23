#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *ant;
    struct node *prox;
    int numero;
} Node;

typedef struct {
    Node *topo;
} Pilha;

Pilha* iniciaPilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
}

void insereNumero (Pilha *pilha, int numero) {
    Node *aux = malloc(sizeof(Node));
    aux->numero = numero;
    if (pilha->topo == NULL) {
        pilha->topo = aux;
        aux->ant = NULL;
        aux->prox = NULL;
    } else {
        pilha->topo->ant = aux;
        aux->prox = pilha->topo;
        pilha->topo = aux;
        aux->ant = NULL;
    }
}

void enchePilha(Pilha *pilha) {
    for (int i=0; i<10; i++) {
        insereNumero(pilha, i);
    }
}

int removeTopo(Pilha *pilha) {
    int elemento = pilha->topo->numero;

    Node *aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return elemento;
}

void criaFila(Pilha *origem, Pilha *dest) {
    while (origem->topo != NULL) {
        insereNumero(dest, removeTopo(origem));
    }
}

void exibePilha(Pilha *pilha) {
    Node *aux = malloc(sizeof(Node));
    for (aux = pilha->topo; aux!=NULL; aux=aux->prox) {
        printf("%d ", aux->numero);
    }
    printf("\n");
}

int main() { 
    Pilha *pilha = iniciaPilha();
    Pilha *fila = iniciaPilha();

    enchePilha(pilha);
    printf("\nOriginal: ");
    exibePilha(pilha);
    criaFila(pilha, fila);
    printf("\nTransformado em pilha: ");
    exibePilha(fila);


}