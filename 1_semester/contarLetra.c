#include <stdio.h>
#include <stdlib.h>
#define TAM 20

char *aloc(int *tam);

char *aloc(int *tam) {
    
    char c;
    char *nome = NULL;
    do {
        c = getchar(); //le o caracter
        //e se o caracter for #
        if(c == EOF) {
            c = getchar();
            break;
        }
        //tem espaco suficiente?
        if(*tam % TAM == 0) {
            nome = (char*)realloc(nome,(1 + *tam + TAM));
        }
        if(nome == NULL) {
            printf("Alocação mal sucedida");
            exit(0);
        }
            
        nome[(*tam)++] = c;
    }while(1); //loop eterno
    nome[*tam] = '\0';
    return nome;
}


int main()
{
    int contador[26] = {0};
    int tam = 0;
    char letras[26];
    char *nome = aloc(&tam);
    for(int i = 0; i < 26; i++) {
        letras[i] = 97 + i;
    }
    for(int i = 0; i < tam; i++) {
        if(nome[i] == ' ')
            i++;
        for(int j = 0; j < 26; j++) {
            if(nome[i] == 65 + j || nome[i] == 97 + j) {
                contador[j]++;
            }
        }
    }
    for(int i = 0; i < 26; i++) {
        
        if(contador[i] > 0)
            printf("%c: %d\n", letras[i], contador[i]);
    }
    free(nome);
    
    return 0;
}



