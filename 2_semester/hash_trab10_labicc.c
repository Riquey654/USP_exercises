#include <stdio.h>
#include <stdlib.h>

void hash(int numero, int bucket[]);
void twosum(int n, int bucket[], int vetor[], int k);
void PesquisaHash(int *flag, int resultado, int bucket[]);

void PesquisaHash(int *flag, int resultado, int bucket[]) {
    int temp = resultado % 10000;
    int contador = 0;
    while(1) {
        if(bucket[temp] == resultado) {
            *flag = 1;
            return;
        }else{
            contador++;
            temp++;
        }
        if(contador == 1000) {
            return;
        }
    }
}

void twosum(int n, int bucket[], int vetor[], int k){
    
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
            if(resultado < 0) {
                continue;
            }else{
                PesquisaHash(&flag, resultado, bucket);
            }
        }
    }
    printf("N\n");
    return;
}

void hash(int numero, int bucket[]) {
        int indice = numero % 10000;
        
        while(1) {
            if(bucket[indice] != -1) {
                indice++;
            }else{
                bucket[indice] = numero;
                return;
            }
        }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int *vetor =  malloc(n*sizeof(int));
    int *bucket =  malloc(10000*sizeof(int));
    for(int i = 0; i < 10000; i++) {
        bucket[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        hash(vetor[i], bucket);
        
    }
    
    int q;
    int k;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &k);
        twosum(n, bucket, vetor, k);
    }
    free(vetor);
    free(bucket);
    

    return 0;
}
