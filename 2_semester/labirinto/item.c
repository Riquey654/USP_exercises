#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct item_ {
    int x;
    int y;
};

ITEM* item_criar(int x, int y) {
    ITEM* item = (ITEM*) malloc(sizeof(ITEM));
    item->x = x;
    item->y = y;
}

void item_apagar(ITEM** item) {
    free(*item);
    *item = NULL;
}

int item_getx(ITEM* item) {
    return item->x;
}
int item_gety(ITEM* item) {
    return item->y;
}
void item_set(ITEM* item, int x, int y) {
    item->x = x;
    item->y = y;
}