#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct item_ ITEM;
struct item_ {
  char verbete[51];
  char definicao[141];
};

ITEM *item_criar(char verb[51], char defini[141]);
bool item_apagar(ITEM **item);
void item_imprimir(ITEM *item);
char* item_get_verb(ITEM *item);
char* item_get_def(ITEM *item);
/*bool item_set_chave(ITEM *item, char* verb, char* defini);*/

#endif
