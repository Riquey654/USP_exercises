/******************************************************************************
fazer um contador para caractere, palavra e linha
a cada caractere, n
a cada espaço, n+2 palavra
if "," ".", +1
a cada  ’\n’, ’\r’ e ’\r\n’ n+1 linha
*******************************************************************************/
#include <stdio.h>

int main()
{
    
    int contadorcaractere = 0, contadorpalavra = 1, contadorlinha = 1;
    char texto;
    char last = ' ';
    //analisar caractere
    while(scanf("%c", &texto) != EOF) {
        if(texto >= 33 && texto <= 126) {
            contadorcaractere++;
        }
        if(texto == ' ' || texto == '\n' || texto == '\r') {
                contadorpalavra++;
                if(last == '\n' || last == '\r'){
                    contadorpalavra--;
                }
        }
        if(texto == '\n') {
            contadorlinha++;
        }
        last = texto;
        
    }
    printf("Caracteres: %d\n", contadorcaractere);
    printf("Palavras: %d\n", contadorpalavra);
    printf("Linhas: %d", contadorlinha);
    

    return 0;
}





