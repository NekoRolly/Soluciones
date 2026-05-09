#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+4;

int n,q;
ll a[6];

int prefix(int x){
    return x < 0 ? -1 : x/6;
}

void update(int l,int r,ll x){
    for (int i=0; i<6; i++){
        a[i] += x*(prefix(r-i) - prefix(l-1-i));
        // cerr << i << " : " << x << " " << prefix(r-i) << "-" << prefix(l-1-i) << '\n';
    }
}

void query(){
    ll A = a[0] - a[2] - a[3] + a[5];
    ll B = a[1] + a[2] - a[4] - a[5];
    // cerr << A << " ---- " << B << '\n';
    cout << (A == 0 && B == 0 ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i=0; i<n; i++){
        int x; cin >> x; a[i%6] += x;
    }
    for (int i=0; i<n; i++){
        int x; cin >> x; a[i%6] -= x;
    }

    query();
    while (q--){
        int l,r,x; cin >> l >> r >> x;
        update(l-1, r-1, x);
        query();
    }

    return 0;
}
