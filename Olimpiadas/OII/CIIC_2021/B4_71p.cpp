/*
Complejidad: O(nlogn + f(n) + t)
Memoria: O(n)
Puntaje: 5 + 19 + 22 + 25 + 0 = 71
Idea: Precalculo para cada n
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;

int lp[N],phi[N];
ll ans[N];

int euler(int x){
    int ans = x;
    while (x > 1){
        int p = lp[x];
        ans -= ans/p;
        while (x%p == 0) x /= p;
    }
    return ans;
}

void pre(int n){
    for (int i=2; i<=n; i++) if (lp[i] == 0)
        for (int j=i; j<=n; j+=i) lp[j] = i;

    for (int i=1; i<=n; i++) phi[i] = euler(i);

    for (int i=1; i<=n; i++)
        for (int j=1; i*j<=n; j++)
            for (int k=1; k*i*j<=n; k++){
                ans[i*j*k] += 1ll * phi[j*k] * phi[i*k];
                if (i == j) ans[i*j*k] += phi[i*k];
            }
}

void solve(){
    int n; cin >> n;
    cout << ans[n]/2 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre(N-1);
    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
