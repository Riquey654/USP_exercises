#include "lista.h"

struct no {
	celula *info;
	no_t *prox;
};

struct lista {
	no_t *ini, *fim;
	int tam;
};

lista_t *criar_lista() {
	lista_t *l = (lista_t *)malloc(sizeof(lista_t));
	assert(l != NULL);
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
	return l;
}       

bool esta_vazia(lista_t *l) {
	assert(l != NULL);
	return (l->tam == 0);
}

int tamanho(lista_t *l) {
	assert(l != NULL);
	return l->tam;
}

void destruir_lista(lista_t **l) {
	no_t *p = (*l)->ini;
	while (p != NULL) {
		(*l)->ini = (*l)->ini->prox;
	    free(p);
	    p = (*l)->ini;
	}
	free(*l);
	*l = NULL;
}

no_t *busca(lista_t *l, celula *x) {
	no_t *p = l->ini;
	
	while(p != NULL && get_valor(p->info) < get_valor(x)) {
		p = p->prox;
	}
	
	if(p == NULL) {
		return NULL;
	}
	
	if(get_valor(p->info) == get_valor(x)) {
		return p;
	}
	
	return NULL;
}

bool inserir_prioridade(lista_t *l, celula *x) {
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->info = x;
	p->prox = NULL;
	
	if(tam(l) == 0) { //1o caso: lista vazia
		l->ini = p;
		l->fim = p;
		l->tam++;
		return true;
	}
	
	no_t *aux = l->ini;
	no_t *ant = NULL;
	
	while(aux != NULL && item_get_prioridade(aux->info) > item_get_prioridade(x)) {
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL) { //3o caso: inserir no fim da lista
		l->fim->prox = p;
		l->fim = p;
		l->tam++;
		return true;
	}
	
	if(ant == NULL) { //2o caso: inserir no inicio
		p->prox = l->ini;
		l->ini = p;
		l->tam++;
		return true;
	}
	
	ant->prox = p;
	p->prox = aux;
	l->tam++;
	return true;
}


bool inserir_horario(lista_t *l, celula *x) {
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->info = x;
	p->prox = NULL;
	
	if(tam(l) == 0) { //1o caso: lista vazia
		l->ini = p;
		l->fim = p;
		l->tam++;
		return true;
	}
	
	no_t *aux = l->ini;
	no_t *ant = NULL;
	
	while(aux != NULL && item_get_tempoemsegundo(aux->info) < item_get_tempoemsegundo(x)) {
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL) { //3o caso: inserir no fim da lista
		l->fim->prox = p;
		l->fim = p;
		l->tam++;
		return true;
	}
	
	if(ant == NULL) { //2o caso: inserir no inicio
		p->prox = l->ini;
		l->ini = p;
		l->tam++;
		return true;
	}
	
	ant->prox = p;
	p->prox = aux;
	l->tam++;
	return true;
}

/*void imprimir(lista_t *l) {
	no_t *p = l->ini;
	
	while(p != NULL) {
		printf("%d ", get_valor(p->info));
		p = p->prox;
	}
	printf("\n");
}*/

bool remover(lista_t *l, celula *x) {
    
    no_t *p = l->ini;
    
    if((l->tam) == 1) {
        l->ini = NULL;
        l->fim = NULL;
        free(p);
        l->tam--;
    }else{ 
        l->ini = p->prox;
	    free(p);
	    l->tam--;
    }
}

celula *retorna_inicio(lista_t *l) {
    return l->ini->info;
}