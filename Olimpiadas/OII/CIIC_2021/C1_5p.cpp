/*
Complejidad: O(n*q)
Memoria: O(n)
Puntaje: 5 + 0 + 0 + 0 + 0 = 5
Idea: Fuerza bruta por cada consulta
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
int dis[N],pos[N];

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

    cin >> q;

    while (q--){
        int u,v; cin >> u >> v;
        if (pos[u] > pos[v]) swap(u, v);
        int ans = inf;
        for (int i=pos[u]+1; i<pos[v]; i++)
            ans = min(ans, abs(dis[rec[i-1]] - (dis[rec.back()] - dis[rec[i+1]])));
        cout << (ans == inf ? -1 : ans) << '\n';
    }

    return 0;
}
