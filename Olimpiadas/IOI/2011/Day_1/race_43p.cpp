#include "race.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int inf = 1e9+4;

int n,k,ans;
vector<pii> adj[N];
int dp[N][104];

void dfs(int u,int p){
    fill(dp[u], dp[u]+k+1, inf);
    dp[u][0] = 0;
    for (auto [v, w] : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        //cerr << u << " -> " << v << '\n';
        for (int we=0; we+w<=k; we++){
            ans = min(ans, dp[v][we] + dp[u][k-w-we] + 1);
            //cerr << ans << " <- " << dp[v][we] + dp[u][k-w-we] + 1 << '\n';
        }
        for (int we=0; we+w<=k; we++)
            dp[u][w+we] = min(dp[u][w+we], dp[v][we] + 1);
    }
}

int best_path(int _n, int _k, int H[][2], int L[]){
    n = _n, k = _k;

    for (int i=0; i<n-1; i++){
        int u = H[i][0], v = H[i][1], w = L[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ans = inf;
    dfs(0, -1);
    return (ans == inf ? -1 : ans);
}
