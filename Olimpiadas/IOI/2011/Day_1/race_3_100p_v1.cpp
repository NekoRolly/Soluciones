/*
Complejidad: O(nlogn^2)
Memoria: O(n)
Puntaje: 9 + 12 + 22 + 57 = 100
Idea: Dsu on Trees y combinar paths verticales
*/
#include "race.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int inf = 1e9+4;

int n,k,ans;
vector<pii> adj[N];
map<ll,int> mp;
int sz[N],L[N],V[N],cur;
int h[N];
ll dis[N];

int dfs_pre(int u,int p,int H,ll Dis){
    sz[u] = 1, h[u] = H, dis[u] = Dis;
    L[u] = cur++, V[L[u]] = u;
    for (auto [v, w] : adj[u]) if (v != p)
        sz[u] += dfs_pre(v, u, H+1, Dis + w);
    return sz[u];
}

void query(int lca,int u){
    ll aux = k+2*dis[lca]-dis[u];
    if (mp.find(aux) == mp.end()) return;
    ans = min(ans, mp[aux] + h[u] - 2*h[lca]);
}

void insert(int u){
    if (mp.find(dis[u]) == mp.end()) mp[dis[u]] = h[u];
    else mp[dis[u]] = min(mp[dis[u]], h[u]);
}

void dfs(int u,int p,bool flag){
    int big = -1;
    for (auto [v, w] : adj[u])
        if (v != p && (big == -1 || sz[big] < sz[v])) big = v;
    for (auto [v, w] : adj[u])
        if (v != p && v != big) dfs(v, u, true);
    if (big != -1) dfs(big, u, false);
    query(u, u); insert(u);
    for (auto [v, w] : adj[u]){
        if (v == p || v == big) continue;
        for (int i=L[v]; i<L[v]+sz[v]; i++)
            query(u, V[i]);
        for (int i=L[v]; i<L[v]+sz[v]; i++)
            insert(V[i]);
    }
    if (flag) mp.clear();
}

int best_path(int _n, int _k, int H[][2], int L[]){
    n = _n, k = _k;

    for (int i=0; i<n-1; i++){
        int u = H[i][0], v = H[i][1], w = L[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ans = inf;
    dfs_pre(0, -1, 0, 0);
    dfs(0, -1, false);
    return (ans == inf ? -1 : ans);
}
