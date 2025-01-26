#include "graph.h"

struct Matriz_Adj {
    ITEM*** matrix;
    int numero_vertices;
};

MATRIZ_ADJ* MyGraph(int Nvertexs) {
    //Aloca memória para a struct e matriz de adjacência;

    MATRIZ_ADJ* m = (MATRIZ_ADJ*) malloc(sizeof(MATRIZ_ADJ));
    if(m == NULL)
        exit(1);

    m->numero_vertices = Nvertexs;

    m->matrix = (ITEM***) malloc(Nvertexs * sizeof(ITEM**));
    if(m->matrix == NULL)
        exit(1);

    for(int i = 0; i < Nvertexs; i++) {
        (m->matrix)[i] = (ITEM**) malloc(Nvertexs * sizeof(ITEM*));
        if((m->matrix)[i] == NULL)
            exit(1);
    }

    for(int i = 0; i < Nvertexs; i++) {
        for(int j = 0; j < Nvertexs; j++) {
            (m->matrix)[i][j] = item_criar(0, 0); //Inicializa com nenhuma aresta e pesos nulos
        }
    }
    return m;
}

bool exist_edge(MATRIZ_ADJ* matrix, int origin, int end) {
    //Verifica se a aresta (origin, end) é 1 (existe) ou 0 (não existe)

    if(matrix != NULL) {
        if(Directed == 1) { //Se direcionado
            if(item_get_aresta((matrix->matrix)[origin][end]) == 1) {
                return true;
            }
        }
        else { //Se não direcionado
            if((item_get_aresta((matrix->matrix)[origin][end]) == 1) || (item_get_aresta((matrix->matrix)[end][origin]) == 1))
                return true;
        }
        return false;
    }
    return false;
}

int* get_adj_vertex(MATRIZ_ADJ* matrix, int vertex) {
    //Retorna uma lista contendo os vértices adjacentes a vertex

    int* lista = (int*) malloc(matrix->numero_vertices * sizeof(int));
    if(lista == NULL)
        exit(1);

    //Verifica a existência de arestas na linha e na coluna da matriz
    for(int i = 0; i < matrix->numero_vertices; i++) {
        lista[i] = item_get_aresta((matrix->matrix)[vertex][i]);
        if(item_get_aresta((matrix->matrix)[i][vertex]) == 1) //Condição necessária para grafos direcionados
            lista[i] = 1;
    }
    return lista;
}

bool remove_edge(MATRIZ_ADJ* matrix, int origin, int end) {
    //Reconfigura a aresta (Origin, end) com 0 (aresta) e 0 (peso)

    if(matrix != NULL) {
        if(Directed == 1) { //Se direcionado
            if(item_get_aresta((matrix->matrix)[origin][end]) == 1) {
                return(item_set_aresta_peso(&((matrix->matrix)[origin][end]), 0, 0));
            }
        }else { //Se não direcionado
            return((item_set_aresta_peso(&((matrix->matrix)[origin][end]), 0, 0)) && (item_set_aresta_peso(&((matrix->matrix)[end][origin]), 0, 0)));
        }
    }
    return false;
}

void print_info(MATRIZ_ADJ* matrix) {
    //Imprime os vértices e os valores de existência de arestas (0 ou 1)

    printf("  ");
    
    for(int j = 0; j < matrix->numero_vertices; j++)
        printf("%d ", j);
    printf("\n");

    for(int i = 0; i < matrix->numero_vertices; i++) {
        printf("%d ", i);
        for(int j = 0; j < matrix-> numero_vertices; j++) {
            printf("%d ", item_get_aresta((matrix->matrix)[i][j]));
        }
        printf("\n");
    }
}

int number_of_vertex(MATRIZ_ADJ* matrix) {
    //Retorna o número de vértices da matriz de adjacência

    if(matrix != NULL) {
        return matrix->numero_vertices;
    }
    return 0;
}


bool remove_graph(MATRIZ_ADJ** matrix) {
    //Desaloca os itens de cada célula da matriz, vetores das linhas da matriz e o grafo

    if(*matrix == NULL)
        return false;
    for(int i = 0; i < (*matrix)->numero_vertices; i++) {
        for(int j = 0; j < (*matrix)-> numero_vertices; j++) {
            item_apagar(&((*matrix)->matrix[i][j]));
        }
        free((*matrix)->matrix[i]);
        (*matrix)->matrix[i] = NULL;
    }
    free((*matrix)->matrix);
    (*matrix)->matrix = NULL;
    free(*matrix);
    *matrix = NULL;
    return true;
}

bool add_edge(MATRIZ_ADJ* matrix, int origin, int end, int weight) {
    //Insere uma aresta e seu peso

    if(matrix != NULL && weight <= MAX_WEIGHT) {
        if(Directed == 1) { //Se direcionado
            return(item_set_aresta_peso(&((matrix->matrix)[origin][end]), 1, weight));
        }
        else { //Se não direcionado
            return((item_set_aresta_peso(&((matrix->matrix)[origin][end]), 1, weight)) && (item_set_aresta_peso(&((matrix->matrix)[end][origin]), 1, weight)));
        }
    }
    return false;
}

bool remove_least_weight(MATRIZ_ADJ* matrix) {
    //Remove a aresta de menor peso
    if(matrix != NULL) {
        int menor = MAX_WEIGHT + 1;
        int x = 0; //linha da célula de menor peso
        int y = 0; //coluna da célula de menor peso

        for(int i = 0; i < matrix->numero_vertices; i++) {
            for(int j = 0; j < matrix-> numero_vertices; j++) {
                if((item_get_peso((matrix->matrix)[i][j]) < menor) && (exist_edge(matrix, i, j))) {
                    menor = item_get_peso((matrix->matrix)[i][j]);
                    x = i;
                    y = j;
                }
            }
        }

        if(Directed == 1) { //Se direcionado
            if(remove_edge(matrix, x, y) && menor != MAX_WEIGHT) {
                return true;
            }
        }
        else { //Se não direcionado
            if(remove_edge(matrix, x, y) && remove_edge(matrix, y, x) && menor != MAX_WEIGHT)
                return true;
        }
        return true;
    }
    return false;
}

ITEM*** adjacency_matrix(MATRIZ_ADJ* matrix) {
    //Retorna o ponteiro para a matriz de adjacência em si

    if(matrix != NULL) {
        return matrix->matrix;
    }
    return NULL;
}