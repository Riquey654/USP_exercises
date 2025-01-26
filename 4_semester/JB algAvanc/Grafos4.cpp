#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kosarajus(vector<vector<int>> &grafo, vector<int> &sccVector, vector<long long> &newFortuna, vector<long long> &fortuna);
void colocaPilha(int index, vector<vector<int>> &grafo, vector<bool> &visited, stack<int> &pilha);
vector<vector<int>> get_transposta(vector<vector<int>> &grafo);
void dfs(vector<vector<int>> &grafo, int num, vector<bool> &visited);
vector<vector<int>> mergeSccs(vector<vector<int>> &grafo, vector<vector<int>> sccs, vector<int> sccVector);
void topoSortDFS(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &order, int node);
vector<int> getTopoOrderDFS(vector<vector<int>> &graph);
long long findMaxPathValue(vector<vector<int>> &graph, vector<long long> &nodeValues);

vector<vector<int>> kosarajus(vector<vector<int>> &grafo, vector<int> &sccVector, vector<long long> &newFortuna, vector<long long> &fortuna) {
    stack<int> pilha;
    vector<bool> visited(grafo.size(), false);

    long long fortunaAtual = 0;
    int indexVector = 0;

    for (int i = 0; i < grafo.size(); i++) {
        if (!visited[i]) {
            colocaPilha(i, grafo, visited, pilha);
        }
    }

    vector<vector<int>> grafoTransp = get_transposta(grafo);

    fill(visited.begin(), visited.end(), false);

    // Identificar SCCs
    vector<vector<int>> sccs;
    while (!pilha.empty()) {
        int num = pilha.top();
        pilha.pop();
        if (!visited[num]) {
            vector<int> componente;
            stack<int> dfs_stack;
            dfs_stack.push(num);

            while (!dfs_stack.empty()) {
                int v = dfs_stack.top();
                dfs_stack.pop();

                if (!visited[v]) {
                    visited[v] = true;
                    componente.push_back(v);
                    sccVector[v] = indexVector;
                    fortunaAtual += fortuna[v];

                    for (int adj : grafoTransp[v]) {
                        if (!visited[adj]) {
                            dfs_stack.push(adj);
                        }
                    }
                }
            }
            sccs.push_back(componente);
            newFortuna.push_back(fortunaAtual);
            fortunaAtual = 0;
            indexVector++;
        }
    }

    return sccs;
}

void colocaPilha(int index, vector<vector<int>> &grafo, vector<bool> &visited, stack<int> &pilha) {
    visited[index] = true;
    for (int adj : grafo[index]) {
        if (!visited[adj]) {
            colocaPilha(adj, grafo, visited, pilha);
        }
    }
    pilha.push(index);
}

vector<vector<int>> get_transposta(vector<vector<int>> &grafo) {
    vector<vector<int>> grafoNovo(grafo.size());
    for (int i = 0; i < grafo.size(); i++) {
        for (int adj : grafo[i]) {
            grafoNovo[adj].push_back(i);
        }
    }
    return grafoNovo;
}

vector<vector<int>> mergeSccs(vector<vector<int>> &grafo, vector<vector<int>> sccs, vector<int> sccVector) {
    vector<vector<int>> newGraph(sccs.size());
    for (int i = 0; i < grafo.size(); i++) {
        for (int adj : grafo[i]) {
            if (sccVector[i] != sccVector[adj]) {
                newGraph[sccVector[i]].push_back(sccVector[adj]);
            }
        }
    }
    return newGraph;
}

void topoSortDFS(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &order, int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            topoSortDFS(graph, visited, order, adj);
        }
    }
    order.push(node);
}

vector<int> getTopoOrderDFS(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> order;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSortDFS(graph, visited, order, i);
        }
    }

    vector<int> topoOrder;
    while (!order.empty()) {
        topoOrder.push_back(order.top());
        order.pop();
    }

    return topoOrder;
}

long long findMaxPathValue(vector<vector<int>> &graph, vector<long long> &fortunas) {
    int n = graph.size();
    vector<int> topoOrder = getTopoOrderDFS(graph);
    vector<long long> maxFortuna = fortunas;

    for (int u : topoOrder) {
        for (int v : graph[u]) {
            maxFortuna[v] = max(maxFortuna[v], maxFortuna[u] + fortunas[v]);
        }
    }

    return *max_element(maxFortuna.begin(), maxFortuna.end());
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> fortuna(n);
    vector<vector<int>> grafo(n);
    vector<int> sccVector(n, -1);
    vector<long long> newFortuna;

    for (int i = 0; i < n; i++) {
        cin >> fortuna[i];
    }

    for (int i = 0; i < m; i++) {
        int tunel1, tunel2;
        cin >> tunel1 >> tunel2;
        grafo[tunel1 - 1].push_back(tunel2 - 1);
    }

    vector<vector<int>> sccs = kosarajus(grafo, sccVector, newFortuna, fortuna);
    vector<vector<int>> mergedGraph = mergeSccs(grafo, sccs, sccVector);
    long long resultado = findMaxPathValue(mergedGraph, newFortuna);

    cout << resultado << endl;

    return 0;
}
