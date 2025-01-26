#include <stdio.h>
#include <stdlib.h>

int somasubseq(int tamanho, int vetor[tamanho], int *k, int *max, int *inicio, int *fim);

int somasubseq(int tamanho, int vetor[tamanho], int *k, int *max, int *inicio, int *fim) {
    max = max + vetor[k];
    if(vetor[k] > max)
        max = vetor[k];
    //se o max anterior for negativo, e o max atual for pra positivo, podemos inicio = k;
    //se o max anterior for maior que o max atual, podemos fim = k - 1;
    somasubseq(tamanho, vetor[tamanho], &(k + 1), &max, &inicio, &fim);
}

int main() {
    int tamanho;
    int max = 0;
    int inicio = 0;
    int fim = 1;
    scanf("%d", &tamanho);
    int *vetor = (int*)malloc(1 * sizeof(int));
    int k = 0;
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    somasubseq(tamanho, vetor[tamanho], &k, &max, &inicio, &fim);
}