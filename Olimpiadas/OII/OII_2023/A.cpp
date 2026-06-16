#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;

struct Dsu{
    int n,t[N],sz[N];
    pii mx[N];

    void build(int m,int val[]){
        n = m;
        for (int i=1; i<=n; i++)
            t[i] = i, sz[i] = 1, mx[i] = {val[i], i};
    }

    int find(int x){
        if (x == t[x]) return x;
        return t[x] = find(t[x]);
    }

    pii merge(int a,int b){
        a = find(a), b = find(b);
        assert(a != b);
        if (sz[a] > sz[b]) swap(a, b);
        t[a] = b, sz[b] += sz[a];
        if (mx[a] > mx[b]) swap(mx[a], mx[b]);
        return {mx[b].second, mx[a].second};
    }
} dsu;

int n;
vector<int> adj[N],_adj[N];
int val[N];
ll ans[N];
bool flag[N];
vector<pii> vec;

ll dfs1(int u){
    ans[u] = val[u];
    for (int v : _adj[u])
        ans[u] += dfs1(v);
    return ans[u];
}

void dfs2(int u){
    for (int v : _adj[u]){
        if (ans[v] > val[u]) ans[v] = ans[u];
        dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        cin >> val[i];
        vec.push_back({val[i], i});
    }

    for (int u=1; u<=n; u++){
        flag[u] = true;
        for (int v : adj[u])
            if (val[u] > val[v])
                flag[u] = false;
    }

    dsu.build(n, val);
    sort(vec.begin(), vec.end());

    for (auto [_val, u] : vec)
        for (int v : adj[u])
            if (make_pair(val[v], v) < make_pair(val[u], u)){
                auto [pa, hi] = dsu.merge(u, v);
                _adj[pa].push_back(hi);
            }

    int rt = dsu.mx[dsu.find(1)].second;
    dfs1(rt); dfs2(rt);

    for (int i=1; i<=n; i++)
        cout << (flag[i] ? val[i] : ans[i]) << ' ';
    cout << '\n';

    return 0;
}
