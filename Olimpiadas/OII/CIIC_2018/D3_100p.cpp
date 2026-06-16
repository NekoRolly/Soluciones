/*
Complejidad: O(n*(n+m))
Memoria: O(n^2)
Puntaje: 21 + 33 + 46 = 100
Idea: Expandir de forma eficiente e independiente con DFS
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1004;

int n,m;
set<int> adj[N];
bool vis[N][N];

void dfs(int u,int id){
    vis[u][id] = true;
    for (int v : adj[u])
        if (!vis[v][id]) dfs(v, id);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++)
        vis[i][i] = true;

    while (m--){
        int u,v; cin >> u >> v;
        if (adj[u].find(v) != adj[u].end())
            adj[u].erase(v), adj[v].erase(u);
        else{
            for (int i=1; i<=n; i++){
                if (!vis[u][i] && vis[v][i]) dfs(u, i);
                if (vis[u][i] && !vis[v][i]) dfs(v, i);
            }
            adj[u].insert(v), adj[v].insert(u);
        }
    }

    for (int i=1; i<=n; i++){
        int ans = 0;
        for (int j=1; j<=n; j++)
            ans += vis[i][j];
        cout << ans << '\n';
    }

    return 0;
}
