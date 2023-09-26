// Mateus Gomes Flores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct aluno {
    int matricula;
    char nome[30];
    double np1, np2, notaEx;
    struct aluno *prox;
} Aluno;

double calculaMedia (Aluno *node) {
    return (node->notaEx + node->np1 + node->np2)/3;
}

void infoAlunos (Aluno *lista) {
    Aluno *maiorP1 = lista, *maiorMedia = lista, *menorMedia = lista;
    Aluno *aux;
    for (aux = lista; aux != NULL; aux = aux->prox) {
        if (aux->np1 > maiorP1->np1)
            maiorP1 = aux;
        
        if (calculaMedia(aux) > calculaMedia(maiorMedia))
            maiorMedia = aux;
        
        if (calculaMedia(aux) < calculaMedia(menorMedia))
            menorMedia = aux;
    }

    printf("\n=>O aluno com ID %d possui a maior nota na prova 1 (%.2lf)", maiorP1->matricula, maiorP1->np1);
    printf("\n=>O aluno com ID %d possui a maior media (%.2lf)", maiorMedia->matricula, calculaMedia(maiorMedia));
    printf("\n=>O aluno com ID %d possui a menor media (%.2lf)\n", menorMedia->matricula, calculaMedia(menorMedia));
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

Aluno* deletarAluno(Aluno *head, int id) {
    Aluno *aux;
    Aluno *anterior = NULL;
    bool idExiste = false;

    for (aux = head; aux != NULL; aux = aux->prox) {
        if (aux->matricula == id) {
            idExiste = true;
            break;
        }
        anterior = aux;
    }

    if (idExiste == false) {
        puts("\n=> Nao foi encontrado nenhum aluno com o ID informado.");
        return head;
    } else if (aux->matricula == head->matricula) {
        head = aux->prox;
        free(aux);
        printf("\n=> Aluno com ID %d removido com sucesso.\n", id);
        return head;
    } else {
        anterior->prox = aux->prox;
        free(aux);
        printf("\n=> Aluno com ID %d removido com sucesso.\n", id);
        return head;
    }
}

void imprimeLista (Aluno *head) {
    Aluno *aux;
    puts("\n---------------------------------LISTA DE ALUNOS----------------------------------\n");
    for (aux=head; aux != NULL; aux = aux->prox) {
        printf("Nome: %s", aux->nome);
        printf("Matricula: %2d   |   Nota P1: %.2lf   |   Nota P2: %.2lf   |   Nota Exercicios: %.2lf   \n", aux->matricula, aux->np1, aux->np2, aux->notaEx);
    }
    puts("\n-----------------------------------------------------------------------------------\n");
}

void exibirClassificados (Aluno *head) {
    Aluno *aux;

    puts("\nID      Situacao");
    puts("---------------");
    for (aux = head; aux != NULL; aux = aux->prox) {
        printf("%2d\t", aux->matricula);

        if (calculaMedia(aux) < 5)
            printf("REPROVADO\n");
        else 
            printf("APROVADO\n");
    }
}

void menuUsuario(Aluno *lista) {
    int op = 0;
    int id;

    while (op != 6) {
        puts("\n**** Selecione uma operacao ****\n1. Exibe lista de alunos\n2. Deleta aluno\n3. Mostra quantidade de alunos na turma");
        puts("4. Ver aluno com maior nota na P1, maior media e menor media\n5. Ver alunos aprovados ou reprovados\n6. Sair\n");

        scanf("%d", &op);

        switch (op) {
        case 1:
            imprimeLista(lista);
            break;
        case 2: 
            puts("Insira o ID do aluno a ser deletado:");
            scanf("%d", &id);
            lista = deletarAluno(lista, id);
            break;
        case 3:
            printf("\n=> Existem %d alunos matriculados na turma.\n\n", quantidadeAlunos(lista));
            break;
        case 4:
            infoAlunos(lista);
            break;
        case 5:
            exibirClassificados(lista);
            break;
        default:
            break;
        }
    }
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

    menuUsuario(lista);
}