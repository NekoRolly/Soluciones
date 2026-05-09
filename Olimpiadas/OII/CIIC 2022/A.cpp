#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;

struct Dsu{
    int t[N],sz[N],sum[N];

    void make_set(int i,int val){
        t[i] = i, sz[i] = 1, sum[i] = val;
    }

    int find(int a){
        if (a == t[a]) return a;
        return t[a] = find(t[a]);
    }

    void merge(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        t[a] = b, sz[b] += sz[a], sum[b] += sum[a];
    }
} dsu1, dsu2;

struct Edge{
    int u,v,cu,cv;

    bool operator<(Edge o){
        if (cu == o.cu) return cv < o.cv;
        return cu < o.cu;
    }
};

int n,m;
int c[N];
vector<Edge> edges;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> c[i];
        dsu1.make_set(i, 1);
    }

    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        if (c[u] > c[v]) swap(u, v);
        if (c[u] == c[v]) dsu1.merge(u, v);
        else edges.push_back({u, v, c[u], c[v]});
    }

    sort(edges.begin(), edges.end());

    m = edges.size();
    int ans = 0;
    for (int i=1; i<=n; i++) ans = max(ans, dsu1.sz[i]);

    for (int l=0,r; l<m; l=r){
        for (r=l+1; r < m && edges[r].cu == edges[l].cu && edges[r].cv == edges[l].cv; ) r++;
        for (int i=l; i<r; i++){
            auto &[u, v, cu, cv] = edges[i];
            u = dsu1.find(u), v = dsu1.find(v);
            dsu2.make_set(u, dsu1.sz[u]);
            dsu2.make_set(v, dsu1.sz[v]);
        }
        for (int i=l; i<r; i++){
            auto [u, v, cu, cv] = edges[i];
            dsu2.merge(u, v);
            ans = max(ans, max(dsu2.sum[dsu2.find(u)], dsu2.sum[dsu2.find(v)]));
        }
    }

    cout << ans << '\n';

    return 0;
}
