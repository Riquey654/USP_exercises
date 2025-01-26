#include <stdio.h>
#include <string.h>

//scanear texto e substring
void scanear(char frase[999],char palavra[30]);
void encontrar(char frase[999],char palavra[30], char **ponteiro);

void scanear(char frase[999],char palavra[30])
{
    scanf("%[^\n]s\n", frase);
    scanf("%s", palavra);
    
}

void encontrar(char frase[999],char palavra[30], char **ponteiro)
{
    *ponteiro = strstr(frase, palavra);
}

int main()
{
    char frase[999];
    char palavra[30];
    char *ponteiro;
    
    scanear(frase, palavra);
    encontrar(frase, palavra, &ponteiro);
    
    if(ponteiro != NULL) {
        while(ponteiro != NULL) {
            printf("\nA sub string foi encontrada na posicao = %ld", ponteiro - frase);
            ponteiro = strstr(ponteiro + strlen(palavra), palavra);
        }
    }else{
        printf("\nA sub string nao foi encontrada");
    }
    return 0;
}
