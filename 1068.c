#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {

        // Aloca as 9 linhas
        int **matriz = (int **) malloc(9 * sizeof(int *));

        // Aloca as 9 colunas de cada linha
        for (int i = 0; i < 9; i++) {
            matriz[i] = (int *) malloc(9 * sizeof(int));
        }

        // Lê a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int valido = 1;

        // Verifica as linhas
        for (int i = 0; i < 9; i++) {
            int usado[10] = {0};

            for (int j = 0; j < 9; j++) {
                int valor = matriz[i][j];

                if (valor < 1 || valor > 9 || usado[valor] == 1) {
                    valido = 0;
                }

                usado[valor] = 1;
            }
        }

        // Verifica as colunas
        for (int j = 0; j < 9; j++) {
            int usado[10] = {0};

            for (int i = 0; i < 9; i++) {
                int valor = matriz[i][j];

                if (valor < 1 || valor > 9 || usado[valor] == 1) {
                    valido = 0;
                }

                usado[valor] = 1;
            }
        }

        // Verifica os blocos 3x3
        for (int linha = 0; linha < 9; linha += 3) {
            for (int coluna = 0; coluna < 9; coluna += 3) {

                int usado[10] = {0};

                for (int i = linha; i < linha + 3; i++) {
                    for (int j = coluna; j < coluna + 3; j++) {

                        int valor = matriz[i][j];

                        if (valor < 1 || valor > 9 || usado[valor] == 1) {
                            valido = 0;
                        }

                        usado[valor] = 1;
                    }
                }
            }
        }

        // Saída
        printf("Instancia %d\n", instancia);

        if (valido == 1) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        // Libera cada linha
        for (int i = 0; i < 9; i++) {
            free(matriz[i]);
        }

        // Libera o vetor de ponteiros
        free(matriz);
    }

    return 0;
}