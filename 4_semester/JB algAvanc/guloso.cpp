#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long int tempoTarefa;
    long int tempoLimite;
    long int custoTotal = 0;
    cin >> n;

    vector<pair<long int, long int>> m;

    for(int i = 0; i < n; i++) {
        cin >> tempoTarefa >> tempoLimite;
        m.push_back(make_pair(tempoTarefa, tempoLimite));
    }

    // ordenar o vetor por tempoTarefa
    sort(m.begin(), m.end());

    tempoTarefa = 0;

    for(auto it = m.begin(); it != m.end(); ++it) {  //itera sobre todo o vetor, realizando as operações

        tempoTarefa += it->first;
        tempoLimite = it->second;
        custoTotal += (tempoLimite - tempoTarefa);

    }

    cout << custoTotal << endl;

    return 0;
}
