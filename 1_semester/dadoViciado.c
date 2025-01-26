/******************************************************************************
Dado viciado
ler com scanf dentro de um loop uma qtd indeterminada de numeros, ate num = EOF.
identificar qual numero aparece mais vezes
 --comparar os contadores e identidficar maior 
     ---contador maior = 0
     ---if(contador1 > contadormaior,  contadormaior = contador1)
        if(6 vezes)
        if contadormaior == contador1 || contadormaior == contador2 || contadormaior == contador3
        || contadormaior == contador4 || contadormaior == contador5 || contadormaior == contador6 || 
e printar o que mais aparece e quantas vezes.
Caso forem 2, printar os 2 e quantas vezes apareceram
*******************************************************************************/
#include <stdio.h>

int main()
{
    int num;
    int numeros [6] = {0};
    int maior = 0;
    
    while(scanf("%d", &num) != EOF) {
        numeros[num-1]++;
    }
    if(numeros[0] > maior)
        maior = numeros[0];
    if(numeros[1] > maior)
        maior = numeros[1];
    if(numeros[2] > maior)
        maior = numeros[2];
    if(numeros[3] > maior)
        maior = numeros[3];
    if(numeros[4] > maior)
        maior = numeros[4];
    if(numeros[5] > maior)
        maior = numeros[5];
    for(int i = 0; i < 6; i++) {
        if (numeros[i] == maior)
        printf("%d\n", i+1);
    }
    printf("%d", maior);
       
    return 0;
}

