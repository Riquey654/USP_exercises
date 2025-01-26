#include <bits/stdc++.h>

using namespace std;

int main() {

    // A ideia é encontrar o 1, e verificar se o indice de 1 está a esquerda ou a direita de 2.
    // Para isso, é possivel utilizar um map
    // como ele se auto ordena, eu utilizo um iterador que vai do começo ate o fim, e vou comparando

    int n;
    int num;
    int contador = 1;

    cin >> n;
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        cin >> num;
        mp[num] = i;
    }

    int previousIndex;
    auto itr = mp.begin();
    previousIndex = itr->second;
    itr++;

    while(itr != mp.end()) {
        if(itr->second < previousIndex) {
            contador++;
        }

        previousIndex = itr->second;

        itr++;
    }

    cout << contador << endl;

    return 0;
}