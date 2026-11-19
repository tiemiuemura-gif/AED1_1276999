
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : -
Objetivo    : analisar documentos
Dificuldade : não entendi o main
Uso de IA   : para fazer o main
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

int dfs(No *adj[], int origem, int estado[]) {

    estado[origem] = 1;

    No *p = adj[origem];

    while (p != NULL) {

        int w = p->valor;

        if (estado[w] == 1) {
            return 1;
        }

        if (estado[w] == 0) {
            if (dfs(adj, w, estado)) {
                return 1;
            }
        }

        p = p->prox;
    }

    estado[origem] = 2;
    return 0;
}

int main() {

    int T, N, M;
    scanf("%d", &T);

    while (T--) {

        scanf("%d %d", &N, &M);

        No *adj[N];

        for (int i = 0; i < N; i++) {
            adj[i] = NULL;
        }

        for (int i = 0; i < M; i++) {

            int A, B;
            scanf("%d %d", &A, &B);

            No *novo = malloc(sizeof(No));

            novo->valor = B - 1;
            novo->prox = adj[A - 1];

            adj[A - 1] = novo;
        }

        int estado[N];

        for (int i = 0; i < N; i++) {
            estado[i] = 0;
        }

        int ciclo = 0;

        for (int j = 0; j < N; j++) {

            if (estado[j] == 0) {

                if (dfs(adj, j, estado)) {
                    ciclo = 1;
                    break;
                }
            }
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        for (int i = 0; i < N; i++) {
            No *p = adj[i];

            while (p != NULL) {
                No *aux = p;
                p = p->prox;
                free(aux);
            }
        }
    }

    return 0;
}
