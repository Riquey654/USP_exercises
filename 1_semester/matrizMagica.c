/******************************************************************************
USAR ALOCAÇÃO DINÂMICA
verificar se é quadrado magico:
    soma da linha == soma da coluna == soma da diagonal
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void calculate(int n, int num[n][n],int linha_soma[n],int coluna_soma[n],int diagonal_soma[2]);
void verify(int n, int linha_soma[n], int coluna_soma[n], int diagonal_soma[2], int contador);

void calculate(int n,int num[n][n],int linha_soma[n],int coluna_soma[n],int diagonal_soma[2]) 
{
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i + j == n - 1) {
            diagonal_soma[1] = diagonal_soma[1] + num[i][j];
            }
            linha_soma[i] = linha_soma[i] + num[i][j];
        }
    }
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            coluna_soma[j] = coluna_soma[j] + num[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        diagonal_soma[0] = diagonal_soma[0] + num[i][i];
    }
}
void verify(int n, int linha_soma[n], int coluna_soma[n], int diagonal_soma[2], int contador)
{
    int mag = linha_soma[0];
    for (int i = 1; i < n; i++) {
        if (linha_soma[i] != mag || coluna_soma[i] != mag) {
            printf("NAO\n");
            return;
        }
    }
    if (diagonal_soma[0] != mag || diagonal_soma[1] != mag) {
        printf("NAO\n");
        return;
    }
    printf("SIM\n");
}

int main()
{
    int n, *ptr;
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    int num[n][n];
    if((ptr = (int*) malloc(n * sizeof(int))) == NULL) {
        printf("SEM MEMÓRIA: ERRO");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int linha_soma[n];
    int coluna_soma[n];
    for(int i = 0; i < n; i++){
        linha_soma[i] = 0;
        coluna_soma[i] = 0;
    }
        
    int diagonal_soma[2];
    diagonal_soma[0] = 0;
    diagonal_soma[1] = 0;
    
    calculate(n, num, linha_soma, coluna_soma, diagonal_soma);
    int contador = 0;
    verify(n, linha_soma, coluna_soma, diagonal_soma, contador);
    free(ptr);
    

    return 0;
}

