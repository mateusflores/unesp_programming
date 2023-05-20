#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[30];
    bool ehPrioritario;
    int itensCarrinho;    
} Cliente;

typedef struct node {
    struct node *ant;
    struct node *prox;
    Cliente cliente;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} Fila;

bool verificaVazia (Fila *fila) {
    if (fila->inicio == NULL)
        return true;
    else
        return false;
}

void inicializaFila (Fila *fila) {
    fila->fim = NULL;
    fila->inicio = NULL;
}

// Insere o cliente no final da fila
void insereCliente (Fila *fila, Cliente cliente) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->cliente = cliente;
    aux->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = aux;
        fila->fim = aux;    
    } else {
        fila->fim->prox = aux;
        fila->fim = aux;
    }
}

// Remove o cliente que está no começo da fila
void removeCliente (Fila *fila) {
    if (verificaVazia(fila)) {
        return;
    } else {
        Node *aux = fila->inicio;
        if (fila->inicio == fila->fim) {
            inicializaFila(fila);
        } else {
            fila->inicio = fila->inicio->prox;
            fila->inicio->ant = NULL;
        }
        free(aux);
    }
}

int tamanhoFila (Fila *fila) {
    int tam = 0;
    Node *aux;
    for (aux=fila->inicio; aux != NULL; aux=aux->prox) {
        tam += 1;
    }
    return tam;
}

Cliente criaCliente(char nome[30], bool ehPrioritario, int itensCarrinho) {
    Cliente c;
    strcpy(c.nome, nome);
    c.ehPrioritario = ehPrioritario;
    c.itensCarrinho = itensCarrinho;

    return c;
}

int main() {
    Fila *fila = malloc(sizeof(Fila));
    inicializaFila(fila);

    Cliente c1 = {"Mateus", false, 14};
    Cliente c2 = {"Petrúcio", false, 30};
    Cliente c3 = {"Leona", true, 5};
    Cliente c4 = {"Haru", false, 11};

    insereCliente(fila, c1);
    insereCliente(fila, c2);
    insereCliente(fila, c3);

    if (verificaVazia(fila))
        printf("\nVazia\n\n");
    else { 
        printf("\nNao Vazia\nTamanho: %d\n\n", tamanhoFila(fila));
    }

    removeCliente(fila);

    if (verificaVazia(fila))
        printf("\nVazia\n\n");
    else 
        printf("\nNao Vazia\nTamanho: %d\n\n", tamanhoFila(fila));

}