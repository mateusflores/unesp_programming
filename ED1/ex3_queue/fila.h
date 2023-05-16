#include "cliente.h"

typedef struct node {
    struct node *ant;
    struct node *prox;
    Cliente cliente;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} Fila;

Fila* inicializaFila () {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
        *fila = NULL;
    return fila;
}

void insereCliente (Fila *fila, Node *cliente) {

}

void removeCliente (Fila *fila, Node *cliente) {
    
}

bool verificaVazia (Fila *fila) {

}

int tamanhoFila (Fila *fila) {

}