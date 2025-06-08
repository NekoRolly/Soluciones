#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 2e5 + 4;

void solve(){
    int n;
    cin >> n;
    int a[n+1],nxt[n+1];

    for (int i=1; i<=n; i++)
        cin >> a[i];

    nxt[n] = n+1;
    for (int i=n-1; i>=1; i--){
        nxt[i] = (a[i] == a[i+1] ? nxt[i+1] : i+1);
    }

    int q;
    cin >> q;

    while (q--){
        int l,r;
        cin >> l >> r;

        if (nxt[l] > r)
            cout << "-1 -1\n";
        else
            cout << l << " " << nxt[l] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    cin >> kou;

    while (kou--)
        solve();

    return 0;
}