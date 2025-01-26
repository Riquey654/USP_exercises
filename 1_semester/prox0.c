/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* memaloc(int n);
void near0(int n, int num[n]);

//funcao de alocar mem
int* memaloc(int n)
{
    int *ptr;
    ptr = (int*) malloc(n * sizeof(int));
    if(ptr == NULL)
        printf("Erro ao alocar memória");
    return ptr;
}
//funcao para resolver o problema
//variavel que guarda o menor número
//Além disso, mostrar a posicao
void near0(int n, int num[n])
{
    int modnum[n];
    for(int i = 0; i < n; i++) {
        modnum[i] = fabs(num[i]);
    }
    int menornum = 999;
    int menorindice = 0;
    for(int i = 0; i < n; i++) {
        if(menornum > modnum[i]) {
            menornum = modnum[i];
            menorindice = i;
        }
    }
    printf("%d\n",num[menorindice]);
    for(int i = 0; i < n; i++) {
        if(menornum == modnum[i])
            printf("%d ",i);
    }
    printf("\n");
}

int main()
{
    int n, *ptr;
    scanf("%d", &n);
    ptr = memaloc(n);
    int num[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    near0(n, num);
    free(ptr);
    return 0;
}
