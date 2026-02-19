#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    vector<int> sz,up;

    void build(int n){
        sz.assign(n+1, 1);
        up.resize(n+1);
        for (int i=1; i<=n; i++)
            up[i] = i;
    }

    int find(int x){
        if (x == up[x]) return x;
        return up[x] = find(up[x]);
    }

    void join(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        up[a] = b;
        sz[b] += sz[a];
    }
} dsu;

struct Edge{
    int u,v,w;

    // bool operator<(Edge x){
    //     return w < x.w;
    // }
};

bool operator<(Edge a,Edge b){
    return a.w < b.w;
}

// bool cmp(Edge a,Edge b){
//     return a.w < b.w;
// }

int n,m,cnt;
vector<Edge> ed;
ll ans;

void kruskal(){
    sort(ed.begin(), ed.end());
    // sort(ed.begin(), ed.end(), cmp);
    dsu.build(n);
    
    ans = cnt = 0;
    for (auto &[u, v, w] : ed){
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.join(u, v);
        ans += w;
        cnt++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    ed.resize(m);
    for (auto &[u, v, w] : ed)
        cin >> u >> v >> w;

    kruskal();

    if (cnt == n-1) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}