#include "race.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int inf = 1e9+4;

int n,k,ans;
vector<pii> adj[N];

void dfs(int u,int p,ll acum,int len){
    if (acum == k) ans = min(ans, len);
    for (auto [v, w] : adj[u])
        if (v != p) dfs(v, u, acum + w, len + 1);
}

int best_path(int _n, int _k, int H[][2], int L[]){
    n = _n, k = _k;

    for (int i=0; i<n-1; i++){
        int u = H[i][0], v = H[i][1], w = L[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ans = inf;
    for (int u=0; u<n; u++) dfs(u, -1, 0, 0);
    return (ans == inf ? -1 : ans);
}
