#ifndef ITEM_H
    #define ITEM_H
    typedef struct item_ ITEM;

    ITEM* item_criar(int x, int y);
    void item_apagar(ITEM** item);
    int item_getx(ITEM* item);
    int item_gety(ITEM* item);
    void item_set(ITEM* item, int x, int y);
#endif