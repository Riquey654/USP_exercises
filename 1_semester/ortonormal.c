/******************************************************************************
vetores ortonormais
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void scanear(int n, int num[n]);
void calculo(int n, int num1[n], int num2[n]);

void scanear(int n, int num[n])
{
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
}

void calculo(int n, int num1[n], int num2[n])
{
    int summod1 = 0;
    int summod2 = 0;
    int summult = 0;
    for(int i = 0; i < n; i++) {
        summod1 = summod1 + pow(num1[i], 2);
        summod2 = summod2 + pow(num2[i], 2);
        summult = summult + num1[i] * num2[i];
    }
    int mod1 = sqrt(summod1);
    int mod2 = sqrt(summod2);
    if(mod1 == 1 && mod2 == 1 && summult == 0) {
        printf("sao ortonormais\n");
    }else{
        printf("nao sao ortonormais\n");
    }
}


int main()
{
    int n, *ptr1, *ptr2;
    scanf("%d", &n);
    ptr1 = (int*) malloc(n * sizeof(int));
    if(ptr1 == NULL)
        printf("Sem espaço na memória");
    ptr2 = (int*) malloc(n * sizeof(int));
    if(ptr2 == NULL)
        printf("Sem espaço na memória");
    int num1[n], num2[n];
    scanear(n, num1);
    scanear(n, num2);
    calculo(n, num1, num2);
    free(ptr1);
    free(ptr2);

    return 0;
}
