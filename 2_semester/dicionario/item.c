#include "item.h"

ITEM *item_criar(char verb[51], char defini[141]) {
  ITEM *item = (ITEM *)malloc(sizeof(ITEM));
  if (item == NULL) {
    return NULL;
  }
  strcpy(item->verbete, verb); // Copia a palavra (str1) para a estrutura ITEM
  strcpy(item->definicao, defini); // Copia a definição (str2) para a estrutura ITEM
  return item;
}

bool item_apagar(ITEM **item) {
  if (*item == NULL) {
    return false;
  }
  free(*item);
  *item = NULL;
  return true;
}

void item_imprimir(ITEM *item) {
  if (item == NULL) {
    return;
  }
  printf("%s ", item_get_verb(item));
  printf("%s", item_get_def(item));

  return;
}

char* item_get_verb(ITEM *item) {
  if (item == NULL) {
    return NULL;
  }
  return item->verbete;
}

char* item_get_def(ITEM *item) {
  if (item == NULL) {
    return NULL;
  }
  return item->definicao;
}

/*bool item_set_chave(ITEM *item, char* verb, char* defini) {
  if (item == NULL) {
    return false;
  }

  // libera a memoria para nao sobreescever
  free(item->verbete);
  free(item->def);

  // aloca memoria para a string
  item->verbete = strdup(verb);
  item->def = strdup(defini);

  return true;
}*/
