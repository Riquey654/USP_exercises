#ifndef SKIP_H
#define SKIP_H

#include "item.h"

typedef struct no_ NO;

typedef struct skip_ SKIP;

SKIP *criar_skip(); // função para criar uma nova skip lista

bool insercao(SKIP *sl, ITEM *verbete); // Função para inserir um verbete

bool alteracao(SKIP *sl, char *verbete,char *nova_definicao); // função para alterar a definição de um verbete

bool remocao(SKIP *sl, char *verbete); // Função para remover um verbete

void busca_imprime(SKIP *sl, char *verbete); // Função para buscar um verbete e imprimir a sua definição

bool busca_bool(SKIP *sl, char* str1);

ITEM *busca_retorna_item(SKIP *sl, char* str1);

int gerar_level(float p, int maxlevel);

//void impressao(SKIP *sl, char *caractere); // Função para imprimir todos os verbetes iniciados por um caractere

void apagar_skip(SKIP *sl); // Função para apagar a skip list

NO *criar_no(ITEM *item, int level, NO *prox, NO *baixo);

#endif