#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

struct point {
    float x;
    float y;
};

float distance(struct point A, struct point B) {

    float dist;
    dist = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));

    return dist;

}

float minDistance(float num1, float num2) {

    if(num1 > num2) {
        return num2;
    }else{
        return num1;
    }

}

float closestPointOfPairs(vector<struct point> &listaX, vector<struct point> &listaY) {

    //main function of the program
    //It is a recursive function, which will use div and conq algorithm

    //Divide, select the min distance in that division, and then merge with another division
    //when merging, we have to consider the min of the left, of the right, and the amount of closest 
    //distance which are one in the left, and another in the right.

    
    int n = listaX.size();

    if(n == 2) {
        return distance(listaX[0], listaX[1]);
    }
    if(n == 3) {
        return minDistance(minDistance(distance(listaX[0], listaX[1]), distance(listaX[0], listaX[2])), distance(listaX[1], listaX[2]));
    }
    
    

    int mid = n/2;
    
    vector<struct point> leftX(listaX.begin(), listaX.begin() + mid);
    vector<struct point> rightX(listaX.begin() + mid, listaX.end());
    
    vector<struct point> leftY, rightY;
    
    
    //colocar no vetor da direita ou da esquerda, em relacao a Y
    for (const auto &p : listaY) {
        
        if (p.x <= listaX[mid - 1].x) {
            
            leftY.push_back(p);
            
        } else {
            
            rightY.push_back(p);
            
        }
    }

    float minRight = closestPointOfPairs(rightX, rightY);
    float minLeft = closestPointOfPairs(leftX, leftY);

    float theMinDist = minDistance(minRight, minLeft);

    //comparar distancia entre os pontos da faixa no meio
    
    vector<struct point> meio;
    
    for (const auto &p : listaY) {
        
        if (abs(p.x - listaX[mid].x) < theMinDist) {
            
            meio.push_back(p);
            
        }
    }
    
    for (int i = 0; i < meio.size(); i++) {
        // checar até 7 pontos 
        for (int j = i + 1; j < meio.size() && (meio[j].y - meio[i].y) < theMinDist && (j - i) <= 7; j++) {
            
            theMinDist = minDistance(theMinDist, distance(meio[i], meio[j]));
            
        }
    }
    

    return theMinDist;
}

int main() {

    int n;
    vector<struct point> ordenadoX; //ordenado por x
    vector<struct point> ordenadoY; //ordenado por y

    //como ordenar um por x e outro por y?

    cin >> n;
    
    vector<struct point> pontos(n);


    for(int i = 0; i < n; i++) {
        
        cin >> pontos[i].x >> pontos[i].y;

    }
    
    ordenadoX = pontos;
    ordenadoY = pontos;
    sort(ordenadoX.begin(), ordenadoX.end(), [](point a, point b) { return a.x < b.x; });
    sort(ordenadoY.begin(), ordenadoY.end(), [](point a, point b) { return a.y < b.y; });

    float distMin;

    distMin = closestPointOfPairs(ordenadoX, ordenadoY);
    
    cout << fixed << setprecision(2) << distMin << endl;
    
    return 0;


}