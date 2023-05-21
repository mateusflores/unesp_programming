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
    int nosInseridos;
    bool ehPrioritaria;
    //Usados apenas para o controle da fila prioritária
    Node *inicioFilaNormal;
    Node *fimFilaPrioritária;
} Fila;

bool verificaVazia (Fila *fila) {
    if (fila->inicio == NULL)
        return true;
    else
        return false;
}

void inicializaFila (Fila *fila, bool ehPriritaria) {
    fila->nosInseridos = 0;
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->fimFilaPrioritária = NULL;
    fila->inicioFilaNormal = NULL;
    fila->ehPrioritaria = ehPriritaria;
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
        fila->fim->prox = NULL;
    }
    fila->nosInseridos++;
}

// Insere o cliente na fila prioritária, mas faz o controle se o cliente deve ter prioridade no atendimento
void insereFilaPrioritaria (Fila *fila, Cliente cliente) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->cliente = cliente;
    aux->prox = NULL;
    aux->ant = NULL;

    if (fila->inicio == NULL && cliente.ehPrioritario == true) {
        fila->inicio = aux;
        fila->fim = aux;    
        fila->fimFilaPrioritária = aux;
    } else if (cliente.ehPrioritario == true) {
        aux->ant = fila->fimFilaPrioritária;
        fila->fimFilaPrioritária->prox = aux;
        fila->fimFilaPrioritária = aux;
        fila->fimFilaPrioritária->prox = fila->inicioFilaNormal;
    } else if (fila->inicioFilaNormal == NULL) {
        fila->inicioFilaNormal = aux;
        fila->fim = aux;
        fila->fim->ant = fila->fimFilaPrioritária;
    } else {
        aux->ant = fila->fim;
        fila->fim->prox = aux;
        fila->fim = aux;
    }
    fila->nosInseridos++;
}

// Remove o cliente que está no começo da fila
void removeCliente (Fila *fila) {
    if (verificaVazia(fila)) {
        return;
    } else {
        Node *aux = fila->inicio;

        fila->inicio = fila->inicio->prox;
        fila->inicio->ant = NULL;
        
        free(aux);
        fila->nosInseridos--;
    }
}

// Identifica qual a fila correta para o cliente
void insereNaFila (Fila *fila[], Cliente cliente) {
    if (cliente.ehPrioritario == true) {
        insereFilaPrioritaria(fila[2], cliente);
        printf("\nO cliente %s foi inserido na fila prioritária.", cliente.nome);
    } else if (cliente.itensCarrinho <= 10 && fila[1]->nosInseridos <= 7) {
        insereCliente(fila[1], cliente);
        printf("\nO cliente %s foi inserido na fila rápida.", cliente.nome);    
    } else if (fila[0]->nosInseridos <= 5 && cliente.itensCarrinho > 10) {
        insereCliente(fila[0], cliente);
        printf("\nO cliente %s foi inserido na fila convencional.", cliente.nome);
    } else { 
        insereFilaPrioritaria(fila[0], cliente);
        printf("\nO cliente %s foi inserido no final da fila prioritária, pois os demais caixas estão fora de serviço.", cliente.nome);    
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

Cliente criaCliente(char nome[], bool ehPrioritario, int itensCarrinho) {
    Cliente c;
    strcpy(c.nome, nome);
    c.ehPrioritario = ehPrioritario;
    c.itensCarrinho = itensCarrinho;

    return c;
}

int main() {
    Fila *caixaConvencional = malloc(sizeof(Fila));
    Fila *caixaRapido = malloc(sizeof(Fila));
    Fila *caixaPrioritario = malloc(sizeof(Fila));

    inicializaFila(caixaConvencional, false);
    inicializaFila(caixaPrioritario, true);
    inicializaFila(caixaRapido, false);

    // Agrupando os enderecos de memoria dos caixas em um vetor
    Fila *listaCaixas[3] = {caixaConvencional, caixaRapido, caixaPrioritario};

    Cliente c1 = criaCliente("Mateus", false, 14);
    Cliente c2 = criaCliente("Petrúcio", false, 30);
    Cliente c3 = criaCliente("Leona", false, 5);
    Cliente c4 = criaCliente("Haru", false, 11);
    Cliente c5 = criaCliente("Kiki", true, 3);
    Cliente c6 = criaCliente("Kaka", true, 5);
    Cliente c7 = criaCliente("Nika", false, 2);

    insereNaFila(listaCaixas, c1);
    insereNaFila(listaCaixas, c2);
    insereNaFila(listaCaixas, c3);
    insereNaFila(listaCaixas, c4);
    insereNaFila(listaCaixas, c5);
    insereNaFila(listaCaixas, c6);
    insereNaFila(listaCaixas, c7);

}