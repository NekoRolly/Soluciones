/*
Complejidad: O(n*k)
Memoria: O(n*k)
Puntaje: 9 + 0 + 22 + 0 + 0 = 31
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
int dp1[N][104],dp2[N][104];
int aux[104];

void dfs1(int u,int p){
    fill(dp1[u]+1, dp1[u]+k+1, inf);
    fill(dp2[u], dp2[u]+k+1, inf);
    for (auto [v, wv] : adj[u]){
        if (v == p) continue;
        dfs1(v, u);
        for (int w=wv; w<=k; w++)
            dp1[u][w] = min(dp1[u][w], dp1[v][w-wv] + 1);
    }
}

void prefix(int u,int p){
    for (auto [v, wv] : adj[u]){
        if (v == p) continue;
        for (int w=wv; w<=k; w++)
            dp2[v][w] = min(dp2[v][w], aux[w-wv] + 1);
        for (int w=wv; w<=k; w++)
            aux[w] = min(aux[w], dp1[v][w-wv] + 1);
    }
}

void dfs2(int u,int p){
    for (int w=0; w<=k; w++) aux[w] = dp2[u][w];
    prefix(u, p);
    fill(aux, aux+k+1, inf);
    reverse(adj[u].begin(), adj[u].end());
    prefix(u, p);
    for (auto [v, wv] : adj[u])
        if (v != p) dfs2(v, u);
}

int best_path(int _n, int _k, int H[][2], int L[]){
    n = _n, k = _k;

    for (int i=0; i<n-1; i++){
        int u = H[i][0], v = H[i][1], w = L[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ans = inf;
    dfs1(0, -1);
    dfs2(0, -1);

    ans = inf;
    for (int u=0; u<n; u++)
        ans = min(ans, min(dp1[u][k], dp2[u][k]));

    return (ans == inf ? -1 : ans);
}
