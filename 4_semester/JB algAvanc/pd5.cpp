#include <bits/stdc++.h>
#include <string>

using namespace std;
vector<vector <int>> MEMOtable;
vector<vector<string>> MEMOstring;

void calculaCusto(int tamRealS1, int tamRealS2, string& s1, string& s2);

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    MEMOtable.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    MEMOstring.assign(s1.size() + 1, vector<string>(s2.size() + 1, ""));


    calculaCusto(s1.size(), s2.size(), s1, s2);
    
    cout << MEMOtable[s1.size()][s2.size()] << endl;
    
    if(MEMOtable[s1.size()][s2.size()] == 0) {
        cout << "nada a fazer";
        return 0;
    }
    
    cout << MEMOstring[s1.size()][s2.size()] << endl;

    return 0;

}

void calculaCusto(int tamRealS1, int tamRealS2, string& s1, string& s2) {

    for(int i = 0; i <= tamRealS1; i++) {
        for(int j = 0; j <= tamRealS2; j++) {

            if(i == 0 && j == 0) {
                MEMOstring[i][j] = "";
                MEMOtable[i][j] = 0;
            }else if(i == 0) {
                
                MEMOstring[i][j] = MEMOstring[i][j - 1] + "I:" + s2[j - 1];
                MEMOtable[i][j] = j * 2;
                
            }else if(j == 0) {
                
                MEMOstring[i][j] = MEMOstring[i - 1][j] + "R:" + s1[i - 1];
                MEMOtable[i][j] = i * 2;
                
            }else if(s1[i - 1] == s2[j - 1]) { //Se a letras sao iguais
            
                MEMOstring[i][j] = MEMOstring[i - 1][j - 1];
                MEMOtable[i][j] = MEMOtable[i - 1][j - 1];
                
            }else{

                int alfa;
                if(s1[i - 1] == 'a' || s1[i - 1] == 'e' || s1[i - 1] == 'i' || s1[i - 1] == 'o' || s1[i - 1] == 'u') { //se letra de S1 é vogal
                    if(s2[j - 1] == 'a' || s2[j - 1] == 'e' || s2[j - 1] == 'i' || s2[j - 1] == 'o' || s2[j - 1] == 'u') { //se letra de S2 tbm é vogal
    
                        alfa = 1;
                    }else{
                        alfa = 3;
                    }
                }else{ //é consoante
                    if(s2[j - 1] == 'a' || s2[j - 1] == 'e' || s2[j - 1] == 'i' || s2[j - 1] == 'o' || s2[j - 1] == 'u') { //se letra de S2 é vogal
                        alfa = 3;
                    }else{
                        alfa = 1;
                    }
                }
                MEMOtable[i][j] = min( min(2 + MEMOtable[i][j - 1], 2 + MEMOtable[i - 1][j]), alfa + MEMOtable[i - 1][j - 1]);
                
                if(MEMOtable[i][j] == 2 + MEMOtable[i][j - 1]) {
    
                    MEMOstring[i][j] = MEMOstring[i][j - 1] + "I:" + s2[j - 1];
    
                }else if(MEMOtable[i][j] == 2 + MEMOtable[i - 1][j]) {
    
                    MEMOstring[i][j] = MEMOstring[i - 1][j] + "R:" + s1[i - 1];
    
                }else{
    
                    MEMOstring[i][j] = MEMOstring[i - 1][j - 1] + "T:" + s1[i - 1] + '-' + s2[j - 1];
    
                }
            }
        }
    }
}
