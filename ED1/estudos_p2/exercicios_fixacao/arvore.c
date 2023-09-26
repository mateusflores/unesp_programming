#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node *esquerda, *direita;
} Node;

Node* criaElemento(int chave) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->chave = chave;
    aux->direita = NULL;
    aux->esquerda = NULL;
    return aux; 
}

Node* iniciaArvore(Node* r, int valor) {
    r = criaElemento(valor);
    return r;
}

Node* insereElemento (Node* raiz, int chave) {
    if (raiz == NULL) {
        raiz = criaElemento(chave);
        return raiz;
    }
    if (raiz->chave > chave) 
        raiz->esquerda = insereElemento(raiz->esquerda, chave);
    else if (raiz->chave < chave)
        raiz->direita = insereElemento(raiz->direita, chave);
    
    return raiz;
}

int calculaFolhas (Node* raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return calculaFolhas(raiz->direita) + calculaFolhas(raiz->esquerda);
}

Node* apagaFolha (Node* raiz, int chave) {
    if (raiz != NULL) {
        if (raiz->chave == chave) {
            raiz = NULL;
            printf("Folha %d apagada com sucesso.\n", chave);
            return raiz;
        } else {
            apagaFolha(raiz->esquerda, chave);
            apagaFolha(raiz->direita, chave);
        }

    }
}

int main() {
    int entradas[] = {7, 4, 16, 8, 18};

    Node* raiz = iniciaArvore(raiz, 11);

    for (int i = 0; i < (sizeof(entradas)/sizeof(int)); i++) {
        insereElemento(raiz, entradas[i]);
        printf("Elemento %d inserido com sucesso.\n", entradas[i]);
    }

    printf("\nNUMERO DE FOLHAS: %d\n", calculaFolhas(raiz));
    apagaFolha(raiz, 18);

    printf("\nNUMERO DE FOLHAS: %d\n", calculaFolhas(raiz));
}