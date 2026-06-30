// Complejidad  : O(n*q)
// Memoria      : O(n)
// Puntaje      : 25 + 0 + 0 = 25
// Idea         : Fuerza Bruta
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int inf = 1e9+4;

struct Rango{
    int l,r,c;
};

int n,q;
Rango a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<=n; i++){
        auto &[l, r, c] = a[i];
        cin >> l >> r >> c;
    }

    cin >> q;

    while (q--){
        int t,i,l,r,c; cin >> t;
        if (t == 1){
            cin >> l >> r;
            ll ans = 0;
            for (int i=1; i<=n; i++){
                if (a[i].r < l || r < a[i].l) continue;
                ans += a[i].c;
            }
            cout << ans << '\n';
        }
        else{
            cin >> i >> l >> r >> c;
            a[i] = {l, r, c};
        }
    }

    return 0;
}
