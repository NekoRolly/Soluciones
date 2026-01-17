#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

int n,m;
vector<int> adj[N];
int vis[N];
bool bip;

// DFS PARA VERIFICAR SI EL GRAFO ES BIPARTITO
void dfs(int u,int color){
    vis[u] = color;
    for (int v : adj[u]){
        if (vis[v] == 0)
            dfs(v, 3-color);
        else if (vis[v] == vis[u])
            bip = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bip = true;
    for (int i=1; i<=n; i++)
        if (vis[i] == 0)
            dfs(i, 1);

    if (!bip)
        cout << "IMPOSSIBLE\n";
    else{
        for (int i=1; i<=n; i++)
            cout << vis[i] << " ";
        cout << "\n";
    }

    return 0;
}