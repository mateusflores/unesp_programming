#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[30];
    double np1, np2, notaEx;
    Aluno *prox;
} Aluno;

int quantidadeAlunos(Aluno *head) {
    int num = 0;
    Aluno *aux = head;
    while (aux->prox != NULL) {
        num++;
        aux = aux->prox;
    }

    return num;
}

int main() {
    Aluno *head;


}