/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : -
Objetivo    : jogar fora a carta do topo e mover a proxima carta para o fim do deque; apresentar as cartas descartadas e a que restou
Dificuldade : construcao das funcoes
Uso de IA   : utilizei o ChatGPT para explicar como fazer o exercicio
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct dequeNo {
    int valor;
    struct dequeNo *proximo, *anterior;
};

typedef struct deque {
    int tamanho;
    struct dequeNo *frente, *tras;
};

//funcao para inserir no inicio;

void push_front (struct deque *d, int valor;){

    //temos que aumentar o tamanho do deque

    d->tamanho++;

    struct dequeNo *novo = malloc (sizeof(dequeNo));

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = d->frente;

    if (d->frente != NULL){
        d->frente->anterior = novo;
    }

    d->frente = novo;

    if (d->tras == NULL){
        d->tras = novo;
    }

//funcao para inserir no final

void push_back (struct deque *d, int valor){

    d->tamanho++;

    struct dequeNo *novo = malloc(sizeof(dequeNo));

    novo->valor = valor;
    novo-> anterior = d->tras;
    novo->proximo = NULL;

    if (d->tras != NULL){
        d->tras->proximo = novo;
    }

    d->tras = novo;

    if (d->frente==NULL){
        d->frente = novo;
    }
}

//funcao para remover no comeco

void pop_front (struct deque *d){

  if (d->tamanho > 0){

    struct dequeNo *velhafrente = d->frente;

    d->frente = d->frente->proximo;
    d->tamanho--;

    if (d->frente != NULL){
        d->frente->anterior = NULL;
    } else{
        d->tras = NULL;
    }

    free(velhafrente);

  }

}

void pop_back (struct deque *d){

    if (d->tamanho > 0){

        struct dequeNo *velhotras = d->tras;

        d->tras = d->tras->anterior;
        d->tamanho--;

        if (d->tras != NULL){
            d->tras->proximo = NULL;
        }else{
            d->frente = NULL;
        }

        free(velhotras);

    }
}

//qual a primeira carta?

int front (struct deque *d){

    return d->frente->valor;
}

//qual a ultima carta?

int back (struct deque *d){

    return d->tras->valor;
}

//qual é o tamanho do deck?

int size (struct deque *d){

    return d->tamanho;
}

//o deck esta vazio?
//se o deck nao estiver vazio a funcao retorna 0

int empty (struct deque *d){

    return d->tamanho == 0;
}

//inicializando
//o deck deve comecar com zero cartas pois sera preenchido no main

void inicializa (struct deque *d){
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}


//funcao para liberar espaco 
//o free ja esta dentro da funcao pop front

void destroi (struct deque *d){

    while (!empty(d)){
        
        pop_front(d);
    }
}

int main (){
    int n;
    int first;
    struct deque cartas

    while (scanf("%d", &n)){

        if (n == 0){
            break;
        }
        inicializa(&cartas);

        //inserir as cartas

        for (int i = 1; i <= n ; i++){
            push_back(&cartas, i);
        }

        first = 1;

        printf ("discarded cards: ");

        while (size(&cartas) > 1){

            //mostra a carta que sera removida:
        
            if(!first){
                printf (", ");
            } else{
                first = 0;
            }

            printf ("%d", front(&cartas));

            //descartar a primeira:

            pop_front(&cartas);

            //mova a proxima carta para o fim:

            push_back (&cartas, front(&cartas));

            //retire a proxima do topo:

            pop_front (&cartas);
        }
    }

    printf("\n");
    printf ("remaining card: %d\n", front(&cartas));

    destroi(&cartas);

}

return 0;

}

