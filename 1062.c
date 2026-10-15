
#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {

        while (1) {
            int desejado[1000];
            int pilha[1000];
            int topo = -1;

            scanf("%d", &desejado[0]);

            if (desejado[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &desejado[i]);
            }

            int entrada = 1;
            int saida = 0;

            while (saida < N) {

                if (topo >= 0 && pilha[topo] == desejado[saida]) {
                    topo--;
                    saida++;
                }
                else if (entrada <= N) {
                    pilha[++topo] = entrada;
                    entrada++;
                }
                else {
                    break;
                }
            }

            if (saida == N) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }

    return 0;
}
