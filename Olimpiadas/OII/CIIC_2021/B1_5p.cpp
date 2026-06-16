/*
Complejidad: O(t*n^2*logn)
Memoria: O(1)
Puntaje: 5 + 0 + 0 + 0 + 0 = 5
Idea: Fuerza Bruta por consulta
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+4;
const int inf = 1e9+4;

void solve(){
    int n, ans = 0; cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            ans += (gcd(i, n) * gcd(j, n) == gcd(i*j, n));
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
