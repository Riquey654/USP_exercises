#include "pilha.h"


int main() {
    int n, m;
    int achou = 0;
   // int linha = 0, coluna = 0;

    pilha_t *pi;
    pi = criar_pilha();

    ITEM *x;
    x = item_criar(0, 0);

    inserir_elemento(pi, x);

    //linhas e colunas
    scanf("%d %d", &n, &m);

    //alocacao da matriz
    int **matriz = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(m * sizeof(int));
    }
    int encontrados[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m ; j++) {
            encontrados[i][j] = 0;
        }
    }
    encontrados[0][0] = 1;
    //preenchimento da matriz
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    //LOGICA 1:caminho  0:parede   2:saida

    while(!esta_vazia(pi)) {
        //ordem de empilhamento baixo, esquerda, cima, direita
        ITEM* itemaux;
        remover_elemento(pi, &itemaux);
        printf("(%d, %d)\n", item_getx(itemaux), item_gety(itemaux));
        if(matriz[item_getx(itemaux)][item_gety(itemaux)] == 2) {
            achou = 1;
            break;
        }
        //baixo
        if(item_getx(itemaux) != (n - 1)) {
            if((matriz[item_getx(itemaux) + 1][item_gety(itemaux)] >= 1) && (encontrados[item_getx(itemaux) + 1][item_gety(itemaux)] == 0)) {
                ITEM* inseridonovo = item_criar(item_getx(itemaux) + 1, item_gety(itemaux));
                inserir_elemento(pi, inseridonovo);
                encontrados[item_getx(itemaux) + 1][item_gety(itemaux)] = 1;
            }
        }

        //esquerda
        if(item_gety(itemaux) != (0)) {
            if((matriz[item_getx(itemaux)][item_gety(itemaux)-1] >= 1) && (encontrados[item_getx(itemaux)][item_gety(itemaux)-1] == 0)) {
                ITEM* inseridonovo = item_criar(item_getx(itemaux), item_gety(itemaux) - 1);
                inserir_elemento(pi, inseridonovo);
                encontrados[item_getx(itemaux)][item_gety(itemaux)-1] = 1;
            }
        }

        //cima
        if(item_getx(itemaux) != (0)) {
            if((matriz[item_getx(itemaux)-1][item_gety(itemaux)] >= 1) && (encontrados[item_getx(itemaux) - 1][item_gety(itemaux)] == 0)) {
                ITEM* inseridonovo = item_criar(item_getx(itemaux)-1, item_gety(itemaux));
                inserir_elemento(pi, inseridonovo);
                encontrados[item_getx(itemaux) - 1][item_gety(itemaux)] = 1;
            }
        }

        //direita
        if(item_gety(itemaux) != (m-1)) {
            if((matriz[item_getx(itemaux)][item_gety(itemaux)+1] >= 1) && (encontrados[item_getx(itemaux)][item_gety(itemaux)+1] == 0)) {
                ITEM* inseridonovo = item_criar(item_getx(itemaux), item_gety(itemaux)+1);
                inserir_elemento(pi, inseridonovo);
                encontrados[item_getx(itemaux)][item_gety(itemaux)+1] = 1;
            }
        }
        //analisar aqui se pilha estiver vazia
        //como acabou de empilhar, se a pilha estiver vazia, é saida nao encontrada
        //apos analisar baixo, esquerda, cima e direita, temos que mover
//E se nao for possivel mover?
//pegar o ultimo elemento da pilha e repetir o processo
//E se a pilha estiver vazia?
//Saida nao encontrada
    }
    if(!achou) {
        printf("Saída não encontrada.\n");
    }
    destruir_pilha(&pi);
    for(int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}