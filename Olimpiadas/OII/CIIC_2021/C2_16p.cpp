/*
Complejidad: O(n + q)
Memoria: O(n)
Puntaje: 5 + 11 + 0 + 0 + 0 = 16
Idea: Precálculo
Nota: Caso del árbol lineal
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+4;
const int inf = 1e9+4;

int n,q;
vector<pii> adj[N];
vector<int> rec;
int dis[N],pos[N],val[N];

void dfs(int u,int p,int Dis){
    pos[u] = rec.size(), dis[u] = Dis;
    rec.push_back(u);
    for (auto [v, wv] : adj[u])
        if (v != p) dfs(v, u, Dis + wv);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int rt = -1;
    for (int i=1; i<=n; i++)
        if (adj[i].size() == 1) rt = i;

    dfs(rt, -1, 0);

    int k = 0;
    for (int i=1; i+1<n; i++){
        val[i] = dis[rec[i-1]] - (dis[rec.back()] - dis[rec[i+1]]);
        if (val[i] < 0) k = i;
    }

    cin >> q;

    while (q--){
        int u,v,ans; cin >> u >> v;
        if (pos[u] > pos[v]) swap(u, v);

        if (pos[u]+1 >= pos[v]) ans = -1;
        else if (pos[u]+1 > k) ans = val[pos[u]+1];
        else if (pos[v]-1 <= k) ans = -val[pos[v]-1];
        else ans = min(val[k+1], -val[k]);

        cout << ans << '\n';
    }

    return 0;
}
