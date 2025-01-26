#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item_ ITEM;

celula *item_criar(int prioridade, int hora, int min, int sec, char *descricao);
bool item_apagar(celula **item);
//void item_imprimir(ITEM *item);
int item_get_prioridade(celula *item);
int item_get_tempoemsegundo(celula *item);
//bool item_set_definicao(ITEM *item, char *definicao);

#endif