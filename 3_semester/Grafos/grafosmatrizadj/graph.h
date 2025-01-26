#ifndef GRAPH_H
    #define GRAPH_H
    #define MAX_WEIGHT 1000 //Valor de peso máximo que uma aresta pode ter
    #define Directed 1 //0 = Não direcionado; 1 = direcionado

    #include "item.h"

    typedef struct Matriz_Adj MATRIZ_ADJ;

    MATRIZ_ADJ* MyGraph(int Nvertexs);
    bool exist_edge(MATRIZ_ADJ* matrix, int origin, int end);
    int* get_adj_vertex(MATRIZ_ADJ* matrix, int vertex);
    bool remove_edge(MATRIZ_ADJ* matrix, int origin, int end);
    void print_info(MATRIZ_ADJ* matrix);
    int number_of_vertex(MATRIZ_ADJ* matrix);
    bool remove_graph(MATRIZ_ADJ** matrix);
    bool add_edge(MATRIZ_ADJ* matrix, int origin, int end, int weight);
    bool remove_least_weight(MATRIZ_ADJ* matrix);
    ITEM*** adjacency_matrix(MATRIZ_ADJ* matrix);

#endif