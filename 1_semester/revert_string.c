#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20
char *aloc(char *nome, int tam);
void revert(char *nome, int tam);


char *aloc(char *nome, int tam) {
    char c;
    do {
        c = getchar(); //le o caracter
        //e se o caracter for #
        if(c == EOF) {
            c = getchar();
            break;
        }
        //tem espaco suficiente?
        if(tam % TAM == 0) {
            nome = (char*)realloc(nome,(1 + tam + TAM));
        }
        nome[tam++] = c;
    }while(1); //loop eterno
    nome[tam] = '\0';
    return nome;
}

void revert(char *nome, int tam) {
    for(int i = tam - 1; i >= 0; i--) {
        printf("%c", nome[i]);
    }
}
    

int main()
{
    char *nome = NULL;
    int tam = 0;
    char *str = aloc(nome, tam);
    revert(str, strlen(str));
    free(str);
    return 0;
}
