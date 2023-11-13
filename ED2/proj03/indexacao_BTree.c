#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_KEYS 3

typedef struct {
    char codCli[11];
    char codVei[7];
    char *nomeCli;
    char *nomeVei;
    int numDias;
} Registro;

typedef struct BTreeNode {
    int keys[MAX_KEYS];  // array de chaves
    struct BTreeNode *children[MAX_KEYS + 1];  // array de ponteiros para os filhos
    int n;  // número de chaves atualmente no nó
    bool leaf;
} BTreeNode;

typedef struct BTree {
    BTreeNode *root;
    int t;
} BTree;

int main() {
    FILE *fp = fopen("registro.bin", "wb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(3)
    }

    
}

