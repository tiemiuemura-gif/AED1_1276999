/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : c
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 27/09/2026
Objetivo    : transforma uma expressao numerica infixa em posfixa
Dificuldade : entender como fazer essa conversao utilizando pilhas
Uso de IA   : utilizei para entender como aplicar as funcoes na funca principal
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dequeNo{
    char valor;
    struct dequeNo *prox;
}dequeNo;

typedef struct deque{
    int tam;
    struct dequeNo *topo;
}deque;

//inserir um valor na pilha
void push (char valor, deque *p){

   struct dequeNo *novo = malloc(sizeof(dequeNo));

   novo->valor = valor;
   novo->prox = p->topo;

   p->topo = novo;

   p->tam++;
}

char pop (deque *p){

    dequeNo *velhotras = p->topo;
    char valor = velhotras->valor;

    p->topo = p->topo->prox;
    p->tam--;

    free(velhotras);

    return valor;
}

void inicializa (deque *p){
    p->tam = 0;
    p->topo = NULL;
}

int size (deque *p){
    return p->tam;
}

char topo (deque *p){
    return p->topo->valor;
}

void lixo (deque *p){
    if (p->tam != 0){
        pop(p);
    }
}

int empty(deque *p) {
    return p->tam == 0;
}

int prioridade (char op){

    switch(op){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        
        default:
            return 0;
    }
}

int main (){
    int N;
    char exp[301];
    
    scanf ("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {

        fgets(exp, 301, stdin);

        int tam = strlen(exp);

        if (exp[tam - 1] == '\n') {
        exp[tam - 1] = '\0';
        }

        deque p;
        inicializa(&p);

        for (int j = 0; exp[j] != '\0'; j++) {

            char atual = exp[j];

            // letra ou número
            if ((atual >= 'A' && atual <= 'Z') ||
                (atual >= 'a' && atual <= 'z') ||
                (atual >= '0' && atual <= '9')) {

                printf("%c", atual);
            }

            // abre parênteses
            else if (atual == '(') {

                push(atual, &p);
            }

            // fecha parênteses
            else if (atual == ')') {

                while (!empty(&p) && topo(&p) != '(') {

                    printf("%c", pop(&p));
                }

                // remove o '('
                if (!empty(&p)) {
                    pop(&p);
                }
            }

            // operador
            else {

                while (!empty(&p) &&
                       topo(&p) != '(' &&
                       prioridade(topo(&p)) >= prioridade(atual)) {

                    printf("%c", pop(&p));
                }

                push(atual, &p);
            }
        }

        // esvazia a pilha
        while (!empty(&p)) {

            printf("%c", pop(&p));
        }

        printf("\n");
    }

    return 0;
}