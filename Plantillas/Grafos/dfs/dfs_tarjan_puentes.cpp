#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 3e5+4;

int n,m,ans;
vector<int> adj[N];
int L[N],low[N],cur;

// ALGORITMO DE TARJAN PARA HALLAR PUENTES
void dfs(int u,int p){
    low[u] = L[u] = ++cur;
    for (int v : adj[u]){
        if (v == p) continue;
        if (L[v] != 0){
            low[u] = min(low[u], L[v]);
            continue;
        }
        dfs(v, u);
        if (low[v] > L[u]) ans++; // u->v es puente
        low[u] = min(low[u], low[v]);   
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

    dfs(1, -1);

    cout << ans << "\n";
    
    return 0;
}