/******************************************************************************
Criptografia
*******************************************************************************/
#include <stdio.h>

int main()
{
    char texto [100000];
    int contcaractere = 1;
    int contlinha = 1;
    for(int i = 0; i <= 99999; i++) {
        scanf("%c", &texto[i]);
        if(texto[i] >= 65 && texto[i] <= 90) {
            texto[i] = texto[i] + contcaractere;
            texto[i] = texto[i] * 
        }
        
    }
    
    return 0;
}
