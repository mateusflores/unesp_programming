#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char cod_cli[12];
    char cod_vei[8];
    char client[50];
    char veiculo[50];
    char dias[4];
} Registro;

typedef struct BTreeNode {
    int *keys; // array of keys
    int t;     // minimum degree (defines the range for number of keys)
    struct BTreeNode **C; // array of child pointers
    int n;     // current number of keys
    bool leaf; // is true when node is leaf. Otherwise false
} BTreeNode;

typedef struct BTree {
    BTreeNode *root; // pointer to root node
    int t;  // minimum degree
} BTree;

int main() {
    FILE *fp = fopen("registro.bin", "wb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(3)
    }

    
}

