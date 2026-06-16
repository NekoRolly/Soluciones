/*
Complejidad: O(n^3 + q*n)
Memoria: O(n^2)
Puntaje: 0 + 0 + 17 + 0 + 0 = 17
Idea: Precálculo y fuerza bruta en la consulta
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

void dfs1(int u,int p){
    vec.push_back(u);
    for (auto [v, wv] : adj[u])
        if (v != p) dfs1(v, u);
}

void dfs2(int u,int p,int rt,int Dis,int &mx){
    mx = max(mx, Dis);
    for (auto [v, wv] : adj[u])
        if (v != p && v != rt)
            dfs2(v, u, rt, Dis + wv, mx);
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
            int mx = 0;
            for (int x : vec)
                dfs2(x, -1, u, 0, mx);
            val[u][v] = mx;
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
