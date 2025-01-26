#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#define TAM_PI 1000

typedef struct pilha_ pilha_t;

pilha_t *criar_pilha();
bool esta_vazia(pilha_t *pi);
bool esta_cheia(pilha_t *pi);
bool inserir_elemento(pilha_t *pi, ITEM *x);
bool remover_elemento(pilha_t *pi, ITEM **x);
bool conferir_topo(pilha_t *pi, ITEM **x);
void destruir_pilha(pilha_t** pi);
