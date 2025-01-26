#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

bool isPosible(int nLivros, int mEstudantes, vector<long long> &paginasDoLivro, long long maxTeste) {
    
    int estudantes = 1;
    long long paginasLendo = 0;
    
    for(int i = 0; i < nLivros; i++) {
        if(paginasLendo + paginasDoLivro[i] > maxTeste) {
            
            estudantes++;
            paginasLendo = paginasDoLivro[i];
            
            if(estudantes > mEstudantes) {
                return false;
            }
            
        }else{
            paginasLendo += paginasDoLivro[i];
        }
    }
    
    return true;
}

int alocarLivros(int nLivros, int mEstudantes, vector<long long> &paginasDoLivro) {
    
    long long minimoHipotese = *max_element(paginasDoLivro.begin(), paginasDoLivro.end());
    long long maximoHipotese = accumulate(paginasDoLivro.begin(), paginasDoLivro.end(), 0);
    
    long long hipotese = maximoHipotese;
    
    while (minimoHipotese <= maximoHipotese) {
        
        long long mid = (minimoHipotese + maximoHipotese) / 2;
        
        if (isPosible(nLivros, mEstudantes, paginasDoLivro, mid)) {
            
            hipotese = mid;
            maximoHipotese = mid - 1;
            
        } else {
            
            minimoHipotese = mid + 1;
            
        }
    }
    
    return hipotese;
}


int main()
{
    
    int nLivros;
    int mEstudantes;
    
    cin >> nLivros >> mEstudantes;
    
    vector<long long> paginas(nLivros);
    
    for(int i = 0; i < nLivros; i++) {
        cin >> paginas[i];
    }
    
    cout <<  alocarLivros(nLivros, mEstudantes, paginas) << endl;
    

    return 0;
}