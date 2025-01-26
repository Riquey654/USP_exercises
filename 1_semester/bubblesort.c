#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    for(int k = 0; k < n-1 ; k++) {
        for(int j = n-1; j > k; j--) {
            if(vetor[j] < vetor[j-1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = temp;
            }
        }
    }
    for(int j = 0; j < n; j++) {
        printf("%d ", vetor[j]);
    }

    return 0;
}

