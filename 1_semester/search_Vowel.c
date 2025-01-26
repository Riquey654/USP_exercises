/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra [100];
    int contador = 0;
    char vogais[20] = "AEIOUaeiou";
    scanf("%s", palavra);
    for(int i = 0; i < strlen(palavra); i++) {
       if(strchr(vogais, palavra[i]) != NULL) {
           contador++;
       }
    }
    if(contador == 0) 
        printf("A palavra \"%s\" nao contem vogais.", palavra);
    else if(contador > 1)
        printf("A palavra \"%s\" contem %d vogais.", palavra, contador);
    else if(contador == 1)
        printf("A palavra \"%s\" contem 1 vogal.", palavra);
    
    
    return 0;
}
