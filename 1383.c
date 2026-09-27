/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Luiza Tiemi Uemura
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : -
Objetivo    : verificar se o sudoku foi preenchido corretamente
Dificuldade : dificuldade em entender o enunciado; dificuldade em construir o codigo em si
Uso de IA   : utilizei o ChatGPT e o Claude para explicar como escrever esse codigo
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
   int n;
    scanf ("%d\n", &n);

    for (int k = 1; k <= n; k++){
        int m[9][9];
        int valido = 1;

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf ("%d\n", &m[i][j]);
            }
        }

        for (int i = 0; i < 9; i++){
        
            int usado[10] = {0};

            for (int j = 0; j < 9; j++){
            
                int numero = m[i][j];

                if (numero < 1 || numero > 9 || usado[numero] == 1){
                    valido = 0;
                } else { 
                    usado [numero] = 1;
                }
            }
        }

        for (int j = 0; j < 9; j++){ 
        
            int usado[10] = {0};

            for (int i = 0; i < 9; i++){

                int numero = m[i][j];

                if (numero < 1 || numero > 9 || usado[numero] == 1){
                    valido = 0;
                } else { 
                    usado[numero] = 1;
                }
            }

        }
    
        for (int linha = 0; linha < 9; linha += 3){
            for (int coluna = 0; coluna < 9; coluna += 3){
            
                int usado[10] = {0};
            
                for (int i = linha; i < linha + 3; i++){
                    for (int j = coluna; j < coluna + 3; j++){
                    
                        int numero = m[i][j];
                    
                        if (numero > 9 || numero < 1 || usado [numero] == 1){
                            valido = 0;
                        } else {
                        usado[numero] = 1;
                        }
                    }
                }
            }
        }
    
        // Saída
            printf("Instancia %d\n", k);

            if (valido == 1) {
            printf("SIM\n");
            } else {
                printf("NAO\n");
            }

            printf("\n");
        }

    return 0;

}