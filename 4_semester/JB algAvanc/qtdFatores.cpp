#include <bits/stdc++.h>

using namespace std;

long long tamCrivo;

bitset<10000010> crivo;
vector<int> primos;

void crivoErastotenes(long long M){
	tamCrivo = M+1;
	crivo.set();

	crivo[0] = crivo[1] = 0;

	for (long long i = 2; i <= tamCrivo; ++i){
		if (crivo[i]){
			for (long long j = i*i; j <= tamCrivo; j += i)
				crivo[j]=0;
			primos.push_back((int)i);
		}
	}
}


vector<int> fatoresPrimos(long long N){
	vector<int> fatores;

	for (int i = 0, fp = primos[i]; fp*fp <=N; i++, fp = primos[i]){
		while (N % fp == 0){
			N = N/fp;
			fatores.push_back(fp);
		}
	}

	if (N != 1)
		fatores.push_back(N);

	return fatores;
}

map<int, int> fatoresPrimosMap(long long N){
	map<int, int> fatMap;

	for (int i = 0, fp = primos[i]; fp*fp <=N; i++, fp = primos[i]){
		while (N % fp == 0){
			N = N/fp;
			fatMap[fp]++;
		}
	}

	if (N != 1)
		fatMap[N] = 1;

	return fatMap;
}


int main(){
	
	crivoErastotenes(10000000);

	long long n;
	long long num;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
	    
	    cin >> num;
	    
	    long long qtdDivisores = 1;
	
    	map<int, int> fatMap = fatoresPrimosMap(num);
    
    	for (auto i : fatMap)   
    		qtdDivisores = qtdDivisores * (i.second + 1);
    		
    	cout << qtdDivisores << endl;
	}
	
	return 0;
}