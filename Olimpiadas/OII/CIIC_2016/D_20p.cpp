#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int M = 2e5+4;

int n,m,q;
int pa[N],mp[N];
int val[M];
bool vis[M];
/*
Complejidad: O(q*(n+m))
Memoria: O(n+m)
Puntaje: 20 + 0(20) + 0 = 20(40)
- Se obtiene 40 debido a los casos débiles
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=m; i++)
        cin >> val[i];

    for (int i=2; i<=n; i++)
        cin >> pa[i] >> mp[i];

    while (q--){
        int u,k; cin >> u >> k;
        for (; u!=1; u=pa[u])
            vis[mp[u]] = true;
        ll ans = 0;
        for (int i=1; i<=m; i++)
            if (vis[i]){
                ans += max(0, val[i] - k);
                vis[i] = false;
            }
        cout << ans << '\n';
    }

    return 0;
}
