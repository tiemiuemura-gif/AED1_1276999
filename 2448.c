/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 24/09/2026
Objetivo    : calcular o tempo de entrega das encomendas
Dificuldade : funcao da busca binaria; como calcular o tempo
Uso de IA   : Utilizei o ChatGPT para corrigir
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// mostra a posição da casa que estamos procurando
int BuscaBinaria(int x, int n, int v[]) {
    int e, m, d;

    e = -1;
    d = n;

    while (e < d - 1) {
        m = (e + d) / 2;

        if (v[m] < x)
            e = m;
        else
            d = m;
    }

    return d;
}

int main() {

    int N, M;

    scanf("%d %d", &N, &M);

    int encomendas[M];
    int casas[N];

    // Lê as casas
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }

    // O carteiro começa na primeira casa
    int tempo = 0;
    int casaAtual = 0;

    // Lê as encomendas e calcula o tempo
    for (int i = 0; i < M; i++) {

        scanf("%d", &encomendas[i]);

        int destino = BuscaBinaria(encomendas[i], N, casas);

        tempo += abs(casaAtual - destino);

        casaAtual = destino;
    }

    printf("%d\n", tempo);

    return 0;
}