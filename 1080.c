int main() {
    
    int v[100];
    int maior, pos;
    
    for (int i = 0; i < 100; i++){
        printf ("digite o %dº valor: ", i + 1);
        scanf ("%d", &v[i]);
    }
    
    maior = v[0];
    pos = 1;
    
    for (int i = 1; i < 100; i++){
        if(v[i] > maior){
            maior = v[i];
            pos = i + 1;
        }
    }
    
    printf ("O maior valor lido = %d\n", maior);
    printf ("A posicao do maior valor = %d\n", pos);
 
    return 0;
}