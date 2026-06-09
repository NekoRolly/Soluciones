/*
Complejidad: O(n + m + sqrt(m) * 50000 / 64)
Memoria: O(n + m + sqrt(m) * 50000 / 64)
Puntaje: 10 + 16 + 6 + 28 + 40 = 100
Idea: DSU + Optimización + DP knapsack con bitset
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;
const int N = 65004;
const int N2 = 1004;
const int M = 350004;

struct Dsu{
    int t[N],sz[N],val[N];

    void make(int x,int Val){
        t[x] = x, sz[x] = 1, val[x] = Val;
    }

    int find(int x){
        if (x == t[x]) return x;
        return t[x] = find(t[x]);
    }

    bool merge(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        t[a] = b, sz[b] += sz[a], val[b] += val[a];
        return true;
    }
} dsu;

int n,m;
int p[N],sum;
bitset<50001> dp[N2];
vector<int> adj[N],vec;
bool used[N],vis[N],_adj[N2][N2];
int pos[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> p[i];
        sum += p[i];
        dsu.make(i, p[i]);
    }

    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int aux = 1;
    for (int i=2; i<=n; i++)
        if (adj[i].size() < adj[aux].size()) aux = i;

    for (int v : adj[aux]) vis[v] = true;
    for (int i=1; i<=n; i++) if (!vis[i])
        dsu.merge(aux, i);

    vec = {dsu.find(aux)};
    for (int v : adj[aux]) vec.push_back(v);

    int sz = vec.size();
    for (int i=0; i<sz; i++) pos[vec[i]] = i;

    for (int i=0; i<sz; i++){
        fill(_adj[i], _adj[i]+sz, true);
        for (int v : adj[vec[i]]) _adj[i][pos[dsu.find(v)]] = false;
    }

    for (int i=0; i<sz; i++)
        for (int j=0; j<sz; j++) if (_adj[i][j])
            dsu.merge(vec[i], vec[j]);

    vec.clear();
    for (int i=1; i<=n; i++) if (dsu.find(i) == i)
        vec.push_back(i);
    sz = vec.size();

    dp[0][0] = 1;

    for (int i=1; i<=sz; i++)
        dp[i] = dp[i-1] | (dp[i-1] << dsu.val[vec[i-1]]);

    int mx = 0;
    for (int i=0; i<=sum/2; i++)
        if (dp[sz][i]) mx = i;

    cout << sum - 2*mx << '\n';

    for (int i=sz; i>=1; i--){
        if (dp[i-1][mx]) continue;
        used[vec[i-1]] = true;
        mx -= dsu.val[vec[i-1]];
    }

    for (int i=1; i<=n; i++)
        if (used[dsu.find(i)]) cout << i << ' ';
    cout << '\n';

    return 0;
}
