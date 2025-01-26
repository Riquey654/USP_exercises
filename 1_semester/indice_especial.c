
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    int somaantes = 0;
    int somadepois = 0;
    int found = 0;// flag
    
    for(int numescolhido = 0; numescolhido < n; numescolhido++)
        if (numescolhido == 0) {
            for(int i = n - 1; i > numescolhido; i--) {
                somadepois = somadepois + vetor[i];
            }
            if(somadepois == 0) {
                printf("%d ", numescolhido);
                found = 1;
                break;
            }
            
                
        } else if (numescolhido > 0 && numescolhido < n - 1) {
            int somaantes = 0;
            int somadepois = 0;
            for(int i = 0; i < numescolhido; i++)
                somaantes = somaantes + vetor[i];
            for(int i = n - 1; i > numescolhido; i--)
                somadepois = somadepois + vetor[i];
            if(somadepois == somaantes) {
                printf("%d ", numescolhido);
                found = 1;
                break;
            }
                
        } else if(numescolhido == n - 1) {
            for(int i = 0; i < numescolhido; i++) 
                somaantes = somaantes + vetor[i];
            if(somaantes == 0) {
                printf("%d ", numescolhido);
                found = 1;
                break;
            }
                
        }
        
    if(!found)
        printf("-1");
        

    return 0;
}