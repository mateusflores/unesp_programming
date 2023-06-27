#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int chave;
    struct node *esq, *dir;
} Node;

Node* criaNode (int valor) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->chave = valor;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
}

Node* insereChave(Node* raiz, int valor) {
    if (raiz == NULL)
        return criaNode(valor);
    if (raiz->chave > valor)
        raiz->esq = insereChave(raiz->esq, valor);
    if (raiz->chave < valor)
        raiz->dir = insereChave(raiz->dir, valor);
    
    return raiz;
}

Node* preOrder (Node* raiz) {
    if (raiz != NULL) {
        printf(" |%d| ->", raiz->chave);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

Node* inOrder (Node* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf(" |%d| ->", raiz->chave);
        inOrder(raiz->dir);
    }
}

Node* posOrder (Node* raiz) {
    if (raiz != NULL) {
        posOrder(raiz->esq);
        posOrder(raiz->dir);
        printf(" |%d| ->", raiz->chave);
    }
}


// EXERCÍCIO 2
void apagarFolhas(Node* raiz) {
    if (raiz != NULL) {
        if (raiz->dir == NULL && raiz->esq == NULL) {
            free(raiz);
            raiz = NULL;
        } else {
            apagarFolhas(raiz->esq);
            apagarFolhas(raiz->dir);
        }
    }
}

// EXERCÍCIO 3
bool saoIguais (Node* r1, Node* r2) {
    if (r1 == NULL && r2 == NULL)
        return true;
    else if (r1 != NULL || r2 != NULL)
        return false;
    else if (r1->chave != r2->chave)
        return false;
    else if (r1 != NULL && r2 != NULL)
        return saoIguais(r1->esq, r2->esq) && saoIguais(r1->dir, r2->dir);
}

int main() {
    int entradas1[] = {2, 9, 8, 4, 3, 5};
    int entradas2[] = {2, 4, 8, 4, 3, 5};

    Node *raiz1 = criaNode(7);
    Node *raiz2 = criaNode(7);

    for (int i = 0; i < (sizeof(entradas1)/sizeof(int)); i++) {
        insereChave(raiz1, entradas1[i]);
        insereChave(raiz2, entradas2[i]);
    }

    if (saoIguais(raiz1, raiz2)){
        printf("Sao iguais");
    } else {
        printf("Diferentes");
    }

    printf("\nPre-Ordem: ");
    preOrder(raiz1);
    printf("\nIn-Ordem:  ");
    inOrder(raiz1);
    printf("\nPos-Ordem: ");
    posOrder(raiz1);
    printf("\n");

    apagarFolhas(raiz1);
    printf("\nIn-Ordem (folhas apagadas):  ");

    
}