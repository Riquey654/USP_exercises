/******************************************************************************
transposicao de matriz
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void scan(int n, int m, int matr[m][n]);
void transp(int n, int m, int matr[n][m]);


void scan(int n, int m, int matr[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

void transp(int n, int m, int matr[n][m]) 
{
    int newmatr[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            newmatr[i][j] = matr[j][i];
            if(newmatr[i][j] < 10)
                printf(" %d ", newmatr[i][j]);
            else
                printf("%d ", newmatr[i][j]);
        }
        printf("\n");
    }

}



int main()
{
    int n, m, **ptr;
    scanf("%d %d", &n, &m);
    ptr = (int**) malloc(n * sizeof(int*));
    if(ptr == NULL)
        printf("Erro na alocação de memória");
    for(int i = 0; i < n; i++) {
        ptr[i] = (int*) malloc(m * sizeof(int));
        if(ptr[i] == NULL)
            printf("Erro na alocação de memória");
    }
    int matr[n][m];
    scan(n, m, matr);
    transp(n, m, matr);
    
    for(int i = 0; i < n; i++)
        free(ptr[i]);
    free(ptr);

    return 0;
}
