// Tad para Armazenamento de valores de Arestas e Pesos

#include "item.h"

struct item_{ 
   int aresta;
   int peso;       
};

ITEM *item_criar (int aresta, int peso){
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
          
          if (item != NULL){
             item->aresta = aresta;
             item->peso = peso;
             return item;
          }
          return NULL;
}

bool item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL;
      return true;
   }
   return false;
}

int item_get_aresta(ITEM *item){
    if (item != NULL)
      return item->aresta;
    exit(1);
}

int item_get_peso(ITEM *item){
    if (item != NULL)
      return(item->peso);
    exit(1);
}

void item_imprimir(ITEM *item){
     if (item != NULL)
        printf("(%d, %d)\n", item->aresta, item->peso);
}

bool item_set_aresta_peso(ITEM **item, int a, int p) {
   if((*item) != NULL) {
      (*item)->aresta = a;
      (*item)->peso = p;
      return true;
   }
   return false;
}
