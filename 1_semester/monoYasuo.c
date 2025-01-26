#include <stdio.h>

void check(int m, int n,char cadeira[m][n], int *contador);
void resultado(int m, int n,char cadeira[m][n], int contador);

void check(int m, int n,char cadeira[m][n], int *contador)
{
    *contador = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(cadeira[i][j] == 'c') {
                for(int k = 0; k < m; k++) {
                    cadeira[k][j] = 'x';
                }
                for(int k = 0; k < n; k++) {
                    if(cadeira[i][k] != 'c')
                        cadeira[i][k] = 'x';
                }
            }
            if(cadeira[i][j] == 'f')
                cadeira[i][j] = 'x';
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(cadeira[i][j] == 'v') {
                cadeira[i][j] = 'o';
                (*contador)++;
            }
        }
    }
}

void resultado(int m, int n,char cadeira[m][n], int contador) 
{
    if(contador == 0) {
        printf("Eh um dia triste para os mono Yasuo");
    }else{
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c ", cadeira[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char cadeira[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &cadeira[i][j]);
        }
    }
    int contador;
    check(m, n,cadeira,&contador);
    resultado(m, n,cadeira,contador);

    return 0;
}


