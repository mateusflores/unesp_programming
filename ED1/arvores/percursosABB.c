#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *p_node;

struct node {
    int chave;
    p_node direita, esquerda;
};

typedef struct entrada {
    char in[3];
    struct entrada *prox;
} Entrada;

p_node criarArvore(int chave) {
    p_node raiz = malloc(sizeof(struct node));
    raiz->chave = chave;
    raiz->direita = NULL;
    raiz->esquerda = NULL;
    return raiz;
}

p_node inserirChave(p_node raiz, int valor) {
    if (raiz->direita == NULL && raiz->chave < valor)
        return raiz->direita = criarArvore(valor);
    if (raiz->esquerda == NULL && raiz->chave > valor)
        return raiz->esquerda = criarArvore(valor);
    if (raiz->chave == valor)
        return raiz;
    
    if (raiz->chave < valor)
        return inserirChave(raiz->direita, valor);
    else 
        return inserirChave(raiz->esquerda, valor);
    
}

void pre_ordem(p_node raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void pos_ordem(p_node raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

void inordem(p_node raiz) {
    if (raiz != NULL) {
        inordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inordem(raiz->direita);
    }
}

void deletarArvore(p_node raiz) {
    if (raiz != NULL) {
        deletarArvore(raiz->esquerda);
        deletarArvore(raiz->direita);
        free(raiz);
        printf("0 ");
    }
}

void lerEntrada(Entrada *entradas) {
    Entrada *aux = entradas;
    for (aux; aux != NULL; aux = aux->prox);
    aux = malloc(sizeof(Entrada));

    /** CONTINUAR */
}

void entradaDados() {
    Entrada *entradas = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

    }
}

int main() {
    int valores[5] = {8, 3, 12, 5, 11};

    p_node raiz = criarArvore(10);
    
    for (int i = 0; i < 5; i++) {
        inserirChave(raiz, valores[i]);
    }

    printf("\nPre: ");
    pre_ordem(raiz);
    printf("\nPos: ");
    pos_ordem(raiz);
    printf("\nIn: ");
    inordem(raiz);
    printf("\n");

    deletarArvore(raiz);
        

}