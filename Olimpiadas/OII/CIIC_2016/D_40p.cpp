#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int M = 54;

int n,m,q;
int pa[N],mp[N];
int val[M];
bool vis[N][M];
/*
Complejidad: O(m*(q+n))
Memoria: O(n*m)
Puntaje: 0 + 20 + 0 = 20
- Se puede obtener 40 juntando con la otra subtarea
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=m; i++)
        cin >> val[i];

    for (int i=2; i<=n; i++){
        cin >> pa[i] >> mp[i];
        for (int j=1; j<=m; j++)
            vis[i][j] = vis[pa[i]][j];
        vis[i][mp[i]] = true;
    }

    while (q--){
        int u,k; cin >> u >> k;
        ll ans = 0;
        for (int i=1; i<=m; i++)
            if (vis[u][i])
                ans += max(0, val[i] - k);
        cout << ans << '\n';
    }

    return 0;
}
