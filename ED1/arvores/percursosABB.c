#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *p_node;

struct node {
    int chave;
    p_node direita, esquerda;
};

typedef struct entrada {
    char in[4];
    struct entrada *prox;
} Entrada;

p_node iniciaArvore() {
    p_node raiz = malloc(sizeof(p_node));
    return raiz;
}

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
        printf("|%d|", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void pos_ordem(p_node raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("|%d|", raiz->chave);
    }
}

void inordem(p_node raiz) {
    if (raiz != NULL) {
        inordem(raiz->esquerda);
        printf("|%d|", raiz->chave);
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

// Lê as entradas do usuário e armazena em uma lista encadeada
Entrada* lerEntradas(Entrada *entradas, int n) {
    Entrada *aux = malloc(sizeof(Entrada));
    Entrada *head = aux;
    for (int i = 0; i < n; i++) {
        getc(stdin);
        fgets(aux->in, 4, stdin);

        if (i == n-1)
            aux->prox = NULL;
        else {
            aux->prox = malloc(sizeof(Entrada));
            aux = aux->prox;
        }
    }
    return head;
}

// Libera a memória alocada para a lista encadeada de entradas
void liberarEntradas(Entrada *entradas) {
    Entrada *aux = entradas;

    for (aux; aux != NULL; ) {
        entradas = entradas->prox;
        free(aux);
        aux = entradas;
    }
}

void processaEntradas(Entrada *entradas) {
    Entrada *aux = entradas;
    p_node raiz;
    for (aux; aux != NULL; aux = aux->prox) {
        switch (aux->in[0]) {
            case '1':
                raiz = iniciaArvore();
            case '2':
                inserirChave(raiz, aux->in[2]);
            case '3':
                pre_ordem(raiz);
            case '4':
                inordem(raiz);
            case '5':
                pos_ordem(raiz);
            case '6':
                deletarArvore(raiz);
            default:
                printf("=> '%s' operacao invalida.\n", aux->in);
        }
    }
}

// Recebe e processa as entradas do usuário
void entradaDados() {
    int n;
    scanf("%d", &n);
    Entrada *entradas = lerEntradas(entradas, n);

    processaEntradas(entradas);
    //liberarEntradas(entradas);
}

int main() {

    entradaDados();
    printf("\n\n");
}