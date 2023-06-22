#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *p_node;

struct node {
    int chave;
    p_node direita, esquerda;
};

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

/* Recebendo e processando as entradas do usuário */

typedef struct entrada {
    int O;
    int I;
    struct entrada *prox;
} Entrada;

void removerQuebraDeLinha(char *txt, int n) {
    for (int i = 0; i < n; i++) {
        if (txt[i] == '\n') {
            txt[i] = '\0';
            return;
        }
    }
}

Entrada* lerComandos(int quantidadeComandos) {
    int n = 0;
    Entrada *head = malloc(sizeof(Entrada));
    Entrada *aux = head;
    char buff[10];
    while (n < quantidadeComandos) {
        if (n == 0)
            getchar();
        fgets(buff, sizeof(buff), stdin);
        removerQuebraDeLinha(buff, 10);
        sscanf(buff, "%d %d", &aux->O, &aux->I);
        
        if (n == (quantidadeComandos-1)) {
            aux->prox = NULL;
            n++;
        } else {
            aux->prox = malloc(sizeof(Entrada));
            aux = aux->prox;
            n++;
        }
    }
    return head;
}

int processarComandos(Entrada *entradas) {
    Entrada *aux = entradas;
    p_node raiz;
    for (aux; aux != NULL; aux = aux->prox) {
        switch (aux->O)
        {
        case 1:
            raiz = criarArvore(aux->prox->I);
            aux = aux->prox;
            break;
        case 2:
            inserirChave(raiz, aux->I);
            break;
        case 3:
            puts("");
            pre_ordem(raiz);
            break;
        case 4:
            puts("");
            inordem(raiz);
            break;
        case 5:
            puts("");
            pos_ordem(raiz);
            break;
        case 6:
            puts("");
            deletarArvore(raiz);
            break;
        default:
            printf("Comando invalido.\n");
            break;
        }
    }
}

int main() {
    int quantidadeComandos;
    scanf("%d", &quantidadeComandos);

    if (quantidadeComandos <= 2) {
        printf("A quantidade de comandos deve ser maior que 2.\n");
        return 0;
    }

    Entrada *entradas = lerComandos(quantidadeComandos);
    processarComandos(entradas);
    puts("");
}