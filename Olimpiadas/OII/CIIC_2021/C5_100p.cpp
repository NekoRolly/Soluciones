/*
Complejidad: O((n+q)*logn)
Memoria: O(n*logn)
Puntaje: 5 + 11 + 17 + 28 + 39 = 100
Idea: DP on trees con rerooting y binary lifting para cada consulta
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+4;
const int inf = 1e9+4;

struct MaxK{
    vector<int> vec;

    void build(int n){
        vec.assign(n, 0);
    }

    void insert(int x){
        for (int &y : vec)
            if (x > y) swap(x, y);
    }
} mx3,mx2;

int n,q;
vector<pii> adj[N];
int dp1[N],dp2[N]; // subtree
int _dp1[N],_dp2[N]; // supertree

void dfs1(int u,int p){
    dp1[u] = dp2[u] = 0;
    for (auto [v, wv] : adj[u]) if (v != p){
        dfs1(v, u);
        dp2[u] = max(max(dp2[u], dp2[v]), dp1[u] + dp1[v] + wv);
        dp1[u] = max(dp1[u], dp1[v] + wv);
    }
}

void dfs2(int u,int p){
    mx3.build(3), mx2.build(2);
    mx3.insert(_dp1[u]), mx2.insert(_dp2[u]);
    for (auto [v, wv] : adj[u]) if (v != p)
        mx3.insert(dp1[v] + wv), mx2.insert(dp2[v]);
    for (auto [v, wv] : adj[u]) if (v != p){
        if (mx3.vec[0] == dp1[v] + wv) _dp1[v] = mx3.vec[1] + wv;
        else _dp1[v] = mx3.vec[0] + wv;

        if (mx3.vec[0] == dp1[v] + wv) _dp2[v] = mx3.vec[1] + mx3.vec[2];
        else if (mx3.vec[1] == dp1[v] + wv) _dp2[v] = mx3.vec[0] + mx3.vec[2];
        else _dp2[v] = mx3.vec[0] + mx3.vec[1];

        if (mx2.vec[0] == dp2[v]) _dp2[v] = max(_dp2[v], mx2.vec[1]);
        else _dp2[v] = max(_dp2[v], mx2.vec[0]);
    }
    for (auto [v, wv] : adj[u]) if (v != p) dfs2(v, u);
}

int pa[N][19],mn[N][19];
int L[N],R[N],cur,h[N];

void dfs3(int u,int p,int H){
    pa[u][0] = p, L[u] = cur++, h[u] = H;
    mn[u][0] = abs(dp2[u] - _dp2[p]);
    for (int i=1; i<19; i++){
        pa[u][i] = pa[pa[u][i-1]][i-1];
        mn[u][i] = min(mn[u][i-1], mn[pa[u][i-1]][i-1]);
    }
    for (auto [v, wv] : adj[u]) if (v != p) dfs3(v, u, H+1);
    R[u] = cur;
}

bool isa(int a,int b){
    return L[a] <= L[b] && R[b] <= R[a];
}

int lca(int a,int b){
    if (isa(a, b)) return a;
    for (int i=18; i>=0; i--)
        if (!isa(pa[a][i], b))
            a = pa[a][i];
    return pa[a][0];
}

int get_min(int u,int k){
    int ans = inf;
    for (int i=0; i<19; i++) if (k>>i&1)
        ans = min(ans, mn[u][i]), u = pa[u][i];
    return ans;
}

int get_kth(int u,int k){
    for (int i=0; i<19; i++)
        if (k>>i&1) u = pa[u][i];
    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs1(1, 1), dfs2(1, 1), dfs3(1, 1, 0);

    cin >> q;

    while (q--){
        int u,v; cin >> u >> v;
        int l = lca(u, v), ans = inf;
        int du = h[u] - h[l], dv = h[v] - h[l];
        if (du + dv <= 1){ cout << "-1\n"; continue;}
        if (du > 0 && dv > 0)
            ans = abs(dp2[get_kth(u, du-1)] - dp2[get_kth(v, dv-1)]);
        if (du >= 2) ans = min(ans, get_min(u, du-1));
        if (dv >= 2) ans = min(ans, get_min(v, dv-1));
        cout << ans << '\n';
    }

    return 0;
}
