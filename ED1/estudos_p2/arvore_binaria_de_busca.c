#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int chave;
    struct node *pai, *esq, *dir;
} Node;

Node* criaElemento(Node *raiz, int chave) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->chave = chave;
    aux->pai = raiz;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}

Node* insereElemento(Node* raiz, int chave) {
    if (raiz == NULL) {
        return criaElemento(NULL, chave);
    } 
    
    if (raiz->chave > chave) {
        if (raiz->esq == NULL)
            raiz->esq = criaElemento(raiz, chave);
        else 
            raiz->esq = insereElemento(raiz->esq, chave);
    } else if (raiz->chave < chave) {
        if (raiz->dir == NULL)
            raiz->dir = criaElemento(raiz, chave);
        else 
            raiz->dir = insereElemento(raiz->dir, chave);
    }

    return raiz;
}

bool ehABB (Node* raiz) {
    if (raiz != NULL) {
        if (raiz->esq != NULL && raiz->dir != NULL) {
            if (!(raiz->esq->chave < raiz->chave && raiz->dir->chave > raiz->chave))
                return false;
        } else if (raiz->esq == NULL && raiz->dir != NULL) {
            if (!(raiz->dir->chave > raiz->chave))
                return false;
        } else if (raiz->dir == NULL && raiz->esq != NULL) {
            if (!(raiz->esq->chave < raiz->chave))
                return false;
        } else
            return true;
        
        return (ehABB(raiz->esq) && ehABB(raiz->dir)) ? true : false;
    } else 
        return false;
}

void inOrder (Node* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf("|%d| ", raiz->chave);
        inOrder(raiz->dir);
    }
}

Node* minimo (Node* raiz) {
    if (raiz != NULL) {
        if (raiz->esq == NULL)
            return raiz;
        else 
            return minimo(raiz->esq);
    }
}

Node* maximo (Node* raiz) {
    if (raiz != NULL) {
        if (raiz->dir == NULL)
            return raiz;
        else
            return maximo(raiz->dir);
    }
}

Node* removerNoh (Node* raiz, int chave) {
    
}

int main() {
    int entradas[] = {8, 3, 9, 7, 2, 4};
    Node *raiz = NULL;
    raiz = criaElemento(raiz, 6);

    for (int i = 0; i < (sizeof(entradas)/sizeof(int)); i++) {
        insereElemento(raiz, entradas[i]);
    }

    Node *raiz2 = NULL;
    raiz2 = criaElemento(NULL, 5);
    raiz2->esq = criaElemento(NULL, 3);
    raiz2->dir = criaElemento(NULL, 8);
    
    if (ehABB(raiz))
        printf("\nEh abb\n");
    else {
        printf("\nNão eh abb\n");}

    printf("\ninOrder: ");
    inOrder(raiz);
    printf("\n");

    printf("\nMínimo: %d", minimo(raiz)->chave);

    printf("\nMáximo: %d", maximo(raiz)->chave);
    printf("\n");
    

}