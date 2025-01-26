/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
    int intervalomenor, intervalomaior;
    int soma = 0;
    scanf("%d",&n);
    int vetor[n];
    for(int i = 0; i <= n-1; i++) {
        scanf("%d", &vetor[i]);
    }
    scanf("%d %d",&intervalomenor, &intervalomaior);
    for(int k = intervalomenor; k <= intervalomaior; k++) {
        soma = soma + vetor[k];
    }
    printf("%d\n", soma);

    return 0;
}
