#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[30];
    double np1, np2, notaEx;
    struct aluno *prox;
} Aluno;

double calculaMedia (Aluno *node) {
    return (node->notaEx + node->np1 + node->np2)/3;
}

int quantidadeAlunos(Aluno *head) {
    int num;
    Aluno *aux = head;

    num = (aux != NULL) ? 1 : 0;

    while (aux->prox != NULL) {
        num++;
        aux = aux->prox;
    }
    return num;
}

Aluno* addAlunos(int quantidadeAlunos) {
    // Primeiro registro
    Aluno *aux = malloc(sizeof(Aluno));
    Aluno *head = aux;
    
    for (int i=0; i<quantidadeAlunos; i++) {
        aux->matricula = i+1;
        getc(stdin);
        puts("Nome: ");
        fgets(aux->nome, 30, stdin);
        puts("Nota da prova 1: ");
        scanf("%lf", &aux->np1);
        puts("Nota da prova 2: ");
        scanf("%lf", &aux->np2);
        puts("Nota do exercicio: ");
        scanf("%lf", &aux->notaEx);

        // Criando próximo node ou atribuindo NULL caso esteja no final da lista
        if (i != quantidadeAlunos-1) {
            aux->prox = malloc(sizeof(Aluno));
            aux = aux->prox;
        } else 
            aux->prox = NULL;
    }
    return head;
}

void imprimeLista (Aluno *head) {
    Aluno *aux;
    for (aux=head; aux != NULL; aux = aux->prox) {
        puts("\n-----------------------------------------------------------------------------------\n");
        printf("Nome: %s", aux->nome);
        printf("Matricula: %2d   |   Nota P1: %.2lf   |   Nota P2: %.2lf   |   Nota Exercicios: %.2lf   \n", aux->matricula, aux->np1, aux->np2, aux->notaEx);
    }
    puts("\n-----------------------------------------------------------------------------------\n");
}

int main() {
    int quant;
    puts("Quantos alunos deseja inserir? (max: 50 alunos)");
    do {
        scanf("%d", &quant);
        if (quant > 50)
            printf("Numero invalido. O numero maximo de alunos deve ser menor que 50.\nInsira novamente:\n");
    } while (quant > 50);

    Aluno *lista = addAlunos(quant);
    printf("Quantidade de alunos inseridos: %d", quantidadeAlunos(lista));

    imprimeLista(lista);
}