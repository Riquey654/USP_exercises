#include <bits/stdc++.h>
using namespace std;

int movimentos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void resolve_caminho(int m, int n, int passos, int *minPath, int *numOfPaths, int linha, int coluna, vector<vector<int>>& matrizMarcada);

int main() {

    int m, n;
    string line;
    int linha, coluna;
    int numOfPaths = 0;
    int minPath = 999;

    cin >> m; //m linhas
    cin >> n; //n colunas
    cin.ignore();

    vector<vector<int>> matriz_Marcada(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            matriz_Marcada[i][j] = 0;  //SETAR CAMINHO
        }
    }

    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> linha >> coluna;
        matriz_Marcada[linha][coluna] = -1; //OBSTACULOS
    }

    matriz_Marcada[0][0] = 1;
    resolve_caminho(m, n, 0, &minPath, &numOfPaths, 0, 0, matriz_Marcada);

    cout << numOfPaths << " " << minPath << endl;


}

void resolve_caminho(int m, int n, int passos, int *minPath, int *numOfPaths, int linha, int coluna, vector<vector<int>>& matriz_Marcada) {

    if(linha == (m - 1) && coluna == (n - 1) ){
        (*numOfPaths)++;
        if(*minPath > passos) {
            *minPath = passos;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {

        int new_linha = linha + movimentos[i][0];
        int new_coluna = coluna + movimentos[i][1];

        if(new_linha >= 0 && new_linha < m && new_coluna >= 0 && new_coluna < n && matriz_Marcada[new_linha][new_coluna] == 0) {
            matriz_Marcada[new_linha][new_coluna] = 1;
            resolve_caminho(m, n, passos + 1, minPath, numOfPaths, new_linha, new_coluna, matriz_Marcada);
            matriz_Marcada[new_linha][new_coluna] = 0;
        }

    }

}
