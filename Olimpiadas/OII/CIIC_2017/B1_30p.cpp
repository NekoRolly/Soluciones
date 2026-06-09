/*
Complejidad: O((F+P+H)*H)
Memoria: O(F+P+H)
Puntaje: 10 + 20 + 0 + 0 = 30
Idea: Fuerza Bruta
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

struct Rectangulo{
    int x1,y1,x2,y2;
};

int F,P,H,X,Y;
Rectangulo rf[N],rp[N],rh[N];

bool interseccion(Rectangulo a,Rectangulo b){
    if (b.x2 <= a.x1 || a.x2 <= b.x1) return false;
    return a.y1 < b.y2 && b.y1 < a.y2;
}

bool inclusion(Rectangulo a,Rectangulo b){
    return a.x1 <= b.x1 && a.y1 <= b.y1 && b.x2 <= a.x2 && b.y2 <= a.y2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> F >> P >> H >> X >> Y;

    for (int i=0; i<F; i++){
        auto &[x1, y1, x2, y2] = rf[i];
        cin >> x1 >> y1 >> x2 >> y2;
    }

    for (int i=0; i<P; i++){
        auto &[x1, y1, x2, y2] = rp[i];
        cin >> x1 >> y1 >> x2 >> y2;
    }

    for (int i=0; i<H; i++){
        auto &[x1, y1, x2, y2] = rh[i];
        cin >> x1 >> y1 >> x2 >> y2;
    }

    for (int i=0; i<H; i++){
        for (int j=0; j<F; j++)
            if (interseccion(rh[i], rf[j]))
                cout << "F " << j+1 << ' ';
        for (int j=0; j<P; j++)
            if (interseccion(rh[i], rp[j]) && !inclusion(rh[i], rp[j]))
                cout << "P " << j+1 << ' ';
        for (int j=0; j<H; j++)
            if (interseccion(rh[i], rh[j]) && i != j)
                cout << "H " << j+1 << ' ';
        cout << '\n';
    }

    return 0;
}
