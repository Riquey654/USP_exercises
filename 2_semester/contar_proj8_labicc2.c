#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct data {
    int dia;
    int mes;
    int ano;
};

typedef struct data DATA;

void merge_sort(long long int *contador, DATA vetores[], int esq, int dir);
void merge(long long int *contador, DATA vetores[], int esq, int meio, int dir);
bool prim_menor_seg(DATA elem1, DATA elem2);


void merge_sort(long long int *contador, DATA vetores[], int esq, int dir) {
    if (esq >= dir) {
            return;
    }else{
            int meio = (esq + dir) / 2;
            merge_sort(contador, vetores, esq, meio);
            merge_sort(contador, vetores, meio + 1, dir);
    
            merge(contador, vetores, esq, meio, dir);
        }
}

void merge(long long int *contador, DATA vetores[], int esq, int meio, int dir) {
        
    DATA *auxiliar = (DATA *)malloc((dir + 1) * sizeof(DATA));
    for (int i = esq; i <= dir; i++) {
        auxiliar[i] = vetores[i];
    }
    
    int i = esq;
    int j = meio + 1;
    int k = esq;
        
    while (i <= meio && j <= dir) {
            
        if (prim_menor_seg(auxiliar[i], auxiliar[j])) {
            vetores[k] = auxiliar[i];
            i++;
        } else {
            vetores[k] = auxiliar[j];
            *contador = *contador + (meio + 1 -(i));
            j++;
        }
        k++;    
    }
    while (i <= meio) {
        vetores[k] = auxiliar[i];
        i++;
        k++;
    }
    while (j <= dir) {
        vetores[k] = auxiliar[j];
        j++;
        k++;
    }
    free(auxiliar);
}

bool prim_menor_seg(DATA elem1, DATA elem2) {
    if(elem1.ano > elem2.ano) {
        return false;
    }else if(elem1.ano == elem2.ano) {
        if(elem1.mes > elem2.mes) {
            return false;
        }else if(elem1.mes == elem2.mes) {
            if(elem1.dia > elem2.dia) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    long long int contador = 0;
    scanf("%d", &n);
    int esq = 0;
    int dir = n - 1;
    DATA *vetores = (DATA*)malloc(n * sizeof(DATA));
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetores[i].dia);
        scanf("%d", &vetores[i].mes);
        scanf("%d", &vetores[i].ano);
    }
    merge_sort(&contador, vetores, esq, dir);
    printf("%lld", contador);
    
    free(vetores);
    

    return 0;
}



