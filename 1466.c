/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : -
Objetivo    : imprimir por níveis
Dificuldade : não entendi como fazer a função de imprimir
Uso de IA   : para entender como fazer a impressão
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    int chave;
    struct cel *esq;
    struct cel *dir;
}no;

typedef struct filaNo {
    no *valor;
    struct filaNo *prox;
} filaNo;


void enfileira (filaNo **fim, filaNo **inicio, no *num){
    filaNo *novo = malloc(sizeof(filaNo));
    novo->valor = num;
    novo->prox = NULL;
    if (*fim == NULL){
        *inicio = novo;
        *fim = novo;
    } else{
        (*fim)->prox = novo;
        *fim = novo;
    }
}

no *desenfileira(filaNo **inicio, filaNo **fim) {
    if (*inicio == NULL) {
        return NULL;
    }

    filaNo *aux = *inicio;
    no *valor = aux->valor;

    *inicio = (*inicio)->prox;

    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(aux);

    return valor;
}

void imprimeNiveis (no *r){
    no *aux;

    if (r == NULL){
        return;
    }

   filaNo *fim = NULL;
   filaNo *inicio = NULL;

   enfileira(&fim, &inicio, r);

   while(inicio != NULL){
        aux = desenfileira (&inicio, &fim);
        printf ("%d", aux->conteudo);

        if (aux->esq != NULL){
            enfileira (&fim, &inicio, aux->esq);
        }

        if (aux->dir != NULL){
            enfileira(&fim, &inicio, aux->dir);
        }

        if (inicio != NULL){
            printf (" ");
        }
        
    }
 
    printf ("\n");
}

no *criaNo (int valor){
    no *novo = malloc(sizeof(no));

    novo->conteudo = valor;
    novo->chave = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

no *inserirFim (no *r, int valor){
    if (r == NULL){
        return criaNo(valor);
    }

    if(valor < r->chave){
        r->esq = inserirFim(r->esq,valor);
    }
    else{
        r->dir = inserirFim(r->dir,valor);
    }

    return r;
}

void destroi (no *r){
    if (r == NULL){
        return;
    }

    destroi (r->esq);
    destroi(r->dir);
    free(r);
}


int main (){
    int C, N, valor;

    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        scanf("%d", &N);

        no *r = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            r = inserirFim(r, valor);
        }

        printf("Case %d:\n", caso);
        imprimeNiveis(r);
        printf("\n");

        destroi(r);
     } 

    return 0;
}