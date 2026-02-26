#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;

struct DSU{
    int t[N],sz[N],cc;

    void build(int n){
        cc = n;
        for (int i=0; i<n; i++)
            t[i] = i, sz[i] = 1;
    }

    int find(int x){
        if (x == t[x]) return x;
        return t[x] = find(t[x]);
    }

    bool same(int a,int b){
        return find(a) == find(b);
    }

    int get_size(int x){
        return sz[find(x)];
    }

    void merge(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        t[b] = a, sz[b] += sz[a], cc--;
    }
} dsu;

int n,q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    dsu.build(n);
    while (q--){
        int t,a,b;
        cin >> t >> a >> b;

        if (t == 0) dsu.merge(a, b);
        else cout << dsu.same(a, b) << "\n";
    }

    return 0;
}