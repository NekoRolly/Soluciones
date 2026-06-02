/*
Complejidad: O(n*k)
Memoria: O(n*k)
Puntaje: 0 + 0 + 15 + 15 + 0 + 0 = 30
Idea: DP on trees con rerooting
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;

int n,P,k;
ll ans;
int a[N];
int dp1[N][14],dp2[N][14];
vector<int> adj[N];

void dfs1(int u,int p){
    dp1[u][a[u]] = 1;
    for (int v : adj[u]) if (v != p){
        dfs1(v, u);
        for (int i=0; i+a[u]<=k; i++)
            dp1[u][i+a[u]] += dp1[v][i];
    }
}

void dfs2(int u,int p){
    for (int v : adj[u]) if (v != p){
        for (int i=a[v]; i<=k; i++){
            dp2[v][i] = dp1[u][i-a[v]] + dp2[u][i-a[v]];
            if (i-a[v]-a[u] < 0) continue;
            dp2[v][i] -= dp1[v][i-a[v]-a[u]];
        }
        dfs2(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> P >> k; k--;

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a[i] = x < P;
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    for (int i=1; i<=n; i++)
        ans += dp1[i][k] + dp2[i][k] + (a[i] == k);

    cout << ans/2 << '\n';

    return 0;
}
