#include <bits/stdc++.h>
using namespace std;

vector<int> inicialTreatment(string frase, string &padrao);
void KMP(string frase, string padrao, vector<int> prefixLookup);

int main() {

    string frase;
    string padrao;

    getline(cin, frase);
    getline(cin, padrao);

    vector<int> prefixLookup = inicialTreatment(frase, padrao);

    /*for(int h = 0; h < padrao.size(); h++) {
        cout << prefixLookup[h] << " ";
    }*/

    KMP(frase, padrao, prefixLookup);

    vector<char> newString;
    newString.assign(padrao.size(), '>');

    for(int h = newString.size(); h > 0; h--) {
        newString[h] = padrao[h - 1];
    }
    /*for(int h = 0; h <= newString.size(); h++) {
        cout << newString[h];
    }*/


    return 0;
}

vector<int> inicialTreatment(string frase, string &padrao) {
    // identificar sequencias dentro da nossa string padrao

    int index = 0;
    int j = 1;

    vector<int> prefixLookup;
    prefixLookup.assign(padrao.size(), 0);
    //01234567
    //ABABAABA
    //00123123

    while(j < padrao.size()) {

        if(padrao[index] == padrao[j]) {
            index++;
            prefixLookup[j] = index;
            j++;
        }else{
            if(index == 0) {
                prefixLookup[j] = 0;
                j++;
            }else{
                index = prefixLookup[index - 1];
            }
        }
    }

    return prefixLookup;


}

void KMP(string frase, string padrao, vector<int> prefixLookup) {

    int i = 1;
    int j = 0;
    int qtdVezes = 0;
    vector<int> indexSuccess;

    vector<char> newString;
    newString.assign(padrao.size(), '>');

    for(int h = newString.size(); h > 0; h--) {
        newString[h] = padrao[h - 1];
    }
    /*for(int h = 0; h <= newString.size(); h++) {
        cout << newString[h];
    }*/

    while(i <= frase.size()) {

        //cout << frase[i - 1] << " " << newString[j + 1] << endl;
        //cout << "VALOR DE i" << i << " valor de j" << j << endl;

        if(frase[i - 1] == newString[j + 1]) {
            i++;
            j++;
        }else{
            if(j == 0) {
                i++;
            }else{
                j = prefixLookup[j - 1];
            }
        }
        if(j == padrao.size()) {
            qtdVezes++;
            indexSuccess.push_back(i - j - 1);
            j = prefixLookup[j - 1];
        }
    }

    cout << qtdVezes << endl;
    if(qtdVezes < 100) {
        for(int g = 0; g < indexSuccess.size(); g++) {
        cout << indexSuccess[g] << endl;
    }
    }
}