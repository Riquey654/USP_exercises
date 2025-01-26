#include "item.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hh;
    int mm;
    int ss;
} horario;

typedef struct {
    int prior;
    horario chegada;
    char descricao[51];
} celula;

celula *item_criar(int prioridade, int hora, int min, int sec, char *descricao) {

    celula *item = (celula *)malloc(sizeof(celula));
    if (item != NULL) {
        item->prior = prioridade;
        item->chegada->hh = hora;
        item->chegada->mm = min;
        item->chegada->ss = sec;
        strcpy(item->descricao, descricao);
    
        return item;
    }
    return NULL;
}

bool item_apagar(celula **item) {
  if (*item != NULL) {
    free(*item);
    *item = NULL;
    return (true);
  }
  return (false);
}

/*void item_imprimir(ITEM *item) {
  if (item != NULL) {
    printf("%s%s", item->verbete, item->definicao);
    printf("\n");
  }
  return;
}*/

int item_get_prioridade(celula *item) {
    if (item != NULL)
        return (item->prior);
    return -1;
}

int item_get_tempoemsegundo(celula *item) {
    int horario_total = 0;
    if (item != NULL) {
        horario_total = (item->chegada->hh)*3600 + (item->chegada->mm)*60 + (item->chegada->ss);
        return horario_total;
    }
    return -1;
}
/*
bool item_set_definicao(ITEM *item, char *definicao) {
  if (item != NULL) {
    strcpy(item->definicao, definicao);
    return (true);
  }
  return (false);
}*/
