/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1191
Data        : .
Objetivo    : reconstruir posfix
Dificuldade : a funcao principal
Uso de IA   : para corrigir o texto
-------------------------------------------------------------------------- */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char conteudo;
    struct cel *esq;
    struct cel *dir;
} no;

no *criaNo(char texto) {
    no *novo = malloc(sizeof(no));

    novo->conteudo = texto;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

no *reconstruir (char prefixo[], char infixo[], int inicio, int fim, int *pos){
     
    if (inicio > fim){
        return NULL;
    }

    char raiz = prefixo[*pos];
    (*pos)++;

    no *novo = criaNo(raiz);

    int meio = inicio;

    if (infixo[meio] != raiz){
        meio++;
    }

    novo->esq = recostruir(prefixo,infixo, inicio, meio - 1, pos);
    novo->dir = reconstruir(prefixo,infixo, meio + 1, fim, pos);

    return novo;
}


void posfix(no *r) {
    if (r == NULL) {
        return;
    }

    posfix(r->esq);
    posfix(r->dir);

    printf("%c", r->conteudo);
}

int main() {
    char prefix[27], infix[27];

    while (scanf("%s %s", prefix, infix) == 2) {

        int pos = 0;
        int inicio = 0;
        int fim = strlen(infix) - 1;

        no *raiz = reconstruir(prefix, infix,
                               inicio, fim, &pos);

        posfix(raiz);
        printf("\n");
    }

    return 0;
}