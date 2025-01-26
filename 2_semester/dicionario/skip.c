#include "skip.h"
#include "item.h"

struct no_ {
  ITEM *item;
  NO *prox;
  NO *baixo;
  int level;
};

struct skip_ {
  NO *upleft;
  int max_level;
  int level;
};

SKIP *criar_skip() {
  SKIP *sl = (SKIP *)malloc(sizeof(SKIP));
  sl->upleft = NULL;
  sl->max_level = 10;
  ITEM *item_upleft = item_criar("0", "0");
  NO* novo_0_upleft = criar_no(item_upleft, 0, NULL, NULL); //o nivel 0 esta separado, pois nao tem down
  NO *aux = novo_0_upleft;
  for(int i = 1; i < sl->max_level; i++) {
    NO* novo_upleft = criar_no(item_upleft, i, NULL, aux);
    aux = novo_upleft;//alocacao de todos os upleft
  }
  return sl;
}

bool insercao(SKIP *sl, ITEM *palavra) {
  printf("Entrou no insercao");
  // se a palavra já existir, nao insere
  if (busca_bool(sl, palavra->verbete) == true) {
    printf("OPERACAO INVALIDA");
    return false;
  }

  // NO para ir percorrendo a skip list até encontrar onde é para ser inserido
  NO *sentinela = sl->upleft;
  printf("Antes de updates");
  // vetor de NO para guardar o elemento anterior de onde será inserido
  NO *updates[sl->max_level];
  printf("antes do gerar level");
  int level_no = gerar_level(5, 99999);

  // busca em cada level
  printf("busca em cada level");
  while (sentinela->level != 0) {

    while (strcmp(sentinela->prox->item->verbete, palavra->verbete) < 0) {
      sentinela = sentinela->prox;
    }
    // armazenamento dos updates
    updates[sentinela->level] = sentinela;
    sentinela = sentinela->baixo;
  }

  while (strcmp(sentinela->prox->item->verbete, palavra->verbete) < 0) {
    // enquanto a primeira palavra for menor que a segunda
    sentinela = sentinela->prox;
  }
  updates[sentinela->level] = sentinela;

  int level_atual = 0;
  printf("Antes da inserção");

  // insercao do NO
  while (level_atual <= sl->max_level && level_atual <= level_no) {
    NO *novo_no = criar_no(palavra, level_atual, NULL, NULL);
    if (level_atual == 0) {
      novo_no->prox = updates[level_atual]->prox; // utilizacao do update
      novo_no->baixo = NULL;
    } else {
      novo_no->prox = updates[level_atual]->prox;
      novo_no->baixo = updates[level_atual - 1]->prox;
    }
    updates[level_atual]->prox = novo_no;
    level_atual = level_atual + 1;
  }
  printf("Insercao bem sucedida");
  // caso seja necessario criar novas linhas expressas
  for (int i = sl->level + 1; i <= level_no; i++) {
    NO *novo_no = criar_no(palavra, i, NULL, updates[i - 1]->prox);
    ITEM *item_novo = item_criar("0", "0");
    NO *novo_upleft = criar_no(item_novo, i, novo_no, sl->upleft);
    sl->upleft = novo_upleft;
    updates[i] = novo_upleft;
   // sl->max_level = level_no;
  }
  return true;
}

bool alteracao(SKIP *sl, char* str1, char* str2) {
  // acha o item e o recebe. altera a definicao do item para a str2
  ITEM *alterado = busca_retorna_item(sl, str1);
  if (alterado != NULL) {
    // O item foi encontrado, agora atualize a definição
    // A definição deve ter no máximo 140 caracteres
    if (strlen(str2) <= 140) {
      // Copie a nova definição para o item
      strcpy(alterado->definicao, str2);
      return true; // Sucesso na alteração
    } else {
      printf("OPERACAO INVALIDA\n");
      return false; // Definição muito longa
    }
  } else {
    printf("OPERACAO INVALIDA\n");
    return false; // Item não encontrado
  }
}

