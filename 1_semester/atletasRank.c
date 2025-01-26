#include <stdio.h>

void preencher(int vetor[], int tamanho);
void bubble(int vetor[], int rank[], int tamanho);
void ranquear(int rank[], int vetor[], int lugar[], int tamanho);

void preencher(int vetor[], int tamanho)
{
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

void bubble(int vetor[], int rank[], int tamanho)
{
    for(int h = 0; h < tamanho; h++) {
        rank[h] = vetor[h];
    }
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho - 1; j++) {
            if(rank[j] < rank[j + 1]) {
                int temp = rank[j];
                rank[j] = rank[j + 1];
                rank[j + 1] = temp;
            }
                
        }
    }
}

void ranquear(int rank[], int vetor[], int lugar[], int tamanho) 
{
    for(int i = 0; i < tamanho; i++) {
        for(int k = 0; k < tamanho; k++) {
            if(vetor[i] == rank[k])
                lugar[i] = k + 1;
            
        }
            
    }
    
}


int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    
    int vetor[tamanho];
    int rank[tamanho];
    int lugar[tamanho];
    
    preencher(vetor, tamanho);
    
    bubble(vetor, rank, tamanho);
    
    ranquear(rank, vetor, lugar, tamanho);
    
    for(int i = 0; i < tamanho; i++)
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i + 1, vetor[i], lugar[i]);

    return 0;
}
