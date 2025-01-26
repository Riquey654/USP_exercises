/*
soma das dezenas é igual à raiz quadrada do número
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int dez1;
    float dez2, raiz;
    for(int num = 1000;num < 10000; num++){
        dez1 = num/100;
        dez2 = num - (dez1*100);
        raiz = sqrt(num);
        if(raiz == dez1 + dez2){
            printf("%d\n", num);
        }
    }

    return 0;
}
