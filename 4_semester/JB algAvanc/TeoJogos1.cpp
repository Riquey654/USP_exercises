#include <bits/stdc++.h>
using namespace std;

bool nim(int qtdPilhas, vector<int> varetasPilha);

int main() {

    int rodadas;
    cin >> rodadas;

    int qtdPilhas;
    vector<int> varetasPilha;

    int dinheiro = 20;

    for(int i = 0; i < rodadas; i++) {

        cin >> qtdPilhas;
        varetasPilha.assign(qtdPilhas, -1);
        for(int j = 0; j < qtdPilhas; j++) {
            cin >> varetasPilha[j];
        }
        if(nim(qtdPilhas, varetasPilha)) {
            dinheiro += 20;
        }else{
            dinheiro -= 20;
        }
    }

    cout << dinheiro;

    return 0;
}

bool nim(int qtdPilhas, vector<int> varetasPilha) {

    int soma = 0;
    for(int g = 0; g < qtdPilhas; g++) {

        soma = soma ^ varetasPilha[g];
    }

    if(soma % 4 == 0) {
        return false;
    }else{
        return true;
    }
}