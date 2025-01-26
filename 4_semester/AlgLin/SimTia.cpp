#include <bits/stdc++.h>

using namespace std;

int main() {

    int d;
    int k;

    int valor;
    int contador = 0; // Como os vetores sao canonicos, contador ao final de cada leitura do vetor é 1
    bool flag = true;

    cin >> d >> k; //dimensao do espaço e numero de vetores

    // Se a dimensao for 3, os vetores terao 3 elementos
    // Nao necessariamente terao 3 vetores

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < d; j++) {

            cin >> valor;
            if(valor == 1) {
                contador++;
            }
        }

        if(contador != 1) {
            flag = false;
            break;
        }
        
    }

    if(flag) {
        cout << "SimTia" << endl;
    }else{
        cout << "Nao" << endl;
    }


    return 0;
}