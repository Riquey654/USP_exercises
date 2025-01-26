#include <bits/stdc++.h>
#include <cctype>

using namespace std;

#define V 38

int rgrafo[V][V];
int pai[V];
vector<vector<int>> grafo;

bool caminho(int s, int t){
	queue<int> q;
	q.push(s);
	pai[s] = -1;

	int visitado[V];
	memset(visitado, 0, sizeof visitado);
	visitado[s] = 1;

	while (!q.empty()){
		int u = q.front(); q.pop();
		
		// para todo v adj a u
		for (int v = 0; v < V; ++v){
			// so entra na fila se tiver residuo e NAO visitado..
			if (rgrafo[u][v]>0 && visitado[v] == 0) {
				q.push(v);
				pai[v] = u;
				visitado[v] = 1;
			}
		}
	}

	// verifica se tem caminho de s para t
	return (visitado[t] == 1);
}

int ek(){
	int u,v;

	// copia grafo original no grafo residual...
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			rgrafo[i][j] = grafo[i][j];

	int s = 0;
	int t = 37;

	int maxFlow = 0;

	while (caminho(s,t)){
		int gargalo = 100000;
		// calcular o gargalo....
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			gargalo = min(gargalo, rgrafo[u][v]);
		}

		// Atualiza o forward e backward edges...
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			rgrafo[u][v] -= gargalo;
			rgrafo[v][u] += gargalo;
		}
		maxFlow += gargalo;
	}

	return maxFlow;

}

void job() {

    grafo.assign(38, vector<int>(38, 0));

    string line;

    int fluxoNeces = 0;

    while(getline(cin, line)) {
        if(!line.empty()) {
            grafo[0][line[0] - 64] = line[1] - 48;

            fluxoNeces += line[1] - 48;

            int index = 3;

            while(isdigit(line[index])) {

                grafo[line[0] - 64][line[index] -48 + 27] = 1;
                index++;
            }

            //li as infos de 1 linha apenas
        }else{
            for(int i = 27; i < 37; i++) {
                    grafo[i][37] = 1;
                }
                //leu todas as infos necessarias

                if(ek() == fluxoNeces) {
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
                fluxoNeces = 0;
                grafo.assign(38, vector<int>(38, 0));
        }
    }
    for(int i = 27; i < 37; i++) {
        grafo[i][37] = 1;
    }
    //leu todas as infos necessarias

    if(ek() == fluxoNeces) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {

    job();

    return 0;
}