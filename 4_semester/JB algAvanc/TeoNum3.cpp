#include <bits/stdc++.h>

using namespace std;

#define p 1000000007

long long exp(int x, int y, int z);

long long exp(int x, int y, int z) {

    // ((a ^ b) ^ c) mod p
    if(y == 0) {
        return 1 % z;
    }
    long long resultado = exp(x, y/2, z);

    resultado = (resultado * resultado) % z;

    if(y % 2 != 0) {
        resultado = (resultado * x) % z;
    }
    return resultado;
}

int main() {

    int n;
    int a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++) {

        cin >> a >> b >> c;
        long long exp_mod = exp(b, c, p - 1);
        long long resposta = exp(a, exp_mod, p);

        cout << resposta << endl;

    }


    return 0;
}