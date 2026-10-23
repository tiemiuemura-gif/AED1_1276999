/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : -
Objetivo    : contar cobaias
Dificuldade : médio. Tive dificuldade com o for
Uso de IA   : usei a IA para corrigir meu código
-------------------------------------------------------------------------- */

#include <stdio.h>

int main (){
    int N, Quantia;
    char Tipo;
    int coelhos = 0, ratos = 0, sapos = 0;
    int total = 0;
    double pc, ps, pr;

    scanf ("%d", &N);

    for (int i = 0; i < N; i++){

        scanf ("%d %c", &Quantia, &Tipo);

        if (Tipo == 'C'){
            coelhos += Quantia;
        }
        else if (Tipo == 'S'){
            sapos += Quantia;
        }
        else if (Tipo == 'R'){
            ratos += Quantia;
        }
    }

    total = ratos + coelhos + sapos;

    pc = ((double) coelhos / total) * 100;
    ps = ((double) sapos / total) * 100;
    pr = ((double) ratos / total) * 100;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);

    printf("Percentual de coelhos: %.2f %%\n", pc);
    printf("Percentual de ratos: %.2f %%\n", pr);
    printf("Percentual de sapos: %.2f %%\n", ps);

    return 0;
  
}