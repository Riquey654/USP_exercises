#include <stdio.h>

long int equacao(int n, int q, int p);

long int equacao(int n, int q, int p) {
    if(n > 1) {
        long int fator1 = 0, fator2 = 0;
        for(int i = 1; i <= 8; i++) {
            fator1 = fator1 + equacao(n/2, q, p) + i;
        }
        for(int i = 1; i <= q; i++) {
            for(int j = 1; j <= n; j++) {
                fator2 = fator2 + i*j;
            }
        }
        return fator1 + fator2;
        
    }else{
        double fat = 1;
        for(int i = p; i >= 1; i--) {
            fat = fat * i;
        }
        return fat;
    }
}

int main()
{
    int n, q, p;
    long int resultado;
    scanf("%d %d %d", &n, &q, &p);
    resultado = equacao(n, q, p);
    printf("%ld", resultado);

    return 0;
}

