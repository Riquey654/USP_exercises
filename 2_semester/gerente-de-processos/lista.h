//duas listas ordenadas, uma de tempo, outra de prioridade
//a lista de tempo remove o primeiro elemento(menor tempo)
//a lista de prioridade remove o ultimo elemento(maior prioridade)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "item.h"

typedef struct no no_t;
typedef struct lista lista_t;

lista_t *criar_lista();
bool esta_vazia(lista_t *l);
int tamanho(lista_t *l);
void destruir_lista(lista_t **l);
no_t *busca(lista_t *l, celula *x);
bool inserir_prioridade(lista_t *l, celula *x);
bool inserir_horario(lista_t *l, celula *x);
bool remover(lista_t *l, celula *x);
void imprimir(lista_t *l);
celula *retorna_inicio(lista_t *l);
