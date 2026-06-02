/*
Complejidad: O(n*logn)
Memoria: O(n)
Puntaje: 10 + 14 + 15 + 15 + 20 + 26 = 100
Idea: Dsu on trees y combinar paths verticales
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;

int n,P,k;
ll ans;
int a[N],cnt[N];
vector<int> adj[N];
int L[N],sz[N],V[N],cur;
int dis[N];

int dfs_pre(int u,int p,int Dis){
    V[cur] = u, L[u] = cur++;
    sz[u] = 1, dis[u] = Dis;
    for (int v : adj[u]) if (v != p)
        sz[u] += dfs_pre(v, u, Dis + a[v]);
    return sz[u];
}

void query(int lca,int u){
    int val = k - dis[u] + 2*dis[lca] - a[lca];
    if (0 <= val && val <= n) ans += cnt[val];
}

void dfs(int u,int p,bool flag){
    int big = -1;
    for (int v : adj[u])
        if (v != p && (big == 1 || sz[big] < sz[v])) big = v;
    for (int v : adj[u])
        if (v != p && v != big) dfs(v, u, true);
    if (big != -1) dfs(big, u, false);
    query(u, u); cnt[dis[u]]++;
    for (int v : adj[u]){
        if (v == p || v == big) continue;
        for (int i=L[v]; i<L[v]+sz[v]; i++) query(u, V[i]);
        for (int i=L[v]; i<L[v]+sz[v]; i++) cnt[dis[V[i]]]++;
    }
    if (!flag) return;
    for (int i=L[u]; i<L[u]+sz[u]; i++) cnt[dis[V[i]]]--;
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

    dfs_pre(1, -1, a[1]);
    dfs(1, -1, false);

    for (int i=1; i<=n; i++)
        ans += a[i] == k;

    cout << ans << '\n';

    return 0;
}
