/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int main()
{
    char palavra [100];
    int contador = 0;
    scanf("%s", palavra);
    for(int i = 0; i < 100; i++) {
        if(palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U' || palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o'|| palavra[i] == 'u') {
            contador++;
        }
    }
    printf("%d\n", contador);
    
    return 0;
}
