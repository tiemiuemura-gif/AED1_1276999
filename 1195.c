/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 17/11/26
Objetivo    : busca e arvore binaria
Dificuldade : deixar a saida do jeito que o beecrowd queria
Uso de IA   : para corrigir o texto
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int conteudo;
    struct no *esq, *dir;
} no;

int primeiro;

no *criaNo(int valor) {
    no *novo = malloc(sizeof(no));

    novo->chave = valor;
    novo->conteudo = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

no *inserirNo(int valor, no *r) {
    if (r == NULL) {
        return criaNo(valor);
    }

    if (valor < r->chave) {
        r->esq = inserirNo(valor, r->esq);
    }
    else {
        r->dir = inserirNo(valor, r->dir);
    }

    return r;
}

// Percurso prefixo
void prefix(no *r) {
    if (r == NULL) {
        return;
    }

    if (primeiro == 0) {
        printf(" ");
    }

    printf("%d", r->conteudo);
    primeiro = 0;

    prefix(r->esq);
    prefix(r->dir);
}

// Percurso infixo
void infix(no *r) {
    if (r == NULL) {
        return;
    }

    infix(r->esq);

    if (primeiro == 0) {
        printf(" ");
    }

    printf("%d", r->conteudo);
    primeiro = 0;

    infix(r->dir);
}

// Percurso posfixo
void posfix(no *r) {
    if (r == NULL) {
        return;
    }

    posfix(r->esq);
    posfix(r->dir);

    if (primeiro == 0) {
        printf(" ");
    }

    printf("%d", r->conteudo);
    primeiro = 0;
}

// Liberar memória
void liberar(no *r) {
    if (r == NULL) {
        return;
    }

    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main() {
    int C, N;

    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        scanf("%d", &N);

        no *r = NULL;

        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%d", &valor);

            r = inserirNo(valor, r);
        }

        printf("Case %d:\n", i + 1);

        printf("Pre.: ");
        primeiro = 1;
        prefix(r);
        printf("\n");

        printf("In..: ");
        primeiro = 1;
        infix(r);
        printf("\n");

        printf("Post: ");
        primeiro = 1;
        posfix(r);
        printf("\n\n");

        liberar(r);
    }

    return 0;
}