/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 19/11/26
Objetivo    : executar comandos
Dificuldade : erros de logica apenas
Uso de IA   : correção
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char chave;
    char conteudo;
    struct no *esq;
    struct no *dir;
} no;

int primeiro;

no *criaNo(char valor) {
    no *novo = malloc(sizeof(no));

    novo->chave = valor;
    novo->conteudo = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

no *inserirNo(no *r, char valor) {
    if (r == NULL) {
        return criaNo(valor);
    }

    if (valor < r->chave) {
        r->esq = inserirNo(r->esq, valor);
    }
    else if (valor > r->chave) {
        r->dir = inserirNo(r->dir, valor);
    }

    return r;
}

void prefix(no *r) {
    if (r == NULL) {
        return;
    }

    if (primeiro)
        printf(" ");

    printf("%c", r->conteudo);
    primeiro = 1;

    prefix(r->esq);
    prefix(r->dir);
}

void infix(no *r) {
    if (r == NULL) {
        return;
    }

    infix(r->esq);

    if (primeiro)
        printf(" ");

    printf("%c", r->conteudo);
    primeiro = 1;

    infix(r->dir);
}

void posfix(no *r) {
    if (r == NULL) {
        return;
    }

    posfix(r->esq);
    posfix(r->dir);

    if (primeiro)
        printf(" ");

    printf("%c", r->conteudo);
    primeiro = 1;
}

no *busca(no *r, char valor) {
    if (r == NULL) {
        return NULL;
    }

    if (valor == r->chave) {
        return r;
    }

    if (valor < r->chave) {
        return busca(r->esq, valor);
    }
    else {
        return busca(r->dir, valor);
    }
}

void libera(no *r) {
    if (r == NULL) {
        return;
    }

    libera(r->esq);
    libera(r->dir);
    free(r);
}

int main() {
    char comando[10];
    char valor;
    no *r = NULL;

    while (scanf("%s", comando) != EOF) {

        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            r = inserirNo(r, valor);
        }

        else if (strcmp(comando, "INFIXA") == 0) {
            primeiro = 0;
            infix(r);
            printf("\n");
        }

        else if (strcmp(comando, "PREFIXA") == 0) {
            primeiro = 0;
            prefix(r);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0) {
            primeiro = 0;
            posfix(r);
            printf("\n");
        }

        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);

            no *achei = busca(r, valor);

            if (achei != NULL) {
                printf("%c existe\n", valor);
            }
            else {
                printf("%c nao existe\n", valor);
            }
        }
    }

    libera(r);

    return 0;
}