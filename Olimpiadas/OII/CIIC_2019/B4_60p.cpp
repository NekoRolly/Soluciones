/*
Complejidad: O(n^2 + sqrt(m) * 50000 / 64)
Memoria: O(n^2 + sqrt(m) * 50000 / 64)
Puntaje: 10 + 16 + 6 + 28 + 0 = 60
Idea: DFS + DP knapsack con bitset
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;
const int N = 1004;

int n,m;
int p[N],sum;
bitset<50001> dp[N];
bool adj[N][N],used[N];
int id[N],comp[N];

void dfs(int u,int Id){
    id[u] = Id, comp[Id] += p[u];
    for (int v=1; v<=n; v++)
        if (id[v] == 0 && adj[u][v]) dfs(v, Id);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> p[i];
        sum += p[i];
        fill(adj[i]+1, adj[i]+n+1, true);
    }

    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u][v] = adj[v][u] = false;
    }

    int cur = 0;
    for (int u=1; u<=n; u++)
        if (id[u] == 0) dfs(u, ++cur);

    dp[0][0] = 1;

    for (int i=1; i<=cur; i++)
        dp[i] = dp[i-1] | (dp[i-1] << comp[i]);

    int mx = 0;
    for (int i=0; i<=sum/2; i++)
        if (dp[cur][i]) mx = i;

    cout << sum - 2*mx << '\n';

    for (int i=cur; i>=1; i--){
        if (dp[i-1][mx]) continue;
        used[i] = true;
        mx -= comp[i];
    }

    for (int i=1; i<=n; i++)
        if (used[id[i]]) cout << i << ' ';
    cout << '\n';

    return 0;
}
