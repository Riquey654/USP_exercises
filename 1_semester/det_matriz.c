#include <stdio.h>

void scanear(int n, int numero[n][n]);
int determinante(int n, int numero[n][n]);

void scanear(int n, int numero[n][n])
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &numero[i][j]);
        }
    }
}

int determinante(int n,int numero[n][n])
{
    int det = 0;
    if(n == 1) {
        det = numero[n-1][n-1];
    }
    if(n == 2) {
        det = numero[0][0]*numero[1][1] - numero[1][0]*numero[0][1];
    }
    if(n == 3) {
        det = (numero[0][0]*numero[1][1]*numero[2][2] + numero[0][1]*numero[1][2]*numero[2][0] + numero[1][0]*numero[2][1]*numero[0][2]) - (numero[0][2]*numero[1][1]*numero[2][0] + numero[0][0]*numero[2][1]*numero[1][2] + numero[0][1]*numero[1][0]*numero[2][2]);
    }

    return det;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int numero[n][n];
    scanear(n, numero);
    int resultado = determinante(n, numero);
    printf("%d", resultado);

    return 0;
}
