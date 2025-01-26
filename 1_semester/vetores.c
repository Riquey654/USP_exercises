#include <stdio.h>

int main()
{
    int x, y;
    int l = 0;
    int n = 0;
    int k = 0;
    scanf("%d %d", &x, &y);
    int vetor1[x], vetor2[y], vetor3[x+y];
    for(int i = 0; i <= x - 1; i++) {
        scanf("%d", &vetor1[i]);
    }
    for(int j = 0; j <= y - 1; j++) {
        scanf("%d", &vetor2[j]);
        
        
    }
    while(l < x && n < y) {
        vetor3[k++] = vetor1[l++];
        vetor3[k++] = vetor2[n++];
    }
    while (l < x) {
        vetor3[k++] = vetor1[l++];
    }

    while (n < y) {
        vetor3[k++] = vetor2[n++];
    }

    for(int h = 0; h <= x + y - 1; h++) {
        printf("%d ", vetor3[h]);
    }
    
    
    return 0;
}

