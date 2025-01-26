#include <bits/stdc++.h>

using namespace std;

long long maxPagesPD(int n, int x, vector<long long> &preco, vector<long long> &paginas, vector<long long> &MEMO);

int main() {

    int n;
    cin >> n;

    int orcamento;
    cin >> orcamento;

    vector<long long> preco(n);
    vector<long long> paginas(n);

    vector<long long> MEMO(orcamento + 1, 0);

    for(int i = 0; i < n; i++) {

        long long p;
        cin >> p;

        cout << p << endl;

        preco.push_back(p);

        cout << preco[i] << endl;

    }

    for(int i = 0; i < n; i++) {

        long long pg;
        cin >> pg;
        paginas.push_back(pg);

    }

    long long resultado = maxPagesPD(n, orcamento, preco, paginas, MEMO);

    for(int i = 0; i < n; i++) {
        cout << preco[i] << endl;
    }

    cout << resultado << endl;


return 0;

}

long long maxPagesPD(int n, int x, vector<long long> &preco, vector<long long> &paginas, vector<long long> &MEMO) {

    for(int orc = 1; orc <= x; orc++) {
        for(int item = 0; item < n; item++) {
            long long aux;
            if(preco[item] <= orc) {
                aux = max(MEMO[orc - 1], paginas[item] + MEMO[orc - preco[item]]);
                MEMO[orc] = max(MEMO[orc], aux);
            }else{
                aux = MEMO[orc - 1];
                MEMO[orc] = max(MEMO[orc], aux);
            }
        }
    }

    return MEMO[x];

}
