#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* novoNo(int valor) {
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = valor;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct TreeNode** gerar(int inicio, int fim, int* quantidade) {
    if (inicio > fim) {
        struct TreeNode** lista = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        lista[0] = NULL;
        *quantidade = 1;
        return lista;
    }

    struct TreeNode** resultado = NULL;
    *quantidade = 0;

    for (int i = inicio; i <= fim; i++) {
        int qtdEsq, qtdDir;

        struct TreeNode** esquerda = gerar(inicio, i - 1, &qtdEsq);
        struct TreeNode** direita = gerar(i + 1, fim, &qtdDir);

        for (int j = 0; j < qtdEsq; j++) {
            for (int k = 0; k < qtdDir; k++) {

                resultado = realloc(
                    resultado,
                    (*quantidade + 1) * sizeof(struct TreeNode*)
                );

                struct TreeNode* raiz = novoNo(i);

                raiz->left = esquerda[j];
                raiz->right = direita[k];

                resultado[*quantidade] = raiz;
                (*quantidade)++;
            }
        }

        free(esquerda);
        free(direita);
    }

    return resultado;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    return gerar(1, n, returnSize);
}

int main() {
    int quantidade;

    struct TreeNode** arvores = generateTrees(3, &quantidade);

    printf("Quantidade de árvores: %d\n", quantidade);

    free(arvores);

    return 0;
}