// Função para remover uma palavra do dicionário
bool remocao(SKIP *sl, char* str1) {
    if((busca_bool(sl, str1)) == false) {
      return false; //se n achar o elemento, return false
    }
    NO *sentinela = sl->upleft;
    NO *updates[sl->max_level];

    while(sentinela->level != 0) {
      while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
        sentinela = sentinela->prox;
      }
      updates[sentinela->level] = sentinela;
      sentinela = sentinela->baixo;
    }

    while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
      sentinela = sentinela->prox;
    }
    updates[sentinela->level] = sentinela;

    int level_atual = 0;
    while(level_atual <= sl->level) {
      if(strcmp(updates[level_atual]->prox->item->verbete, str1) == 0) {
        NO *rem = updates[level_atual]->prox;
        updates[level_atual]->prox = rem->prox;
        free(rem);
      }
      level_atual = level_atual + 1;
    }

    while(sl->upleft->prox != NULL) {
      NO *rem = sl->upleft;
      sl->upleft = sl->upleft->baixo;
      sl->level = sl->level - 1;
      free(rem);
    }
    return true;
}

void busca_imprime(SKIP *sl, char* str1) {
  NO *sentinela = sl->upleft;
  while(sentinela->level != 0) {
    while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
      sentinela = sentinela->prox;
    }
    sentinela = sentinela->baixo;
  }

  while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
    sentinela = sentinela->prox;
  }

  if(strcmp(sentinela->item->verbete, str1) != 0) {
    printf("OPERACAO INVALIDA");
    return;
  } else {
    printf("%s %s\n", sentinela->item->verbete, sentinela->item->definicao);
    return;
  }
}
bool busca_bool(SKIP *sl, char* str1) {
  NO *sentinela = sl->upleft;
  while(sentinela->level != 0) {
    while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
      sentinela = sentinela->prox;
    }
    sentinela = sentinela->baixo;
  }

  while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
    sentinela = sentinela->prox;
  }

  if(strcmp(sentinela->item->verbete, str1) != 0) {
    return false;
  } else {
    return true;
  }
}

ITEM *busca_retorna_item(SKIP *sl, char* str1) {
  NO *sentinela = sl->upleft;
  while(sentinela->level != 0) {
    while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
      sentinela = sentinela->prox;
    }
    sentinela = sentinela->baixo;
  }

  while(strcmp(sentinela->prox->item->verbete, str1) < 0) {
    sentinela = sentinela->prox;
  }

  if(strcmp(sentinela->item->verbete, str1) != 0) {
    return NULL;
  } else {
    return sentinela->item;
  }
}

/*void impressao(SKIP *sl, char* ch1) {
  NO *atual = sl->upleft;
  bool encontrou = false;

  // Percorrendo a Skip List
  while (atual != NULL) {
    NO *linha_atual = atual;

    // percorre a linha atual
    while (linha_atual != NULL) {
      if (linha_atual->item != NULL) {
        if (linha_atual->item->verbete[0] == ch1) {
          printf("%s %s\n", linha_atual->item->verbete, linha_atual->item->definicao);
          encontrou = true;
        }
      }
      linha_atual = linha_atual->prox; // Move para a direita, no nivel atual
    }
    atual = atual->baixo; // Desce para baixo, no próximo nivel
  }
  if (!encontrou) {
    printf("NAO HA PALAVRAS INICIADAS POR %c\n", ch1);
  }
}*/

int gerar_level(float p, int maxlevel) {
  // p sempre será 5
  // como a função random gera um número aleatorio entre 0 e 10, o level
  // aumenta se o número aleatorio for menor que 5
  int level = 0;
  while ((random() % 10) <= p && level < maxlevel) {
    level = level + 1;
  }
  return level;
}
// numero aleatorio, dependendo de qunatas vezes dividir por
// 2, o nivel aumenta

NO *criar_no(ITEM *item, int level, NO *prox, NO *baixo) {
  NO *no_criado = (NO *)malloc(sizeof(NO));
  no_criado->item = item;
  no_criado->level = level;
  no_criado->prox = prox;
  no_criado->baixo = baixo;
  return no_criado;
}

void apagar_skip(SKIP *sl){
    if(sl == NULL) {
        printf("Falha ao apagar");
        return;
    }
    free(sl);
}

// lista dinamicamente encadeada
// nao usar item?????
// a função strcmp é essencial
// Um verbete possui até 50 caracteres, não tem espaço.
// A definição possui até 140 caracteres, incluindo espaços.
/*Note que há operações que não podem ser completadas em alguns casos.
Especificamente, essas operações são a alteração, remoção e busca de palavras
inexistentes no dicionário e a inserção de uma palavra repetida. Nesses casos,
o seu programa deve imprimir “OPERACAO INVALIDA”. Caso não haja palavras
iniciadas por ch1, mas o usuário requeira a impressão de todas as palavras
iniciadas por esse caractere, seu programa deve imprimir a mensagem “NAO HA
PALAVRAS INICIADAS POR ch1”.*/