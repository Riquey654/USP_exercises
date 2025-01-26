/******************************************************************************
DCT II
DCT(x0) = xn.cos.(pi/N (n+1/2).k)
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float soma = 0;
    float dct;
    scanf("%d", &n);
    float vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%f", &vetor[i]);
    }
    //é necessario fazer uma soma dos cossenos
    //primeiro, irei fazer um for para mudar o valor de n.
    for(int k = 0; k < n; k++) {
        for(int j = 0; j <= n-1; j++) {
            dct = vetor[j] * cos(M_PI/n * (j + 1.0/2.0) * k);
            soma = soma + dct;
        }
        printf("%.4f\n", soma);
        soma = 0;
    }
    

    return 0;
}
