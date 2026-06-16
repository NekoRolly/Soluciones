/*
Complejidad: O(nlogn + t)
Memoria: O(n)
Puntaje: 5 + 19 + 22 + 25 + 29 = 100
Idea: Precalculo para cada n con función multiplicativa
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6+4;

int lp[N],phi[N];
ll f1[N],f2[N];

void pre(int n){
    for (int i=2; i<=n; i++) if (!lp[i])
        for (int j=i; j<=n; j+=i) lp[j] = i;

    f1[1] = f2[1] = phi[1] = 1;
    for (int i=2; i<=n; i++){
        int p = lp[i], e = 0, pe = 1;
        while (lp[i/pe] == p) e++, pe *= p;
        if (pe != i){
            f1[i] = 1ll * f1[pe] * f1[i/pe];
            f2[i] = 1ll * f2[pe] * f2[i/pe];
            phi[i] = phi[pe] * phi[i/pe];
        }
        else{
            phi[i] = i - i/p;
            for (int j=0,pj=1; j<=e; j++,pj*=p)
                for (int k=0,pk=1; j+k<=e; k++,pk*=p){
                    if (j == k) f2[i] += phi[i/pj];
                    f1[i] += 1ll * phi[i/pj] * phi[i/pk];
                }
        }
    }
}

void solve(){
    int n; cin >> n;
    cout << (f1[n] + f2[n])/2 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre(N-1);
    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
