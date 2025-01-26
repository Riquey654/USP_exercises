#include <stdio.h>


void verificarprimo(int numero);

void verificarprimo(int numero) {
    int contadordivisores = 0;
    for(int j = 2; j <= numero; j++) {
        if((numero % j) == 0) {
            contadordivisores++;
        }
    }
    if(contadordivisores == 1)
        printf("%d e um numero primo\n", numero);
    else
        printf("%d nao e um numero primo\n", numero);
}


int main()
{
    int num[100];
    int i = 0;
    while((scanf("%d",&num[i])) != EOF) {
        
        //checar se é primo
        verificarprimo(num[i]);
        
        i++;
    }

    return 0;
}
