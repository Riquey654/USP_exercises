/******************************************************************************
ler n, qtd de termos
ler primeiro termo e razão da sequencia
PA, PG
*******************************************************************************/
#include <stdio.h>

int main()
{
    float n, primeiro, razao;
    float first;
    int i = 1;
    int h = 1;
    scanf("%f", &n);
    scanf("%f %f", &primeiro, &razao);
    first = primeiro;
    printf("PA: %.3f ", primeiro);
    while(n > i) {
        primeiro = primeiro + razao;
        printf("%.3f ", primeiro);
        i++;
    }
    
    printf("\nPG: %.3f ", first);
    while(n > h) {
        first = first*razao;
        printf("%.3f ", first);
        h++;
    }

    return 0;
}

