/*
Complejidad: O(t*n^(2/3)*logn)
Memoria: O(n)
Puntaje: 5 + 19 + 22 + 0 + 0 = 46
Idea: Fuerza Bruta en los divisores de n
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

void get_divisores(int x,vector<int> &div){
    for (int i=1; i*i<=x; i++){
        if (x%i != 0) continue;
        div.push_back(i);
        if (i*i != x) div.push_back(x/i);
    }
}

int ep[20];
void solve(){
    int n; cin >> n;
    vector<int> div;
    get_divisores(n, div);

    ll ans = 0;
    for (int d1 : div)
        for (int d2 : div){
            if (n % (1ll * d1 * d2) != 0) continue;
            ans += 1ll * euler(n/d1) * euler(n/d2);
            if (d1 == d2) ans += euler(n/d1);
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
