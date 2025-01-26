#include <stdio.h>

void acharsequencial(int n, int vetor[], int numeroconsultado);


int main()
{
    int n;
    int q, numeroconsultado;
    scanf("%d", &n); //numeros a serem lidos
    int vetor[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);//numeros sendo lidos
    }
    
    scanf("%d", &q);//numeros de consultas
    for(int i = 0; i < q; i++) {
        scanf("%d", &numeroconsultado);
        
        acharsequencial(n, vetor, numeroconsultado);//funcaoAcharSequencial
    }

    return 0;
}

void acharsequencial(int n, int vetor[], int numeroconsultado) {
    int flag = 0;
    for(int h = 0; h < n; h++) {
        if(vetor[h] == numeroconsultado) {
            flag = 1;
        }
    }
    if(flag == 1) {
        printf("Presente\n");
    }else{
        printf("Ausente\n");
    }
    
}
