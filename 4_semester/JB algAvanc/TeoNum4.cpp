#include <bits/stdc++.h>

using namespace std;

vector<long long> resolucao(long long p);

vector<long long> resolucao(long long p) {

    vector<long long> vetor;
    vetor.assign(p, -1);

    for(long long i = 0; i < p; i++) {
        long long teste = (i * i) % p;
        if(vetor[teste] == -1) {
            vetor[(i * i) % p] = i;
        }
    }
    return vetor;

}

int main() {

    int p;
    cin >> p;

    vector<long long> vetorResultado = resolucao(p);
    for(int i = 0; i < p; i++) {
        cout << vetorResultado[i] << " ";
    }

    return 0;
}