/*
Complejidad: O(t*n^2*logn)
Memoria: O(n)
Puntaje: 0 + 0 + 22 + 0 + 0 = 22
Idea: Fuerza Bruta en los divisores de n
Nota: Caso especial n = p^k
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;

int lp[N];

void pre(int n){
    for (int i=2; i<=n; i++) if (lp[i] == 0)
        for (int j=i; j<=n; j+=i) lp[j] = i;
}

int euler(int x){
    int ans = x;
    while (x > 1){
        int p = lp[x];
        ans -= ans/p;
        while (x%p == 0) x /= p;
    }
    return ans;
}

int ep[20];
void solve(){
    int n; cin >> n;
    int p = lp[n], k = 0, aux = n;
    while (aux%p == 0) k++, aux/=p;

    ep[0] = 1;
    for (int i=1; i<=k; i++) ep[i] = ep[i-1] * p;

    ll ans = 0;
    for (int i=0; i<=k; i++)
        for (int j=0; i+j<=k; j++){
            ans += 1ll * euler(n/ep[i]) * euler(n/ep[j]);
            if (i == j) ans += euler(n/ep[i]);
        }

    cout << ans/2 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre(N-1);
    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
