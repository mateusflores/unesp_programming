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

typedef struct {
    char cod_cli[12];
    char cod_vei[8];
    int pos;
} Indice;

void inserir_indice(BTree *arvore, char *cod_cli, char *cod_vei, int pos) {
    // Implemente a função de inserção na árvore B aqui
}

void escrever_indice(BTree *arvore, FILE *fp) {
    // Implemente a função de escrita do índice no arquivo aqui
}

int main() {
    FILE *fp = fopen("registro.bin", "wb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(3)
    }

    FILE *fp_indice = fopen("indice.bin", "wb+");
    if (fp_indice == NULL) {
        printf("Erro ao abrir o arquivo de índice.\n");
        exit(3);
    }

    BTree *arvore = criar_arvore(); // Implemente a função de criação da árvore B aqui

    // Suponha que temos um array de registros
    Registro registros[] = {	{"11111111111", "ABC1234", "Cliente-1", "Veiculo-11", "2"},
                                {"22222222222", "ABC1234", "Cliente-2", "Veiculo-11", "8"},
                                {"33333333333", "CDE9874", "Cliente-3", "Veiculo-33", "1"},
                                {"44444444444", "ERT4561", "Cliente-4", "Veiculo-44", "11"},
                                {"11111111111", "ERT4561", "Cliente-1", "Veiculo-44", "2"},
                                {"11111111111", "UJG3574", "Cliente-1", "Veiculo-66", "3"},
                                {"77777777777", "TOP5487", "Cliente-7", "Veiculo-22", "2"},
                                {"88888888888", "IUY3214", "Cliente-8", "Veiculo-88", "2"},
            // para teste de chaves duplicadas
                                {"11111111111", "ABC1234", "Cliente-1", "Veiculo-11", "2"},
                                {"22222222222", "ABC1234", "Cliente-2", "Veiculo-11", "8"}};
    for (int i = 0; i < sizeof(registros) / sizeof(Registro); i++) {
        fwrite(&registros[i], sizeof(Registro), 1, fp);
        inserir_indice(arvore, registros[i].cod_cli, registros[i].cod_vei, i);
    }

    escrever_indice(arvore, fp_indice);

    fclose(fp);
    fclose(fp_indice);
    
}

