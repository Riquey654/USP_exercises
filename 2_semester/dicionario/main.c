#include "item.h"
#include "skip.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  char inicializacao[10];
  SKIP *sl = criar_skip();
  char str1[51];
  char def1[141];
  char letra[2];

  while (scanf("%s", inicializacao) != EOF) {
    if(strcmp(inicializacao, "insercao") == 0) {
      printf("Entrou no insercao while");
      scanf("%s%[^\n]s", str1, def1);
      ITEM *p = item_criar(str1, def1);
      insercao(sl, p);

    }
    if(strcmp(inicializacao, "busca") == 0) {
      printf("Entrou no busca while");
      scanf("%s", str1);
      busca_imprime(sl, str1);

    }
    if(strcmp(inicializacao, "remocao") == 0) {
      printf("Entrou no remocao while");
      scanf("%s", str1);
      remocao(sl, str1);

    }
    if(strcmp(inicializacao, "alteracao") == 0) {
      printf("Entrou no alteracao while");
      scanf("%s%[^\n]s", str1, def1);
      alteracao(sl, str1, def1);

    }
    /*if(strcmp(inicializacao, "impressao") == 0) {
      printf("Entrou no impressao while");
      scanf("%s", letra);
      impressao(sl, letra);

    }*/
    }

  apagar_skip(sl);
  return 0;
}