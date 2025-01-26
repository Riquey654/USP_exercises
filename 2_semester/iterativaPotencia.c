#include <stdio.h>

int iterativa(int n, int k);

int iterativa(int n, int k) {
    long int resultado = 1;
    for(int i = 0; i < k; i++) {
        resultado = resultado * n;
        resultado = resultado % 1000;
    }
    return resultado;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int resposta;
    resposta = iterativa(n, k);
    printf("%ld", resposta % 1000);

    return 0;
}

