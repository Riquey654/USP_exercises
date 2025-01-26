/*
Grupo:
Arthur Trottmann Ramos - 14681052
Didrick Chancel EGNINA NDOMBI - 14822368
Henrique Drago - 14675441
Henrique Yukio Sekido - 14614564
João Vitor Naldoni - 13748102

Compilação e Execução:
No terminal, insira "make" para compilar e "./graph" para executar. Caso queira remover
os executáveis, insira "make clean"

Testes:
Insira o número de vértices do grafo, o número de arestas e as configurações dessas, ou seja, vértice de origem, vértice de término e peso (para grafos não valorados, insira 0)
Em seguida, utilize os seguintes comandos:
    'a' = dada uma aresta, verifica se ela existe
    'b' = imprime os vértices adjacentes a um dado vértice
    'c' = remove uma dada aresta
    'd' = imprime a matriz de adjacência do grafo
    'e' = imprime o número de vértices do grafo
    'f' = remove a aresta de menor peso
    'z' = finaliza o programa, desalocando memória

OBS: em graph.h, o macro "Directed" indica se o grafo é direcionado (1) ou não direcionado (0). Isso implica na adição das arestas iniciais e na implementação de algumas funções
*/

#include "graph.h"

int main(void) {
    MATRIZ_ADJ* graph;
    int numberVertex, numberEdge;
    int origin, end, weight;
    char operation;

    scanf("%d", &numberVertex);
    graph = MyGraph(numberVertex);

    scanf("%d", &numberEdge);

    for(int i = 0; i < numberEdge; i++) {
        scanf("%d %d %d", &origin, &end, &weight);
        add_edge(graph, origin, end, weight);
    }

    /*
    //Para teste da função adjacency_matrix (retorna a matriz de adjacência em si):
        if(adjacency_matrix(graph) != NULL)
            printf("YES\n");
        else
            printf("No\n");
    */

    scanf("%c", &operation);

    while(operation != 'z') {
        switch(operation) {
            case 'a':
                scanf("%d %d", &origin, &end);
                if(exist_edge(graph, origin, end))
                    printf("Existe Aresta %d-%d\n", origin, end);
                else
                    printf("Não Existe Aresta %d-%d\n", origin, end);
                break;
            case 'b':
                scanf("%d", &origin);
                int* list = get_adj_vertex(graph, origin);
                if(list != NULL) {
                    printf("Vértices adjacentes a %d: ", origin);
                    for(int i = 0; i <= numberEdge; i++) {
                        if(list[i] == 1)
                            printf("%d ", i);
                    }
                    printf("\n");
                    free(list);
                    list = NULL;
                }
                else
                    printf("Não há vértices adjacentes a %d\n", origin);
                break;
            case 'c':
                scanf("%d %d", &origin, &end);
                if(remove_edge(graph, origin, end))
                    printf("Aresta %d-%d removida\n", origin, end);
                else
                    printf("Aresta %d-%d não existe\n", origin, end);
                break;
            case 'd':
                print_info(graph);
                break;
            case 'e':
                printf("Número de vértices: %d\n", number_of_vertex(graph));
                break;
            case 'f':
                if(remove_least_weight(graph))
                    printf("Aresta de Menor peso removida\n");
                else
                    printf("Não foi possível remover a aresta de menor peso\n");
                break;
            case 'g':
                scanf("%d %d %d", &origin, &end, &weight);
                add_edge(graph, origin, end, weight);
        }
        scanf("%c", &operation);
    }
    remove_graph(&graph);

    return 0;
}