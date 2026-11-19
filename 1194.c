#include <stdio.h>
#include <string.h>

void posfixo(char prefixo[], char infixo[], int n) {

    if (n == 0) {
        return;
    }

    char raiz = prefixo[0];

    int i;
    for (i = 0; i < n; i++) {
        if (infixo[i] == raiz) {
            break;
        }
    }

    // Percorre a subárvore esquerda
    posfixo(prefixo + 1, infixo, i);

    // Percorre a subárvore direita
    posfixo(prefixo + i + 1, infixo + i + 1, n - i - 1);

    // Imprime a raiz
    printf("%c", raiz);
}

int main() {

    int C, N;
    char prefixo[53], infixo[53];

    scanf("%d", &C);

    while (C--) {

        scanf("%d %s %s", &N, prefixo, infixo);

        posfixo(prefixo, infixo, N);

        printf("\n");
    }

    return 0;
}