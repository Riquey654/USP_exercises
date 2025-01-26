#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

vector<int> grundy;

void makeGrundy(int numC, vector<int> valoresC);
int mex(const vector<int>& nums);
bool nimExtendido(int qtdPilhas, vector<int> varetasPilha);

int main() {

    int numC;
    int numRodadas;
    int numPilhas;
    vector<int> valoresPilhas;
    cin >> numC;
    vector<int> valoresC;
    valoresC.assign(numC, -1);
    for(int i = 0; i < numC; i++) {
        cin >> valoresC[i];
    }

    makeGrundy(numC, valoresC);

    cin >> numRodadas;

    for(int j = 0; j < numRodadas; j++) {

        cin >> numPilhas;
        valoresPilhas.assign(numPilhas, -1);
        for(int h = 0; h < numPilhas; h++) {
            cin >> valoresPilhas[h];
        }

        if(nimExtendido(numPilhas, valoresPilhas)) {
            cout << "W";
        }else{
            cout << "L";
        }
    }


    return 0;
}

void makeGrundy(int numC, vector<int> valoresC) {

    grundy.assign(10010, 0);

    // grundy 0 perde
    // grundy 1 perde
    // grundy 2 ganha
    // grundy 3 ganha
    // grundy 4 perde

    grundy[0] = 0;

    for (int i = 0; i < 10010; i++) {
        vector<int> vetorC;
        for (int c : valoresC) {
            if (i >= c) {
                vetorC.push_back(grundy[i - c]);
            }
        }
        grundy[i] = mex(vetorC);
    }
}

int mex(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());

    int numMex = 0;
    while (numSet.find(numMex) != numSet.end()) {
        numMex++;
    }

    return numMex;
}

bool nimExtendido(int qtdPilhas, vector<int> varetasPilha) {
    int soma = 0;
    for(int g = 0; g < qtdPilhas; g++) {

        soma = soma ^ grundy[varetasPilha[g]];
    }

    if(soma == 0) {
        return false;
    }else{
        return true;
    }

}

