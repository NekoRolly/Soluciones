/*
Complejidad: O(n + q + sum_ans)
Memoria: O(n)
Puntaje: 4 + 24 + 20 + 0 = 48
Idea: Precálculo del nxt y observación clave
Nota: Caso cuando la suma de respuesta es <= 10^6
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;

int get_id(char c){
    if (c == 'a') return 0;
    if (c == 'e') return 1;
    if (c == 'i') return 2;
    if (c == 'o') return 3;
    return 4;
}

int n,q;
string s;
int nxt[N][5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> q;
    s = '.' + s;

    for (int j=0; j<5; j++) nxt[n+1][j] = n+1;
    for (int i=n; i>=1; i--){
        for (int j=0; j<5; j++)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][get_id(s[i])] = i;
    }

    while (q--){
        int l,r; cin >> l >> r;
        int ans = 0;
        while (l <= r){
            int aux = l;
            for (int j=0; j<5; j++)
                aux = max(aux, nxt[l][j]);
            if (aux <= r) ans++;
            l = aux+1;
        }
        cout << ans+1 << '\n';
    }

    return 0;
}
