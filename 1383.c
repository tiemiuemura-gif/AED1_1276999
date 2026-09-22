#include <stdio.h>

int main (){
   
    int n;
    scanf ("%d\n", &n);

    for (int k = 1; k <= n; k++){
        int m[9][9];
        int valido = 1;
    }

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

            }

            usado [numero] = 1;

        }
    }

    for (int j = 0; j < 9; j++){ 
        
        int usado[10] = {0};

        for (int i = 0; i < 9; i++){

            int numero = m[j][i];

            if (numero > 9 || numero < 1 || usado[numero] == 1){

                valido = 0;

            }

            usado[numero] = 1;

        }

    }

    
}