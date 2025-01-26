#include <stdio.h>
#include <stdlib.h>

//while n > k, divide.
//apos isso, usar insertion sort
//depois, dar um merge

void mergesort(int vetor[], int esquerda, int direita, int k);
void merge(int vetor[], int esquerda, int meio, int direita);
void insertsort(int n, int v[n]);
void print(int n, int vetor[n]);

void mergesort(int vetor[], int esquerda, int direita, int k) {
    if(esquerda >= direita) {
        insertsort(direita, vetor);
        print(direita, vetor);
    }else{
        int meio = ((direita + esquerda)/2);
        mergesort(vetor, esquerda, meio, k);
        mergesort(vetor, meio + 1, direita, k);
        merge(vetor, esquerda, meio, direita);
    }

}
void merge(int vetor[], int esquerda, int meio, int direita) {
        
    // transfere os elementos entre esquwerda e direita para um array auxiliar.
    int aux[direita - esquerda];
    for (int i = esquerda; i <= direita; i++) {
        aux[i] = vetor[i];
    }
        
        
    int i = esquerda;
    int j = meio + 1;
    int k = esquerda;
        
    while (i <= meio && j <= direita) {
            
        if (aux[i] <= aux[j]) {
            vetor[k] = aux[i];
            i++;
        } else {
            vetor[k] = aux[j];
            j++;
        }
        k++;    
            
    }
        
    // se a metade inicial não foi toda consumida, faz o append.
    while (i <= meio) {
        vetor[k] = aux[i];
        i++;
        k++;
    }
        
    // se a metade final não foi toda consumida, faz o append.
    while (j <= direita) {
        vetor[k] = aux[j];
        j++;
        k++;
    }

}
void insertsort(int n, int vetor[n]) {
    int i, j, chave;
    for(i = 1; i < n; i++) {
        chave = vetor[i];
        //comparar com os elementos anteriores
        j = i - 1;
        while(j >= 0 && chave < vetor[j]) {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;

    }
}

void print(int n, int vetor[n]) {
    for(int i = 0; i < 0; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int k;
    scanf("%d", &k);

    int direita, esquerda;
    esquerda = 0;
    direita = n - 1;
    mergesort(vetor, esquerda, direita, k);

}