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
    int n = 1e7;
    int lp[n+1] = {0};
    vector<int> pr;

    for (int i=2; i<=n; i++)
        if (lp[i] == 0){
            pr.push_back(i);
            for (int j=i; j<=n; j+=i)
                lp[j] = i;
        }

    int q;
    cin >> q;

    while (q--){
        int x;
        cin >> x;
        int k = 1e4;
        ll ans = 0;
        for (int i=0; i<k; i++)
            ans += x / pr[i];

        if (x >= pr[k]){
            int l = k;
            for (int val=x/pr[k]; val>=1; val--){
                int r = upper_bound(pr.begin(), pr.end(), x/val) - pr.begin();
                ans += 1ll * (r-l) * val;
                l = r;
            }
        }

        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    // cin >> kou;

    while (kou--)
        solve();

    return 0;
}