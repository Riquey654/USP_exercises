/******************************************************************************

*******************************************************************************/
#include <stdio.h>

void scanear(int qtd, float num[qtd][2]);
void resultado(int qtd, float num[qtd][2], float multiplicativo);

void scanear(int qtd, float num[qtd][2])
{
    for(int i = 0; i < qtd; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%f", &num[i][j]);
        }
    }
}

void resultado(int qtd, float num[qtd][2], float multiplicativo)
{
    for(int i = 0; i < qtd; i++) {
        for(int j = 0; j < 2; j++) {
            num[i][j] = num[i][j] * multiplicativo;
        }
    }
    for(int i = 0; i < qtd; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%.2f ", num[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int qtd;
    float multiplicativo;
    scanf("%d %f", &qtd, &multiplicativo);
    float num[qtd][2];
    scanear(qtd, num);
    resultado(qtd, num, multiplicativo);

    return 0;
}
