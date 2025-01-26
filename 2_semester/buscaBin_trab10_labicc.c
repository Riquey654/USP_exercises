#include <stdio.h>

void twosum(int n, int vetor[], int k);
void PesquisaBinaria (int *flag, int numeroconsultado, int vetor[], int e, int d);


void twosum(int n, int vetor[], int k){
    
    int resultado;
    int flag = 0;
    
    for(int i = 0; i < n; i++) {
        if(flag == 1) {
            printf("S\n");
            return;
        }
        
        if(k < vetor[i]){
            continue;
        }else{
            resultado = k - vetor[i];
            PesquisaBinaria(&flag, resultado, vetor, 0, n);
        }
    }
    printf("N\n");
    return;
}

void PesquisaBinaria (int *flag, int numeroconsultado, int vetor[], int e, int d) {
    int meio = (e + d)/2;
    if (vetor[meio] == numeroconsultado)
        *flag = 1;
    else if (e >= d)                                                                                                                              
        return;
    else
        if (vetor[meio] < numeroconsultado)
            return PesquisaBinaria(flag, numeroconsultado, vetor, meio+1, d);
        else
            return PesquisaBinaria(flag, numeroconsultado, vetor, e, meio-1);
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
  
void heapar(int tamanho, int vetor[tamanho], int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
  
    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
      maior = esquerda;
  
    if (direita < tamanho && vetor[direita] > vetor[maior])
      maior = direita;
  
    if (maior != i) {
      troca(&vetor[i], &vetor[maior]);
      heapar(tamanho, vetor, maior);
    }
}
  
void heapSort(int n, int vetor[n]) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
      heapar(n, vetor, i);
  
    for (int i = n - 1; i >= 0; i--) {
      troca(&vetor[0], &vetor[i]);
  
      heapar(i, vetor, 0);
    }
  }

int main()
{
    int n;
    scanf("%d", &n);
    
    int vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    heapSort(n, vetor);
    
    int q;
    int k;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &k);
        twosum(n, vetor, k);
    }
    

    return 0;
}
