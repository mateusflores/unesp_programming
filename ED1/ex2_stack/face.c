#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char a, b, c, d;
    struct node *prox;
} Node;

typedef struct {
    Node *topo;
} Stack;

void inicializaPilha(Stack *pilha) {
    pilha->topo = NULL;
}

bool pilhaVazia(Stack *pilha) {
    return (pilha->topo == NULL);
}

void insereItem(Stack *pilha, char frase[]) {
    Node *aux;
    aux = malloc(sizeof(Node));

    aux->a = frase[0];
    aux->b = frase[1];
    aux->c = frase[2];
    aux->d = frase[3];

    aux->prox = pilha->topo;
    pilha->topo = aux;
}

void removeItens(Stack *pilha) {
    
}

int main() {
    Stack *pilha;
    inicializaPilha(pilha);

    int quantidade;
    scanf("%d", &quantidade);

    char resposta[5];
    getc(stdin);
    fgets(resposta, 5, stdin);
    insereItem(pilha, resposta);


}