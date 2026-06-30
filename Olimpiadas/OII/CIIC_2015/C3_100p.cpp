// Complejidad  : O((n*q)*logL)
// Memoria      : O(L)
// Puntaje      : 25 + 30 + 45 = 100
// Idea         : Estructuras de Datos
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int inf = 1e9+4;

struct Fenwick_Tree{
    int n;
    ll t[N*10];

    void update(int i,int val){
        for (; i<=n; i+=i&-i) t[i] += val;
    }

    ll prefix(int i){ ll ans = 0;
        for (; i>0; i-=i&-i) ans += t[i];
        return ans;
    }

    ll query(int l,int r){
        return prefix(r) - prefix(l-1);
    }
} fwt1,fwt2;

struct Rango{
    int l,r,c;
};

int n,q;
Rango a[N];
ll total;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int mx = 1000000;
    fwt1.n = fwt2.n = mx;
    for (int i=1; i<=n; i++){
        auto &[l, r, c] = a[i];
        cin >> l >> r >> c;
        total += c;
        fwt1.update(l, c);
        fwt2.update(r, c);
    }

    cin >> q;

    while (q--){
        int t,i,l,r,c; cin >> t;
        if (t == 1){
            cin >> l >> r;
            cout << total - fwt2.prefix(l-1) - fwt1.query(r+1, mx) << '\n';
        }
        else{
            cin >> i >> l >> r >> c;
            fwt1.update(a[i].l, -a[i].c);
            fwt2.update(a[i].r, -a[i].c);
            total += c - a[i].c;
            a[i] = {l, r, c};
            fwt1.update(l, c);
            fwt2.update(r, c);
        }
    }

    return 0;
}
