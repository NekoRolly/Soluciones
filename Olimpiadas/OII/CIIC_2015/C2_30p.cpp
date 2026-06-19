/*
Complejidad: O((n+q)logL)
Memoria: O(L)
Puntaje: 0 + 30 + 0 = 30
Idea: Update en rango y query en punto
Nota: L <= 1000000 y caso de consulta en punto A = B
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int inf = 1e9+4;

struct Segment_Tree{
    int n; ll t[N*20];

    void update(int l,int r,int val){
        for (l+=n, r+=n; l<r; l>>=1, r>>=1){
            if (l&1) t[l++] += val;
            if (r&1) t[--r] += val;
        }
    }

    ll query(int i){
        ll ans = t[i+=n];
        while (i>>=1) ans += t[i];
        return ans;
    }
} sgt;

struct Rango{
    int l,r,c;
};

int n,q;
Rango a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; sgt.n = 1000001;

    for (int i=1; i<=n; i++){
        auto &[l, r, c] = a[i];
        cin >> l >> r >> c;
        sgt.update(l, r+1, c);
    }

    cin >> q;

    while (q--){
        int t,i,l,r,c; cin >> t;
        if (t == 1){
            cin >> l >> r;
            cout << sgt.query(l) << '\n';
        }
        else{
            cin >> i >> l >> r >> c;
            sgt.update(a[i].l, a[i].r+1, -a[i].c);
            a[i] = {l, r, c};
            sgt.update(l, r+1, c);
        }
    }

    return 0;
}
