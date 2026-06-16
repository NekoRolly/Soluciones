/*
Complejidad: O((n+q)*logn)
Memoria: O(n*logn)
Puntaje: 4 + 24 + 20 + 52 = 100
Idea: Binary lifting con el nxt y observación clave
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
int pos[5];
int nxt[N][17];
int step[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> q;
    s = '.' + s;

    fill(pos, pos+5, n+1);
    fill(nxt[n+1], nxt[n+1]+17, n+1);
    for (int i=n; i>=1; i--){
        pos[get_id(s[i])] = i;
        int &mx = step[i];
        for (int j=0; j<5; j++)
            mx = max(mx, pos[j]);
        nxt[i][0] = min(n+1, step[i]+1);
        for (int j=1; j<17; j++)
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
    }

    while (q--){
        int l,r; cin >> l >> r;
        int ans = 0;
        for (int i=16; i>=0; i--)
            if (nxt[l][i] <= r)
                l = nxt[l][i], ans ^= 1<<i;
        if (step[l] <= r) ans++;
        cout << ans+1 << '\n';
    }

    return 0;
}
