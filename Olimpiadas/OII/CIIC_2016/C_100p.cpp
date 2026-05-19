#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;
const int mod = 1e9+7;

int S(int a,int b){ return (a+b)%mod;}
int P(int a,int b){ return 1ll*a*b%mod;}

struct Edge{
    int u,v,w;

    bool operator<(Edge o){
        return w < o.w;
    }
};

struct Dsu{
    int t[N],sz[N];

    void make_set(int i){
        t[i] = i, sz[i] = 1;
    }

    int find(int x){
        if (x == t[x]) return x;
        return t[x] = find(t[x]);
    }

    void merge(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        t[a] = b, sz[b] += sz[a];
    }
} dsu;

int n,ans;
Edge ed[N];

/*
Complejidad: O(n*logn)
Memoria: O(n)
Puntaje: 20 + 20 + 60 = 100
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<n; i++){
        auto &[u, v, w] = ed[i];
        cin >> u >> v >> w;
    }

    sort(ed+1, ed+n);
    for (int i=1; i<=n; i++)
        dsu.make_set(i);

    for (int i=1; i<n; i++){
        auto [u, v, w] = ed[i];
        ans = S(ans, P(w, P(dsu.sz[dsu.find(u)], dsu.sz[dsu.find(v)])));
        dsu.merge(u, v);
    }
    cout << ans << '\n';

    return 0;
}
