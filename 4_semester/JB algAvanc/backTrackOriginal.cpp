#include <bits/stdc++.h>

using namespace std;

void biggestPath(int farmAtual, vector<pair<int, int>>& arestVec, int actualPathSize, int& maximPath);

int main() {

    int numFarm;
    int numArest;

    while(true) {
        
        cout << "FLUMINENSE" << endl;
        cin >> numFarm >> numArest;

        if(numFarm == 0 && numArest == 0) {
            break;
        }

        vector<pair<int, int>> arestVec;
        int farm1, farm2;

        for(int i = 0; i < numArest; i++) {
            

            cin >> farm1 >> farm2;
            arestVec.emplace_back(farm1, farm2);

        }

        int maxPath = 0;
        for(int i = 0; i < numFarm; i++) {
            
            cout << " Começa Farmacia " << i << endl;
            
            biggestPath(i, arestVec, 0, maxPath);
        }

        cout << maxPath << endl;
    }
    return 0;
}

void biggestPath(int farmAtual, vector<pair<int, int>>& arestVec, int actualPathSize, int& maximPath) {

    //percorrer o vetor de arestas inteiro

    for(auto it = arestVec.begin(); it != arestVec.end();) {
        if(it->first == farmAtual) {
            
            cout << "TamPath " << actualPathSize << endl;
            cout << it->first << " " << it->second << " " << farmAtual << endl;

            int proxFarm = it->second;
            it = arestVec.erase(it);
            it++;
            biggestPath(proxFarm, arestVec, actualPathSize + 1, maximPath);
            arestVec.emplace_back(farmAtual, proxFarm);

        }else if(it->second == farmAtual) {
            
            cout << "TamPath " << actualPathSize << endl;
            cout << it->first << " " << it->second << " " << farmAtual << endl;

            int proxFarm = it->first;
            it = arestVec.erase(it);
            it++;
            biggestPath(proxFarm, arestVec, actualPathSize + 1, maximPath);
            arestVec.emplace_back(proxFarm, farmAtual);

        }else{
            it++;
        }
    }

    if(actualPathSize > maximPath) {
            maximPath = actualPathSize;
    }
    return;

    //se achar uma aresta que liga a farm atual a outra, remove do vetor
    //recursao e dps da recursao adiciona de volta


}