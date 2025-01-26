#include <bits/stdc++.h>

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

float closestPointOfPairs(int n, vector<struct point> listaX, vector<struct point> listaY) {

    //main function of the program
    //It is a recursive function, which will use div and conq algorithm

    //Divide, select the min distance in that division, and then merge with another division
    //when merging, we have to consider the min of the left, of the right, and the amount of closest 
    //distance which are one in the left, and another in the right.

    float minRight;
    float minLeft;
    float theMinDist;

    if(n == 2) {
        return minDistance(distance(), distance());
    }
    if(n == 3) {
        return minDistance(minDistance(distance(), distance()), distance());
    }

    int mid = n/2;

    minRight = closestPointOfPairs(mid, vetorCortadoX, vetorCortadoY);
    minLeft = closestPointOfPairs(mid, vetorCortadoX, vetorCortadoY);

    theMinDist = minDistance(minRight, minLeft);

    //comparar distancia entre os pontos da faixa no meio

    /////////////////////////////////////////////

    return theMinDist;
}

int main() {

    int n;
    vector<struct point> ordenadoX; //ordenado por x
    vector<struct point> ordenadoY; //ordenado por y

    //como ordenar um por x e outro por y?

    struct point aux;

    cin >> n;


    for(int i = 0; i < n; i++) {
        cin >> aux.x;
        cin >> aux.y;

        //inserir na lista ordenada por x e por y

    }

    float distMin;

    distMin = closestPointOfPairs();


}