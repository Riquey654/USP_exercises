#include <stdio.h>

int main(void) {
    
    int n;
    float soma = 0;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        
        if(i % 2 == 1){
        soma = soma + 1.0/i;
        }
        else
        soma = soma - 1.0/i;
        
    }
    printf("%.4f", soma);
    return 0;
}