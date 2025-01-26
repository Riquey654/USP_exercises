#include <stdio.h>

struct data {
    int dia;
    int mes;
    int ano;
};

typedef struct data DATA;

void troca(int *elem1, int *elem2);
int contagem_forca_bruta(int n ,DATA vetores[n]);

int contagem_forca_bruta(int n ,DATA vetores[n]) {
    
    int contador = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {//compara com elementos acima dele
            if(vetores[i].ano > vetores[j].ano) {
                contador++;
            }else if(vetores[i].ano == vetores[j].ano) {
                if(vetores[i].mes > vetores[j].mes) {
                    contador++;
                }else if(vetores[i].mes == vetores[j].mes) {
                    if(vetores[i].dia > vetores[j].dia) {
                        contador++;
                    }
                }
            }
        }
    }
    return contador;
}

int main()
{
    int n;
    int mudancas;
    scanf("%d", &n);
    DATA vetores[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &vetores[i].dia, &vetores[i].mes, &vetores[i].ano);
    }
    mudancas = contagem_forca_bruta(n ,vetores);
    printf("%d", mudancas);

    return 0;
}