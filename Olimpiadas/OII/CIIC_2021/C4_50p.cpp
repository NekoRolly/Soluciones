/*
Complejidad: O(n^2 + q*n)
Memoria: O(n^2)
Puntaje: 5 + 0 + 17 + 28 + 0 = 50
Idea: DP on trees y fuerza bruta en la consulta
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+4;
const int inf = 1e9+4;

int n,q;
vector<pii> adj[N];
vector<int> vec,rec,path;
int val[N][N];
int dp1[N],dp2[N];

void dfs1(int u,int p){
    dp1[u] = dp2[u] = 0;
    for (auto [v, wv] : adj[u]) if (v != p){
        dfs1(v, u);
        dp2[u] = max(max(dp2[u], dp2[v]), dp1[u] + dp1[v] + wv);
        dp1[u] = max(dp1[u], dp1[v] + wv);
    }
}

void dfs3(int u,int p,int x){
    rec.push_back(u);
    if (u == x) path = rec;
    for (auto [v, wv] : adj[u])
        if (v != p) dfs3(v, u, x);
    rec.pop_back();
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

    for (int u=1; u<=n; u++)
        for (auto [v, wv] : adj[u]){
            vec.clear(); dfs1(v, u);
            val[u][v] = dp2[v];
        }

    cin >> q;

    while (q--){
        int u,v; cin >> u >> v;
        dfs3(u, -1, v);
        int ans = inf;
        for (int i=1; i+1<path.size(); i++)
            ans = min(ans, abs(val[path[i]][path[i-1]] - val[path[i]][path[i+1]]));
        cout << (ans == inf ? -1 : ans) << '\n';
    }

    return 0;
}
