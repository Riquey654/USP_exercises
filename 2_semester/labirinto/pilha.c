#include "pilha.h"


struct pilha_{
    int topo;
    ITEM* elementos[TAM_PI];
};

pilha_t *criar_pilha(){

    pilha_t *pi;
    pi = (pilha_t*)malloc(sizeof(pilha_t));
    pi->topo = -1;
    return pi;

}

bool esta_vazia(pilha_t *pi) {
    if(pi->topo == -1) {
        return true;
    }else{
        return false;
    }

}
bool esta_cheia(pilha_t *pi) {
    if(pi->topo == TAM_PI-1) {
        return true;
    }else{
        return false;
    }

}
bool inserir_elemento(pilha_t *pi, ITEM *x) {

    if(!esta_cheia(pi)) {
        pi->topo++;
        pi->elementos[pi->topo] = x;
        return true;
    }else{
        return false;
    }

}
bool remover_elemento(pilha_t *pi, ITEM **x) {
    if(!esta_vazia(pi)) {
        *x = pi->elementos[pi->topo];
        pi->topo--;
        return true;
    }else{
        return false;
    }
}
bool conferir_topo(pilha_t *pi, ITEM **x) {
    if(!esta_vazia(pi)) {
        *x = pi->elementos[pi->topo];
        return true;
    }else{
        return false;
    }
}
void destruir_pilha(pilha_t **pi) {
    while((*pi)->topo != -1) {
        ITEM* itemaux;
        remover_elemento(*pi, &itemaux);
        item_apagar(&itemaux);
    }
    free(*pi);
    *pi = NULL;
}