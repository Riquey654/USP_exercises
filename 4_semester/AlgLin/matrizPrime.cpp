#include <bits/stdc++.h>

using namespace std;


bitset<10000010> crivo;
long long tamCrivo;
vector<long long> primos;

void crivoErastotenes(long long maximo){
	tamCrivo = maximo + 1;
	crivo.set();

	crivo[0] = crivo[1] = 0;

	for (long long i = 2; i <= tamCrivo; ++i){
		if (crivo[i]){
			for (long long j = i*i; j <= tamCrivo; j += i)
				crivo[j] = 0;
			primos.push_back(i);
		}
	}
}


bool primo(long long num){
	if (num <= tamCrivo)
		return crivo[num];

	for (long long i = 0; i*i <= primos.size() ; i++){
		if (num % primos[i] == 0)
			return false;
	}
	return true;
}


int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<long long>> matrizPrime;
    
    matrizPrime.assign(n, vector<long long>(m, -1));
    
    crivoErastotenes(10000000);
    
    //cout << "terminou crivo" << endl;
    
    long long num;
    long long minIncremento = 99999;
    long long aux = 0;
    
    for(int i = 0; i < n; i++) {
        aux = 0;
        for(int j = 0; j < m; j++) {
            
            cin >> num;
            matrizPrime[i][j] = num;
            
            while(!primo(num)) { //nao primo
                num++;
                aux++;
            }
        }
        if(minIncremento > aux) {
            minIncremento = aux;
        }
    }
    
    
    //pra uma mesma linha, se houver um nao primo, eu coloco na lista
    //se nessa mesma linha, se houver outro nao primo, eu tiro o numero anterior da lista, pois
    //essa linha nao tem a possibilidade de ser toda composta de numeros primos
    
    for(int i = 0; i < m; i++) { //ANALISE POR COLUNA
        aux = 0;
        for(int j = 0; j < n; j++) {
            
            long long num = matrizPrime[j][i];
            while (!primo(num)) { // nao primo
                num++;
                aux++;
            }
        }
         minIncremento = min(minIncremento, aux);
    }
    
    cout << minIncremento << endl;
    
    
    return 0;
}