#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> get_pai(vector<long long> &grafo, long long individuo) { // pair(pai, qtd de elems)

    if(grafo[individuo] < 0) {
        return {individuo, grafo[individuo]};
    }else{
        long long raiz = get_pai(grafo, grafo[individuo]).first;
        grafo[individuo] = raiz;
        return {raiz, grafo[raiz]};
    }
}

void unionFind(vector<long long> &pais, long long bicho1, long long bicho2, long long &maxCompSize, long long &totalComp) {

// o vetor grafo é um vetor que em cada indice esta o pai
// aqui eu vou achar o pai do bicho1 e o pai do bicho2
    auto conjBicho1 = get_pai(pais, bicho1);
    auto conjBicho2 = get_pai(pais, bicho2);

    if(conjBicho1.first != conjBicho2.first) { //pais diferentes
        totalComp--;

        long long novoTamanho = abs(conjBicho1.second) + abs(conjBicho2.second);

        if(abs(conjBicho1.second) >= abs(conjBicho2.second)) {//bicho1 tem mais elementos

            pais[conjBicho2.first] = conjBicho1.first; //CALCULAR TOTAL DE ELEMENTOS
            pais[conjBicho1.first] = -novoTamanho;

        }else{ //bicho2 tem mais elementos

            pais[conjBicho1.first] = conjBicho2.first;
            pais[conjBicho2.first] = -novoTamanho;

        }

        maxCompSize = max(maxCompSize, novoTamanho);

    }
    cout << totalComp << " " << maxCompSize << endl;

    return;
}

int main() {

    long long n;
    long long numContatos;
    vector<long long> grafo;
    long long bicho1, bicho2;
    long long maxCompSize = 1;

    cin >> n >> numContatos;

    long long totalComp = n;

    grafo.assign(n, -1); //vetor com tamanho n

    for(int i = 0; i < numContatos; i++) {
        cin >> bicho1 >> bicho2;
        unionFind(grafo, bicho1 - 1, bicho2 - 1, maxCompSize, totalComp);
    }
    return 0;
}