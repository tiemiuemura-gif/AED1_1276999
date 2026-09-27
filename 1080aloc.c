/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : -
Objetivo    : descobrir o maior valor e a sua posicao (com alocacao dinamica) 
Dificuldade : Nao senti dificuldade nesse exercicio
Uso de IA   : Nao foi usado
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main (){
    int *v;

    v = 100 * malloc(sizeof(int));

    for (int i = 0; i < 100; i++){
        scanf ("%d", &v[i]);
    }
    
    int maior = v[0];
    int posmaior = 1;

    for (int i = 0; i < n; i++){
        if (v[i] > maior){
            maior = v[i];
            pos = i + 1;
        }
    }

    printf ("%d\n", maior);
    printf ("%d\n", posmaior);

    free(vetor);

    return 0;
}