#include <stdio.h>

int recursiva(int n, int k);

int recursiva(int n, int k) {
    int resultado;
    int res;
    if(k == 1) {
        resultado = n;
        
        return resultado;
        
    }else{
        if(k % 2 == 0) { //par
            int res = recursiva(n, k/2);
            resultado = res * res;
            resultado = resultado % 1000;
            
            return resultado;
            
        }else{//impar
            
            int res = recursiva(n, k/2);
            resultado = res * res * n;
            resultado = resultado % 1000;
            
            return resultado;
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int resposta;
    resposta = recursiva(n, k);
    printf("%d", resposta % 1000);

    return 0;
}


