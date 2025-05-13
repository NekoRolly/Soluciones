#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 2e5 + 4;

int n,W;
ll dp[104][100004];
int v[104], w[104];

ll Dp(int pos,int x){
    if (pos == n) return 0;
    if (dp[pos][x] != -1) return dp[pos][x];

    ll ans = Dp(pos + 1, x);
    if (x >= w[pos]) ans = max(ans, Dp(pos + 1, x - w[pos]) + v[pos]);

    return dp[pos][x] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));

    cin >> n >> W;

    for (int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }

    cout << Dp(0, W) << endl;
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