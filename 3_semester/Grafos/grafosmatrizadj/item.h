#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *item_criar(int aresta, int peso);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	int item_get_aresta(ITEM *item);
	int item_get_peso(ITEM *item);
	bool item_set_aresta_peso(ITEM **item, int aresta, int peso);

#endif
