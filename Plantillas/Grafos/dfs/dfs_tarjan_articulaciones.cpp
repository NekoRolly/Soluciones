#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5+4;

int n,m,q;
vector<int> adj[N];
int L[N],low[N],cur;
bool art[N];

// ALGORITMO DE TARJAN PARA HALLAR ARTICULACIONES
void dfs(int u,int p){
    int cnt = 0;
    low[u] = L[u] = ++cur;
    for (int v : adj[u]){
        if (v == p) continue;
        if (L[v] != 0){
            low[u] = min(low[u], L[v]);
            continue;
        }
        dfs(v, u);
        if (low[v] >= L[u]) art[u] = true;
        low[u] = min(low[u], low[v]), cnt++;   
    }
    if (p == -1) art[u] = cnt > 1;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    while (cin >> n && n != 0){
        cur = 0;
        for (int i=1; i<=n; i++){
            adj[i].clear();
            art[i] = false;
            L[i] = 0;
        }

        int u;
        while (cin >> u && u != 0){
            while (getchar() != '\n'){
                int v;
                cin >> v;
                // cout << u << " --- " << v << "\n";
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        dfs(1, -1);

        int ans = 0;
        for (int i=1; i<=n; i++)
            ans += art[i];
        cout << ans << "\n";
    }

    return 0;
}