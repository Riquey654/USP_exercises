#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> MEMO;

int maxCaminhos(int n, vector<vector<char>> caminho, int linha, int coluna);

int main() {

    int n;
    cin >> n;

    vector<vector<char>> caminho;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            char aux;
            cin >> aux;
            caminho[i][j] = aux;
        }
    }

    for(int i = 0; i < n; i++) {
        MEMO[i].assign(n, 0);
    }

    int resultado = maxCaminhos(n, caminho, n - 1, n - 1);

    cout << resultado << endl;


    return 0;

}


int maxCaminhos(int n, vector<vector<char>> caminho, int linha, int coluna) {

    if(linha == 0 && coluna == 0) {
        return MEMO[0][0] = 1;
    }


    if(linha < 0 || coluna < 0) {
        return 0;
    }
    if(caminho[linha][coluna] == '*') {
        return 0;
    }

    return MEMO[linha][coluna] = maxCaminhos(n , caminho, linha - 1, coluna) + maxCaminhos(n , caminho, linha, coluna - 1) + maxCaminhos(n , caminho, linha - 1, coluna - 1);

}
