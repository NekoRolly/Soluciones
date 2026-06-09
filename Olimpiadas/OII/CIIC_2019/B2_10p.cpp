/*
Complejidad: O(n^2)
Memoria: O(n^2)
Puntaje: 10 + 0 + 0 + 0 + 0 = 10
Idea: DFS
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;
const int N = 1004;

int n,m;
int p[N];
bool adj[N][N],vis[N];

void dfs(int u){
    vis[u] = true;
    for (int v=1; v<=n; v++)
        if (adj[u][v] && !vis[v]) dfs(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> p[i];
        fill(adj[i]+1, adj[i]+n+1, true);
    }

    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u][v] = adj[v][u] = false;
    }

    dfs(1);

    int ans = 0;
    for (int i=1; i<=n; i++)
        ans += (vis[i] ? p[i] : -p[i]);

    cout << abs(ans) << '\n';
    for (int i=1; i<=n; i++)
        if (vis[i]) cout << i << ' ';
    cout << '\n';

    return 0;
}
