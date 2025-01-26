#include <bits/stdc++.h>

using namespace std;

int main() {

    int numCasos;
    cin >> numCasos; //ler numCasos

    for(int i = 0; i < numCasos; i++) {

        cout << "Case " << i+1 << ": ";

        int numAssuntos;
        cin >> numAssuntos; //ler numAssuntos
        string assuntos;
        int numDiasAssunto;
        unordered_map <string, int> mp;

        int diasTotais;
        string nomeAssunto;

        for(int j = 0; j < numAssuntos; j++) {
            cin >> assuntos; //ler assuntos
            cin >> numDiasAssunto; //ler numDiasAssuntos

            mp[assuntos] = numDiasAssunto; //botar infos no map
        }

        cin >> diasTotais; //ler diasTotais
        cin >> nomeAssunto; //ler nomeAssunto


       if(mp.find(nomeAssunto) != mp.end()) {
            if(diasTotais >= mp[nomeAssunto] ) {
                cout << "Ufa!\n";
            }else{
                if(mp[nomeAssunto] > diasTotais + 5) {
                    cout << "Deu ruim! Va trabalhar\n";
                }else{
                    cout << "Atrasado\n";
                }
            }
       }else{
            cout << "Deu ruim! Va trabalhar\n";
       }
    }
}