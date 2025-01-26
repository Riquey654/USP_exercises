#include <stdio.h>
#include <string.h>

struct medalha {
    char sigla[4];
    int ouro;
    int prata;
    int bronze;
};

void bubble(int n, struct medalha pais[n]);

void bubble(int n, struct medalha pais[n]) {
    char aux1[4];
    int aux2, aux3, aux4;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(pais[j].ouro < pais[j+1].ouro) {
                strcpy(aux1, pais[j+1].sigla);
                aux2 = pais[j+1].ouro;
                aux3 = pais[j+1].prata;
                aux4 = pais[j+1].bronze;
                strcpy(pais[j+1].sigla, pais[j].sigla);
                pais[j+1].ouro = pais[j].ouro;
                pais[j+1].prata = pais[j].prata;
                pais[j+1].bronze = pais[j].bronze;
                strcpy(pais[j].sigla, aux1);
                pais[j].ouro = aux2;
                pais[j].prata = aux3;
                pais[j].bronze = aux4;
            } else if (pais[j].ouro == pais[j+1].ouro) {
                if (pais[j].prata < pais[j+1].prata) {
                    strcpy(aux1, pais[j+1].sigla);
                    aux2 = pais[j+1].ouro;
                    aux3 = pais[j+1].prata;
                    aux4 = pais[j+1].bronze;
                    strcpy(pais[j+1].sigla, pais[j].sigla);
                    pais[j+1].ouro = pais[j].ouro;
                    pais[j+1].prata = pais[j].prata;
                    pais[j+1].bronze = pais[j].bronze;
                    strcpy(pais[j].sigla, aux1);
                    pais[j].ouro = aux2;
                    pais[j].prata = aux3;
                    pais[j].bronze = aux4;
                } else if (pais[j].prata == pais[j+1].prata) {
                    if (pais[j].bronze < pais[j+1].bronze) {
                        strcpy(aux1, pais[j+1].sigla);
                        aux2 = pais[j+1].ouro;
                        aux3 = pais[j+1].prata;
                        aux4 = pais[j+1].bronze;
                        strcpy(pais[j+1].sigla, pais[j].sigla);
                        pais[j+1].ouro = pais[j].ouro;
                        pais[j+1].prata = pais[j].prata;
                        pais[j+1].bronze = pais[j].bronze;
                        strcpy(pais[j].sigla, aux1);
                        pais[j].ouro = aux2;
                        pais[j].prata = aux3;
                        pais[j].bronze = aux4;
                    }
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    struct medalha pais[n];
    for(int i = 0; i < n; i++) {
        scanf("%s", pais[i].sigla);
        scanf("%d", &pais[i].ouro);
        scanf("%d", &pais[i].prata);
        scanf("%d", &pais[i].bronze);
    }
    //if ouro == ouro
    //comparar prata
    //if prata == prata
    //comparar bronze
    bubble(n, pais);

    for (int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", pais[i].sigla, pais[i].ouro, pais[i].prata, pais[i].bronze);
    }

    return 0;
}
