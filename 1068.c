/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : -
Objetivo    : verificar se os parenteses estao corretos utilizando pilhas
Dificuldade : foi complicado entender como fazer a funcao principal
Uso de IA   : utilizei o Codex para procurar erros antes de enviar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhaNo{

    char valor;
    struct pilhaNo *abaixo;

};

typedef struct pilha{

    int tam;
    struct pilhaNo *topo;
};

void push (pilha *p, char valor){
    
    p->tam++;

    struct pilha *novo = malloc(sizeof(pilha));

    novo->valor = valor;
    novo->abaixo = p->topo;

    p->topo = novo;
    
}

void pop (pilha *p){

    if (p->tam > 0){
        struct pilha *velhotopo = p->topo;

        p->topo = p->topo->abaixo;
        p->tam--

        free(velhotopo);

    }
}

char top (struct pilha *p){
    return p->topo->valor;
}

int size (struct pilha *p){
    return p->tam;
}

int empty (struct pilha *p){
    return p->tam == 0;
}

void inicializa (struct pilha *p){
    p->tam = 0;
    p->topo = NULL;
}

void destroi(struct pilha *p){
    while (!empty(p)){
        pop(p);
    }
}

int main (){

    int i, tam;
    struct pilha p;
    char expressao [1001];

    while (scanf("%s\n", &expressao) != EOF){

        inicializa (&p);

        tam = strlen(expressao);

        for (int i = 0; i < tam; i++){
            if (expressao[i] == '('){
                push(&p, '(');
            }

            else if(expressao[i] == ')'){
                if (empty(&p)){
                    break;
                } else{
                     pop(&p);
                }
            }

        }

        if (i = tam && empty(&p)){
            printf("correct\n");
        } else{
            printf ("incorrect\n");
        }

        destroi(&p);
    }

    return 0;
}