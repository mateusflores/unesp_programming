// Mateus Gomes Flores  RA: 221150391

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

// Se a pilha estiver vazia, atribui "FACE" ao elemento no topo 
bool checkTopoVazio(Stack *pilha) {
    if (pilha->topo == NULL) {
        pilha->topo = malloc(sizeof(Node));

        pilha->topo->a = 'F';
        pilha->topo->b = 'A';
        pilha->topo->c = 'C';
        pilha->topo->d = 'E';
        pilha->topo->prox = NULL;

        return true;
    } else
        return false;
}

void inicializaPilha(Stack *pilha) {
    pilha->topo = NULL;
    checkTopoVazio(pilha);
}

// Verifica se o item no topo eh igual ao item anterior na pilha
bool checkReverso(Node *atual, Node *anterior) {
    if (atual->a == anterior->d && atual->b == anterior->c && atual->c == anterior->b && atual->d == anterior->a)
        return true;
    else
        return false;
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

// Remove o item do topo e o próximo, caso eles sejam reversos
void removeItens(Stack *pilha) {
    for (int i=0; i<2; i++) {
        Node *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}

int premiaParticipante(Stack *pilha) {
    if (checkReverso(pilha->topo, pilha->topo->prox)) {
        removeItens(pilha);
        return 1;
    }
    return 0;
}

// Retorna a quantidade de pessoas premiadas
int entradasPainel(Stack *pilha, int num) {
    int quantidadeGanhadores = 0;
    char frase[5];
    for (int i=0; i<num; i++) {
        fscanf(stdin, "%s", frase);
        insereItem(pilha, frase);
        quantidadeGanhadores += premiaParticipante(pilha);
        checkTopoVazio(pilha);
    }
    return quantidadeGanhadores;
}

int main() {
    int quantidadeGanhadores = 0;
    Stack pilha;
    inicializaPilha(&pilha);

    int num;
    scanf("%d", &num);

    quantidadeGanhadores = entradasPainel(&pilha, num);

    printf("%d\n", quantidadeGanhadores);
}