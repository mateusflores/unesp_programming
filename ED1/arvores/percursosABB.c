#include <stdio.h>
#include <stdlib.h>

typedef struct node *p_node;

struct node {
    int valor;
    p_node pai, direita, esquerda;
};

p_node criarArvore(int chave, p_node esq, p_node dir) {
    p_node raiz = malloc(sizeof(struct node));
    raiz->valor = chave;
    raiz->direita = dir;
    raiz->esquerda = esq;
    return raiz;
}

p_node procurarPosicao(int valor, p_node raiz) {
    if (raiz == NULL || raiz->valor == valor) {
        criarArvore(valor, NULL, NULL);
        return raiz;
    }
    
    if (valor < raiz->direita->valor){ 
        return procurarPosicao(valor, raiz->esquerda);
    } else { 
        return procurarPosicao(valor, raiz->direita);
    }
}

int main() {
    int valores[5] = [10, 3, 12, 5, 11];

    for (int i = 0; i < 5; i++)
        

}