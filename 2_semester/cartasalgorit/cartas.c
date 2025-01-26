#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void cartas(int n) {

    FILA *f = fila_criar();
    ITEM **elementos = (ITEM**)malloc(n * sizeof(ITEM*));
    ITEM *ponteiro;
    int *descarte = (int*) malloc((n - 1) * sizeof(int));
    int controledescarte = 0;
    

    //elementos da fila sendo inseridos
    for(int i = 0; i < n; i++) {
        elementos[i] = item_criar(i+1);
        fila_inserir(f, elementos[i]);
    }

        if(n == 1) {
            printf("Discarded cards:\n");
            ponteiro = fila_remover(f);
            printf("Remaining card: %d\n", item_get_chave(ponteiro));

        }else{
        //fazer um loop até o tamanho da fila ser 1
        while(fila_tamanho(f) != 1) {

            //1 elemento da fila sendo descartado
            ponteiro = fila_remover(f);
            descarte[controledescarte] = item_get_chave(ponteiro);
            item_apagar(&ponteiro);
            controledescarte++;

            //mover 1 para o final da sequencia
            ponteiro = fila_remover(f);
            fila_inserir(f, ponteiro);
        }

        //printar as respostas
        printf("Discarded cards:");
        for(int j = 0; j < n - 2; j++) {
            printf(" %d,", descarte[j]);
        }
        printf(" %d", descarte[n - 2]);

        ponteiro = fila_remover(f);
        printf("\nRemaining card: %d\n", item_get_chave(ponteiro));
        }
    fila_apagar(&f);
    free(elementos);
    free(descarte);   
}