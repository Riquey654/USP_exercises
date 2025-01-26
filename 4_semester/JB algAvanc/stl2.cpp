#include <bits/stdc++.h>

using namespace std;

struct customCompare {
    bool operator()(const pair <pair <int, int>, int> &a, const pair <pair <int, int>, int> &b) const{
        if(a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
};

void printar(const pair<pair<int, int>, int> &a) {

    cout << a.first.second << "\n";
    
}

int main() {

    int nAbsoluto; //Num absoluto de consultas diferentes
    int nPrint; //Num de consultas a serem printadas

    string lixo;
    int ID;
    int totalTime;
    int baseTime;

    set <pair <pair <int, int>, int>, customCompare> consultasSet;

    cin >> nAbsoluto;

    for(int i = 0; i < nAbsoluto; i++) {

        cin >> lixo >> ID >> baseTime;

        consultasSet.insert({{baseTime, ID}, baseTime}); //trocou a ordem pois o tempo tem mais importancia na ordenacao

        //ler as consultas "query ID T"
    }

    cin >> nPrint;

    //Se printar, incrementa o contador, e adiciona T ao tempo da consulta printada

    for(int i = 0; i < nPrint; i++) {

        auto it = consultasSet.begin();

        ID = it->first.second;
        totalTime = it->first.first;
        baseTime = it->second;


        printar(*it);
        consultasSet.erase(it);
        consultasSet.insert({{totalTime + baseTime, ID}, baseTime});
    }

}