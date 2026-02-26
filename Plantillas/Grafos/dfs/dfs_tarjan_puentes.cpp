#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+4;

int n,m;
vector<pii> adj[N]; // {v, id}
// Se guarda ID cuando es multigrafo
int L[N],low[N],cur;
int col[N];
vector<int> comp[N];

// DFS para hallar L[] y low[]
void dfs1(int u,int p_id){
    low[u] = L[u] = ++cur;
    for (auto [v, id] : adj[u]){
        if (id != p_id && L[v] != 0)
            low[u] = min(low[u], L[v]);
        if (L[v] != 0) continue;
        dfs1(v, id);
        low[u] = min(low[u], low[v]);
    }
}

// DFS para asignar las componentes con col[]
void dfs2(int u,int id){
    col[u] = id;
    for (auto [v, _] : adj[u]){
        if (col[v] != 0) continue;
        if (L[u] < low[v]) dfs2(v, ++cur); // u --- v es puente
        else dfs2(v, id);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i=0; i<n; i++)
        if (L[i] == 0) dfs1(i, -1);

    cur = 0;
    for (int i=0; i<n; i++)
        if (col[i] == 0) dfs2(i, ++cur);

    for (int i=0; i<n; i++)
        comp[col[i]].push_back(i);

    cout << cur << "\n";
    for (int i=1; i<=cur; i++){
        cout << comp[i].size() << " ";
        for (int x : comp[i]) cout << x << " ";
        cout << "\n";
    }

    return 0;
}