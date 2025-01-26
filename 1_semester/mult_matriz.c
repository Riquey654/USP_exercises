#include <stdio.h>

void readD(int *n1, int *m1, int *n2, int *m2);
void readM(int n, int m, int matr[n][m]);
void resultado(int n1, int m1, int n2, int m2, int matrA[n1][m1],int matrB[n2][m2], int matresult[n1][m2]);
void printar(int n1, int m2, int matresult[n1][m2]);

void readD(int *n1, int *m1, int *n2, int *m2)
{
    scanf("%d %d %d %d", n1, m1, n2, m2);
    
}
void readM(int n, int m, int matr[n][m])
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            scanf("%d", &matr[i][j]);
        }
    }
}

void resultado(int n1, int m1,int n2,int m2,int matrA[n1][m1],int matrB[n2][m2],int matresult[n1][m2])
{
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m2; j++) {
            matresult[i][j] = 0;
            for(int k = 0; k < m1; k++) {
                matresult[i][j] = matresult[i][j] + matrA[i][k]*matrB[k][j];
            }
        }
    }
}

void printar(int n1,int m2,int matresult[n1][m2])
{
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m2; j++) {
            printf("%d ", matresult[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n1, m1, n2, m2;
    
    readD(&n1, &m1, &n2, &m2);
    
    if(m1 != n2) {
        printf("Impossível multiplicar matrizes com essas dimensões.");
        return 0;
    }
    
    int matrA[n1][m1], matrB[n2][m2], matresult[n1][m2];
    
    readM(n1,m1,matrA);
    readM(n2,m2,matrB);
    resultado(n1,m1,n2,m2,matrA,matrB,matresult);
    printar(n1,m2,matresult);

    return 0;
}
