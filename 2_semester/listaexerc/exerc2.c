#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    char *vetor = (char*) malloc(1 * sizeof(char));
    int erro = 0;
    for(int i = 0; i < tamanho; i++) {
        scanf(" %c", &vetor[i]);
    }
    char comparador[26];
    for(int i = 0; i < 26; i++) {
        comparador[i] = 65 + i;
    }
    //comparar os dois vetores
    for(int j = 0; j < tamanho; j++) {
        if(vetor[j] != comparador[j]) {
            erro++;
        }
    }
    if(erro == 2 || erro == 0) {
        printf("There are the chance.");
    }else{
        printf("There aren't the chance.");
    }
}