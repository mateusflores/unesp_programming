// Mateus Gomes Flores (RA: 221150391)
// gcc -std=c99 -pedantic -Wall -lm -o caixaMercado caixaMercado.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    int inseridosAtehOMomento;
    int clientesAtendidos;
    int tempoTotal;
    bool ehPrioritaria;
    Node *inicio;
    Node *fim;
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

void inicializaFila (Fila *fila, bool ehPrioritaria) {
    fila->clientesAtendidos = 0;
    fila->tempoTotal = 0;
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->fimFilaPrioritária = NULL;
    fila->inicioFilaNormal = NULL;
    fila->ehPrioritaria = ehPrioritaria;
}

// Insere o cliente no final da fila
void insereCliente (Fila *fila, Cliente cliente) {
    Node *aux = (Node*) malloc(sizeof(Node));
    aux->cliente = cliente;
    aux->prox = NULL;
    aux->ant = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = aux;
        fila->fim = aux;    
    } else {
        fila->fim->prox = aux;
        fila->fim = aux;
        fila->fim->prox = NULL;
    }
    fila->inseridosAtehOMomento++;
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
    fila->inseridosAtehOMomento++;
}

// Remove o cliente que está no começo da fila
void removeCliente (Fila *fila) {
    if (verificaVazia(fila)) {
        return;
    } else {
        Node *aux = fila->inicio;
        fila->tempoTotal += fila->inicio->cliente.itensCarrinho;

        fila->inicio = fila->inicio->prox;
        fila->inicio->ant = NULL;
        
        free(aux);
        fila->clientesAtendidos++;
    }
}

// Identifica qual a fila correta para o cliente
void insereNaFila (Fila *fila[], Cliente cliente) {
    if (cliente.ehPrioritario == true) {
        insereFilaPrioritaria(fila[2], cliente);
        printf("\nO cliente %s foi inserido na fila prioritária.", cliente.nome);
    } else if (cliente.itensCarrinho <= 10 && fila[1]->clientesAtendidos <= 7) {
        insereCliente(fila[1], cliente);
        printf("\nO cliente %s foi inserido na fila rápida.", cliente.nome);    
    } else if (fila[0]->clientesAtendidos <= 5 && cliente.itensCarrinho > 10) {
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

// Gera um cliente aleatório
Cliente criaCliente(bool ehPrioritario, int quantidadeItens) {
    char nomesAleatorios[40][30] = {"Mateus", "Isabel ", "Joao", "Pedro", "Ana", "Maria", "Juliana", "Marcos", "Ricardo", "Joana", "Leonardo", "Wilson", "Claudia",
    "Gilberto", "Isabela", "Giovana", "Pamela", "Lucas", "Marcelo", "Rodrigo", "Jorge", "Rubens", "Luana", "Karen", "Adamastor", "Nestor", "Petrucio", "Leona",
    "Sebastiao", "Rogerio", "Lurdes", "Benedito", "Gisele", "Julia", "Natan", "Bartolomeu", "Bruno", "Paulo", "Eduardo", "Rafaela"};

    Cliente c;
    strcpy(c.nome, nomesAleatorios[rand() % 40]);
    c.ehPrioritario = ehPrioritario;
    c.itensCarrinho = quantidadeItens;
    return c;
}

void exibeFila(Fila *filas[]) {
    for (int i = 0; i < 3; i++) {
        if (i == 0)
            printf("\n* { CAIXA CONVENCIONAL } ==> ");
        else if (i == 1)
            printf("\n*       { CAIXA RAPIDO } ==> ");
        else 
            printf("\n*  { CAIXA PRIORITARIO } ==> ");

        for (Node *aux = filas[i]->inicio; aux != NULL; aux = aux->prox) {
            printf("[ %s(%d itens) ] -> ", aux->cliente.nome, aux->cliente.itensCarrinho);
        }
        puts("");
    }
}

int main() {
    srand(time(NULL));

    // Alocando memória para as três filas
    Fila *caixaConvencional = malloc(sizeof(Fila));
    Fila *caixaRapido = malloc(sizeof(Fila));
    Fila *caixaPrioritario = malloc(sizeof(Fila));

    // Inicializando as filas
    inicializaFila(caixaConvencional, false);
    inicializaFila(caixaPrioritario, true);
    inicializaFila(caixaRapido, false);

    // Agrupando os enderecos de memoria dos caixas em um vetor
    Fila *listaCaixas[3] = {caixaConvencional, caixaRapido, caixaPrioritario};

    // Gerando entre 1 e 5 clientes prioritários e direcinando para a fila correta
    for (int i = 0; i < (rand() % 4 + 1); i++) {
        int randItens = rand() % 19 + 1;
        insereNaFila(listaCaixas, criaCliente(true, randItens));
    }

    // Gerando entre 10 e 20 clientes não prioritários e direcinando para a fila correta
    for (int i = 0; i < (rand() % 9 + 11); i++) {
        int randItens = rand() % 19 + 1;
        insereNaFila(listaCaixas, criaCliente(false, randItens));
    }

    puts("");
    puts("--------------------------"); 
    exibeFila(listaCaixas);
}