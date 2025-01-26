/*
numero desaparecido
scanear n 
scanear numeros(n-1 números)
ordenar por bubble sort
criar uma variavel h que recebe n. Enquanto h + 1 == vetor[h]
h--
printf(h+1)
*/
#include <stdio.h>

void preenche(int vetor[], int tamanho);
void bubble_sort(int vetor[], int tamanho);
int desaparecido(int vetor[], int tamanho);

void preenche(int vetor[], int tamanho)
{
    for(int i = 0; i < tamanho - 1; i++) {
        scanf("%d", &vetor[i]);
    }
}


void insertion_sort(int vetor[], int tamanho)
{
    int j, atual;
    for(int i = 1; i < tamanho; i++) {
        atual = vetor[i];
        j = i - 1;
        while(j >= 0 && atual < vetor[j]) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = atual;
    }
}
/*criar uma variavel h que recebe n. Enquanto h + 1 == vetor[h]h--printf(h+1)*/
int desaparecido(int vetor[], int tamanho)
{
    int h = tamanho;
    while(h == vetor[h - 2]) {
        h--;
    }
    return h;
}

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho - 1];
    preenche(vetor, tamanho);
    insertion_sort(vetor, tamanho - 1);
    desaparecido(vetor, tamanho);
    int num = desaparecido(vetor, tamanho);
    
    
    
    printf("Numero desaparecido: %d", num);
    return 0;
}

