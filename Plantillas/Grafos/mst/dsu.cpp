#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    vector<int> up,sz;
    int comp,mx_comp;

    void build(int n){
        up.resize(n+1);
        sz.assign(n+1, 1);
        comp = n, mx_comp = 1;
        for (int i=1; i<=n; i++)
            up[i] = i;
    }

    int find(int x){ // O(1) amortizado
        if (up[x] == x) return x;
        return up[x] = find(up[x]);
    }

    void join(int a,int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        up[a] = b;
        sz[b] += sz[a];
        comp--;
        mx_comp = max(mx_comp, sz[b]);
    }
} dsu;

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    dsu.build(n);

    while (m--){
        int a,b;
        cin >> a >> b;
        dsu.join(a, b);
        cout << dsu.comp << " " << dsu.mx_comp << "\n";
    }

    return 0;
}