/*
Complejidad: O(n*k)
Memoria: O(n*k)
Puntaje: 0 + 0 + 15 + 15 + 0 + 0 = 30
Idea: DP on trees y combinar paths verticales
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;

int n,P,k;
ll ans;
int a[N];
int dp[N][14];
vector<int> adj[N];

void dfs(int u,int p){
    dp[u][a[u]] = 1;
    for (int v : adj[u]) if (v != p){
        dfs(v, u);
        for (int i=0; i<=k; i++)
            ans += 1ll * dp[v][i] * dp[u][k-i];
        for (int i=0; i+a[u]<=k; i++)
            dp[u][i+a[u]] += dp[v][i];
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

    dfs(1, -1);

    for (int i=1; i<=n; i++)
        ans += a[i] == k;

    cout << ans << '\n';

    return 0;
}
