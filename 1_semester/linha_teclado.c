/******************************************************************************
usar strchr
while char != EOF
função pra scanear as palavras, cada palavra tem no max 100 letras
usar strchr
verificar com 3 ifs as tres linhas possiveis
se for possivel, imprime palavra
se nao for possivel escrever com nenhuma das linhas, nao imprime
*******************************************************************************/
#include <stdio.h>
#include <string.h>

char esta_naLinha (char *palavra , char *ponteiro1, char *ponteiro2,char *ponteiro3);

char esta_naLinha (char *palavra , char *ponteiro1, char *ponteiro2,char *ponteiro3)
{
    char *ponteiro1;
    char *ponteiro2;
    char *ponteiro3;
    ponteiro1 = strchr(palavra, "asdfghjklzxcvbnm");
    ponteiro2 = strchr(palavra, "qwertyuiopasdfghjkl");
    ponteiro3 = strchr(palavra, "qwertyuiopzxcvbnm");
    
}


int main()
{
    char palavra[100];
    while(scanf("%s", palavra) != EOF) {
        
        char *ponteiro1, *ponteiro2, *ponteiro3;
        char esta_naLinha (palavra , ponteiro1, ponteiro2, ponteiro3);
        
        if(ponteiro1 == NULL) {
        printf("%s", palavra);
        }
        if(ponteiro2 == NULL) {
            printf("%s", palavra);
        }
        if(ponteiro3 == NULL) {
            printf("%s", palavra);
        }
    }

    return 0;
}

